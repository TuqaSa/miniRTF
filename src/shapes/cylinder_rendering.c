/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_rendering.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:49:56 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/09 18:32:15 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
//#include "libft.h"
#include "matrix.h"
#include "data_ctxs.h"

static float	check_cap(t_ray ray, float t)
{
	float	result;
	float	x;
	float	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	result = powf(x, 2) + powf(z, 2);
	return (result <= 1.0f + EPSILON);
}

float	cylinder_calculate_discriminant(t_cylinder *cyl, t_ray ray)
{
	float	disc;

	cyl->a = powf(ray.direction.x, 2) + powf(ray.direction.z, 2);
	cyl->b = (2 * ray.origin.x * ray.direction.x)
		+ (2 * ray.origin.z * ray.direction.z);
	cyl->c = powf(ray.origin.x, 2) + powf(ray.origin.z, 2) - 1;
	disc = powf(cyl->b, 2) - (4 * cyl->a * cyl->c);
	return (disc);
}

void	intersect_cylinder_caps(t_shape *shape, t_ray ray,
	t_intersections *txs_r, int *count)
{
	float		t;
	t_cylinder	*cyl;

	cyl = (t_cylinder *)shape->data;
	if (cyl->closed == 0)
		return ;
	t = (cyl->minimum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
	{
		txs_r->xs[*count] = intersection(t, shape);
		(*count)++;
	}
	t = (cyl->maximum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
	{
		txs_r->xs[*count] = intersection(t, shape);
		(*count)++;
	}
	return ;
}

int	calculate_cylinderbdy_t(float discr, t_shape *shape,
	t_intersections *result_r, t_ray ray)
{
	t_cylt_ctx	ctx;

	ctx.i = 0;
	ctx.count = 0;
	ctx.cyl = shape->data;
	result_r->xs = init_xs(4);
	if (!result_r->xs)
		return (ft_indicate_err("Error\nfailed to allocate intersections\n",
				-1));
	ctx.t[0] = (-ctx.cyl->b - sqrt(discr)) / (2 * ctx.cyl->a);
	ctx.t[1] = (-ctx.cyl->b + sqrt(discr)) / (2 * ctx.cyl->a);
	swap(&ctx.t[0], &ctx.t[1]);
	while (ctx.i < 2)
	{
		ctx.y[ctx.i] = ray.origin.y + ctx.t[ctx.i] * ray.direction.y;
		if (ctx.cyl->minimum < ctx.y[ctx.i] && ctx.y[ctx.i] < ctx.cyl->maximum)
		{
			result_r->xs[ctx.count] = intersection(ctx.t[ctx.i], shape);
			ctx.count++;
		}
		ctx.i++;
	}
	return (ctx.count);
}
