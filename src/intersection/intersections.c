/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 00:00:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/10/15 18:29:24 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <float.h>

t_intersection	intersection(float t, void *object)
{
	t_intersection	i;
	t_shape			*base;

	base = (t_shape *)object;
	i.t = t;
	i.object = base;
	return (i);
}

static void	fill_intersections(t_intersections *result, int count, va_list args)
{
	int	i;

	i = 0;
	while (i < count)
	{
		result->xs[i] = va_arg(args, t_intersection);
		i++;
	}
}

t_intersections	intersections(int count, ...)
{
	t_intersections	result;
	va_list			args;

	result.count = count;
	va_start(args, count);
	fill_intersections(&result, count, args);
	va_end(args);
	sort_intersections(&result);
	return (result);
}

int	hit(t_intersections xs, t_intersection *result_r)
{
	int		i;
	int		found;
	float	best_t;

	i = 0;
	found = 0;
	best_t = FLT_MAX;
	while (i < xs.count)
	{
		if (xs.xs[i].t > EPSILON && xs.xs[i].t < best_t)
		{
			best_t = xs.xs[i].t;
			*result_r = xs.xs[i];
			found = 1;
		}
		i++;
	}
	if (found)
		return (0);
	return (-1);
}
