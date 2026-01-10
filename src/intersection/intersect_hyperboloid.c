/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_hyperboloid.c                            :+:      :+:    :+:   */
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

static int	handle_hyperboloid_parallel(t_hyperboloid *hyp, t_ray tray,
		t_intersections *result_r, t_shape *shape)
{
	float	t;

	t = hyperboloid_calculate_parallel_t(hyp, tray);
	if (t >= EPSILON && t >= hyp->minimum && t <= hyp->maximum)
	{
		result_r->xs[0] = intersection(t, shape);
		result_r->count = 1;
	}
	else
		result_r->count = 0;
	return (0);
}

static int	init_hyperboloid_intersections(t_intersections *result_r)
{
	result_r->xs = init_xs(2);
	if (!result_r->xs)
	{
		result_r->count = 0;
		return (ft_indicate_err("Error\nfailed to allocate\n", -1));
	}
	return (0);
}

int	intersect_hyperboloid(t_shape *shape, t_ray *ray_r,
		t_intersections *result_r)
{
	int				count;
	t_hyperboloid	*hyp;
	t_ray			transformed_ray;
	float			discriminant;

	hyp = (t_hyperboloid *)shape->data;
	transformed_ray = get_transformed_ray(shape, ray_r);
	discriminant = hyperboloid_calculate_discriminant(hyp, transformed_ray);
	if (init_hyperboloid_intersections(result_r) < 0)
		return (-1);
	if (discriminant < 0)
		result_r->count = 0;
	else if (fabsf(hyp->a) < EPSILON)
		return (handle_hyperboloid_parallel(hyp, transformed_ray, result_r,
				shape));
	else
	{
		count = hyperboloid_calculate_t(hyp, transformed_ray, result_r, shape);
		result_r->count = count;
	}
	return (0);
}
