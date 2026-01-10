/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shapes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:36:36 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/24 18:26:58 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape.h"
#include "libft.h"

int	intersect(t_shape *shape, t_ray *ray_r, t_intersections *result_r)
{
	int	status;

	status = 0;
	if (!shape || !ray_r)
		return (ft_indicate_err("Error\nnull shape or ray in intersect\n",
				-1));
	if (shape->ops.intersect)
		status = shape->ops.intersect(shape, ray_r, result_r);
	return (status);
}

static t_ray	get_transformed_ray(t_shape *shape, t_ray *ray_r)
{
	t_ray		transformed_ray;
	t_matrix4	trans_inv;

	if (shape->inv_computed)
		transformed_ray = transform((*ray_r), shape->transform_inv);
	else
	{
		trans_inv = init_mat4();
		inverse_mat(&shape->transform, &(trans_inv));
		transformed_ray = transform((*ray_r), trans_inv);
	}
	return (transformed_ray);
}

static int	handle_sphere_intersections(t_shape *shape, float t1, float t2,
		t_intersections *result_r)
{
	result_r->count = 2;
	result_r->xs = init_xs(2);
	if (!result_r->xs)
		return (ft_indicate_err("Error\nfailed to allocate intersections\n",
				-1));
	result_r->xs[0] = intersection(t1, shape);
	result_r->xs[1] = intersection(t2, shape);
	return (0);
}

int	intersect_sphere(t_shape *shape, t_ray *ray_r, t_intersections *result_r)
{
	t_sphere	*sphere;
	t_ray		transformed_ray;
	float		discriminant;
	float		t1;
	float		t2;

	t1 = 0;
	t2 = 0;
	sphere = (t_sphere *)shape->data;
	transformed_ray = get_transformed_ray(shape, ray_r);
	discriminant = sphere_calculate_discriminant(sphere, transformed_ray);
	if (discriminant < 0)
		result_r->count = 0;
	else
	{
		calculate_t_values(transformed_ray, discriminant, &t1, &t2);
		return (handle_sphere_intersections(shape, t1, t2, result_r));
	}
	return (0);
}

int	intersect_plane(t_shape *shape, t_ray *ray_r, t_intersections *result_r)
{
	float	t;
	t_ray	transformed_ray;

	transformed_ray = get_transformed_ray(shape, ray_r);
	t = calculate_plane_t(shape, transformed_ray, result_r);
	if (t < EPSILON)
		result_r->count = 0;
	else
	{
		result_r->count = 1;
		result_r->xs = init_xs(1);
		if (!result_r->xs)
			return (ft_indicate_err("Error\nfailed to allocate\n", -1));
		result_r->xs[0] = intersection(t, shape);
	}
	return (0);
}
