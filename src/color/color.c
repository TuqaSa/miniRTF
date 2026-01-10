/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:12:12 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/07 16:01:34 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "shape.h"

t_color	color(float r, float g, float b)
{
	t_color	result;

	result.r = r;
	result.g = g;
	result.b = b;
	return (result);
}

void	color_info(t_color *color_r)
{
	printf("color: (%f, %f, %f)\n", color_r->r, color_r->g, color_r->b);
}

/*
** The `color_at` function will intersect the world with the given ray
** and then return the color at the resulting intersection.
*/

int	color_at(t_world **world_r, t_ray *ray_r, t_color *shade_r)
{
	t_precomp		precomp;
	t_intersections	txs;
	t_intersection	xs;

	ft_memset(&txs, 0, sizeof(t_intersections));
	ft_memset(&xs, 0, sizeof(t_intersection));
	if (ft_intersect_world(world_r, ray_r, &txs) < 0)
		return (-1);
	if (hit(txs, &xs) < 0)
	{
		*shade_r = color(0, 0, 0);
		free(txs.xs);
		return (0);
	}
	precomp = prepare_computations(ray_r, &xs);
	*shade_r = shade_hit(world_r, &precomp);
	free(txs.xs);
	return (0);
}
