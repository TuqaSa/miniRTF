/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/22 09:47:17 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "libft.h"

t_shape	*init_plane(void)
{
	t_shape	*shape;
	t_plane	*plane_data;

	shape = init_shape();
	if (!shape)
		return (NULL);
	plane_data = ft_calloc(1, sizeof(t_plane));
	if (!plane_data)
		return (NULL);
	plane_data->normalv = vector(0, 1.0, 0);
	plane_data->point_coord = point(0, 0, 0);
	shape->ops.info = plane_info;
	shape->ops.normal = plane_normal;
	shape->ops.intersect = intersect_plane;
	shape->data = plane_data;
	return (shape);
}

int	add_plane(t_shape **root_r)
{
	t_shape	*new;
	t_shape	*curr;

	if (!root_r)
		return (-1);
	new = init_plane();
	if (!new)
		return (-1);
	if ((*root_r) == NULL)
	{
		(*root_r) = new;
		return (0);
	}
	curr = (*root_r);
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (0);
}

float	calculate_plane_t(t_shape *shape, t_ray ray, t_intersections *result_r)
{
	float			t;
	t_tuple			ray_to_planev;
	float			dot_nd;
	float			numerator;
	t_plane			*plane_data;

	plane_data = (t_plane *)shape->data;
	dot_nd = tuple_dot_product(&plane_data->normalv, &ray.direction);
	if (fabsf(dot_nd) < EPSILON)
	{
		result_r->count = 0;
		return (0);
	}
	ray_to_planev = tuple_sub(&ray.origin, &plane_data->point_coord);
	numerator = tuple_dot_product(&plane_data->normalv, &ray_to_planev);
	t = -numerator / dot_nd;
	return (t);
}
