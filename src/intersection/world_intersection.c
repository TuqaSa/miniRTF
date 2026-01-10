/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:36:44 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/25 13:58:25 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape.h"
#include "libft.h"

int	ft_accum_interxs(t_intersections *totxs_r, t_intersections *currxs_r)
{
	int				i;
	int				j;
	int				newsize;
	t_intersection	*tmpxs;

	i = 0;
	newsize = totxs_r->count + currxs_r->count;
	tmpxs = realloc_xs(totxs_r->xs, newsize, totxs_r->count);
	if (!tmpxs)
		return (-1);
	free(totxs_r->xs);
	totxs_r->xs = tmpxs;
	j = totxs_r->count;
	totxs_r->count += currxs_r->count;
	while (i < currxs_r->count)
	{
		totxs_r->xs[j] = currxs_r->xs[i];
		i++;
		j++;
	}
	return (0);
}

static int	count_shapes(t_shape *shapes)
{
	int		count;
	t_shape	*curr;

	count = 0;
	curr = shapes;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

static int	intersect_all_shapes(t_world **world_r, t_ray *ray_r,
		t_intersections *totxs_r)
{
	t_intersections	currxs;
	t_shape			*curr_sp;

	ft_memset(&currxs, 0, sizeof(t_intersections));
	curr_sp = (*world_r)->shapes;
	while (curr_sp)
	{
		if (intersect(curr_sp, ray_r, &currxs) < 0)
			return (-1);
		ft_accum_interxs(totxs_r, &currxs);
		if (currxs.xs)
		{
			free(currxs.xs);
			currxs.xs = NULL;
		}
		curr_sp = curr_sp->next;
	}
	return (0);
}

int	ft_intersect_world(t_world **world_r, t_ray *ray_r,
		t_intersections *totxs_r)
{
	int	shape_count;
	int	estimated_capacity;

	if (!(*world_r)->shapes)
		return (ft_indicate_err("world has no spheres\n", -1));
	shape_count = count_shapes((*world_r)->shapes);
	estimated_capacity = shape_count * 4;
	totxs_r->xs = (t_intersection *)ft_calloc(estimated_capacity,
			sizeof(t_intersection));
	if (!totxs_r->xs)
		return (-1);
	if (intersect_all_shapes(world_r, ray_r, totxs_r) < 0)
		return (-1);
	sort_intersections(totxs_r);
	return (0);
}
