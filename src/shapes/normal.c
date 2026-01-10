/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:30:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/10 09:15:40 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_tuple	normal_at(t_shape *shape, t_tuple world_point)
// {
// 	t_tuple		object_point;
// 	t_tuple		object_normal;
// 	t_tuple		world_normal;

// 	object_point = mat4_multi_tuple(shape->transform_inv, world_point);
// 	object_normal = vector(0, 0, 0);
// 	if (shape->ops.normal)
// 		object_normal = shape->ops.normal(shape, object_point);
// 	world_normal = mat4_multi_tuple(shape->transpose_inv, object_normal);
// 	world_normal.w = 0;
// 	return (tuple_norm(&world_normal));
// }

t_tuple	normal_at(t_shape *shape, t_tuple world_point)
{
	t_matrix4	inverse_transform;
	t_tuple		object_point;
	t_tuple		object_normal;
	t_matrix4	transpose_inverse;
	t_tuple		world_normal;

	inverse_transform = init_mat4();
	inverse_mat(&(shape->transform), &(inverse_transform));
	object_point = mat4_multi_tuple(inverse_transform, world_point);
	object_normal = vector(0, 0, 0);
	if (shape->ops.normal)
		object_normal = shape->ops.normal(shape, object_point);
	transpose_inverse = matrix4_transpose(inverse_transform);
	world_normal = mat4_multi_tuple(transpose_inverse, object_normal);
	world_normal.w = 0;
	return (tuple_norm(&world_normal));
}

t_tuple	sphere_normal(t_shape *shape, t_tuple object_point)
{
	t_tuple		origin_point;
	t_tuple		object_normal;

	(void)shape;
	origin_point = point(0, 0, 0);
	object_normal = tuple_sub(&object_point, &origin_point);
	return (object_normal);
}

t_tuple	plane_normal(t_shape *shape, t_tuple object_point)
{
	t_tuple		object_normalv;
	t_plane		*plane;

	(void)object_point;
	plane = (t_plane *)shape->data;
	object_normalv = plane->normalv;
	return (object_normalv);
}

t_tuple	cylinder_normal(t_shape *shape, t_tuple object_point)
{
	t_tuple		object_normalv;
	t_cylinder	*cyl;
	float		dist;

	cyl = shape->data;
	dist = powf(object_point.x, 2) + powf(object_point.z, 2);
	if (dist < 1 && object_point.y >= cyl->maximum - EPSILON)
		object_normalv = vector(0, 1, 0);
	else if (dist < 1 && object_point.y <= cyl->minimum + EPSILON)
		object_normalv = vector(0, -1, 0);
	else
		object_normalv = vector(object_point.x, 0, object_point.z);
	return (object_normalv);
}

t_tuple	hyperboloid_normal(t_shape *shape, t_tuple object_point)
{
	t_tuple			object_normalv;
	t_hyperboloid	*hyp;

	(void)shape;
	hyp = (t_hyperboloid *)shape->data;
	(void)hyp;
	object_normalv = vector(object_point.x, -object_point.y, object_point.z);
	return (object_normalv);
}
