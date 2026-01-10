/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:41:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 16:43:56 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"

static float	check_cap(t_ray ray, float t)
{
	float	result;
	float	x;
	float	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	result = powf(x, 2) + powf(z, 2);
	return (result);
}

void	intersect_cone_caps(t_shape *shape, t_ray ray,
	t_intersections *txs_r, int *count)
{
	float		t;
	t_cylinder	*cone;
	float		radius_at_y;
	float		distance_from_axis;

	cone = (t_cylinder *)shape->data;
	if (cone->closed == 0 || fabsf(ray.direction.y) < EPSILON)
		return ;
	t = (cone->minimum - ray.origin.y) / ray.direction.y;
	distance_from_axis = check_cap(ray, t);
	radius_at_y = fabsf(cone->minimum);
	if (distance_from_axis <= powf(radius_at_y, 2))
	{
		txs_r->xs[*count] = intersection(t, shape);
		(*count)++;
	}
	t = (cone->maximum - ray.origin.y) / ray.direction.y;
	distance_from_axis = check_cap(ray, t);
	radius_at_y = fabsf(cone->maximum);
	if (distance_from_axis <= powf(radius_at_y, 2))
	{
		txs_r->xs[*count] = intersection(t, shape);
		(*count)++;
	}
	return ;
}

float	cone_calculate_discriminant(t_cylinder *cone, t_ray ray)
{
	float	discr;

	cone->a = powf(ray.direction.x, 2)
		- powf(ray.direction.y, 2)
		+ powf(ray.direction.z, 2);
	cone->b = 2 * (ray.origin.x * ray.direction.x
			- ray.origin.y * ray.direction.y
			+ ray.origin.z * ray.direction.z);
	cone->c = powf(ray.origin.x, 2)
		- powf(ray.origin.y, 2)
		+ powf(ray.origin.z, 2);
	discr = powf(cone->b, 2) - (4 * cone->a * cone->c);
	return (discr);
}

int	calculate_parallel_t(t_shape *shape, t_intersections *result_r, t_ray ray)
{
	float		t;
	float		y;
	t_cylinder	*cone;
	int			count;

	count = 0;
	cone = (t_cylinder *)shape->data;
	if (fabsf(cone->b) < EPSILON)
		return (0);
	t = -cone->c / (2 * cone->b);
	y = ray.origin.y + t * ray.direction.y;
	if (cone->minimum < y && y < cone->maximum)
		result_r->xs[count++] = intersection(t, shape);
	return (count);
}

int	calculate_cone_t(float discr,
	t_shape *shape, t_intersections *result_r, t_ray ray)
{
	float			t[2];
	float			y[2];
	int				i;
	int				count;
	t_cylinder		*cone;

	i = 0;
	count = 0;
	cone = shape->data;
	t[0] = (-cone->b - sqrt(fabsf(discr))) / (2 * cone->a);
	t[1] = (-cone->b + sqrt(fabsf(discr))) / (2 * cone->a);
	swap(&t[0], &t[1]);
	while (i < 2)
	{
		y[i] = ray.origin.y + t[i] * ray.direction.y;
		if (cone->minimum < y[i] && y[i] < cone->maximum)
			result_r->xs[count++] = intersection(t[i], shape);
		i++;
	}
	return (count);
}
