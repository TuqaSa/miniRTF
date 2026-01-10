/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_cone.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:00:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/05 00:00:00 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape.h"
#include "libft.h"

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

int	intersect_cylinder(t_shape *shape, t_ray *ray_r, t_intersections *result_r)
{
	int			count;
	t_cylinder	*cyl;
	t_ray		transformed_ray;
	float		discriminant;

	count = 0;
	cyl = (t_cylinder *)shape->data;
	transformed_ray = get_transformed_ray(shape, ray_r);
	discriminant = cylinder_calculate_discriminant(cyl, transformed_ray);
	if (discriminant < 0)
		result_r->count = 0;
	else
	{
		count = calculate_cylinderbdy_t(discriminant, shape, result_r,
				transformed_ray);
		if (count < 0)
			return (-1);
	}
	intersect_cylinder_caps(shape, transformed_ray, result_r, &count);
	result_r->count = count;
	return (0);
}

int	intersect_cone(t_shape *shape, t_ray *ray_r, t_intersections *result_r)
{
	int			count;
	t_cylinder	*cone;
	t_ray		tray;
	float		discr;

	count = 0;
	cone = (t_cylinder *)shape->data;
	tray = get_transformed_ray(shape, ray_r);
	discr = cone_calculate_discriminant(cone, tray);
	result_r->xs = init_xs(4);
	if (!result_r->xs)
	{
		result_r->count = 0;
		return (ft_indicate_err("Error\nfailed to allocate\n", -1));
	}
	if (fabsf(cone->a) < EPSILON)
		count = calculate_parallel_t(shape, result_r, tray);
	else if (discr > 0 || fabsf(discr) < EPSILON)
		count = calculate_cone_t(discr, shape, result_r, tray);
	intersect_cone_caps(shape, tray, result_r, &count);
	result_r->count = count;
	return (0);
}
