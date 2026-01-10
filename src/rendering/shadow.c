/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:37:26 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/08 12:02:50 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "data_ctxs.h"
#include "shape.h"

static t_shadowctx	init_shadowctx(void)
{
	t_shadowctx		ctx;

	ft_memset(&ctx, 0, sizeof(t_shadowctx));
	return (ctx);
}

static int	check_blocking_intersection(t_intersections *currxs, float max_dist)
{
	int	i;

	i = 0;
	while (i < currxs->count)
	{
		if (currxs->xs[i].t > EPSILON && currxs->xs[i].t < max_dist)
		{
			if (currxs->xs)
				free(currxs->xs);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_intersect_world_early_exit(t_world **world_r, t_ray *ray_r,
		float max_dist)
{
	t_intersections	currxs;
	t_shape			*curr_sp;
	int				blocked;

	if (!(*world_r)->shapes)
		return (0);
	ft_memset(&currxs, 0, sizeof(t_intersections));
	curr_sp = (*world_r)->shapes;
	while (curr_sp)
	{
		if (intersect(curr_sp, ray_r, &currxs) < 0)
			return (-1);
		blocked = check_blocking_intersection(&currxs, max_dist);
		if (blocked)
			return (1);
		if (currxs.xs)
		{
			free(currxs.xs);
			currxs.xs = NULL;
		}
		curr_sp = curr_sp->next;
	}
	return (0);
}

int	is_shadowed(t_world *world, t_tuple point, t_light *light)
{
	t_shadowctx	ctx;
	int			blocked;

	ctx = init_shadowctx();
	ctx.v = tuple_sub(&(light->position), &point);
	ctx.distance = tuple_magnitude(&ctx.v);
	ctx.direction = tuple_norm(&ctx.v);
	ctx.tmp = tuple_scale(&ctx.direction, 0.001f);
	ctx.offset_point = tuple_add(&point, &(ctx.tmp));
	ctx.ray = create_ray(ctx.offset_point, ctx.direction);
	blocked = ft_intersect_world_early_exit(&world, &ctx.ray,
			ctx.distance - 0.001f);
	if (blocked < 0)
		return (-1);
	return (blocked);
}

t_color	shade_hit(t_world **world_r, t_precomp *comp_r)
{
	t_color	shade;
	t_color	lit;
	t_light	*light;
	int		is_shadow;

	shade = color(0, 0, 0);
	light = (*world_r)->lights;
	while (light)
	{
		is_shadow = is_shadowed(*world_r, comp_r->over_point, light);
		lit = lighting(light, comp_r, is_shadow);
		shade = addcolor(shade, lit);
		light = light->next;
	}
	return (shade);
}
