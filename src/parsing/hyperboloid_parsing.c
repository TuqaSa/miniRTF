/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/12/07 19:46:55 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_ctxs.h"
#include "parsing.h"
#include "shape.h"

/*
 * Hyperboloid:
 * hy x,y,z   radius   min,max   R,G,B
 *
 * identifier: hy
 * x, y, z coordinates of the center: x,y,z
 * radius of the hyperboloid: radius
 * minimum and maximum y bounds: min,max
 * R, G, B colors in the range [0,255]: R,G,B
 */

static t_hypbparsectx	ft_inithypbctx(char **id_r, int *ct_r)
{
	t_hypbparsectx	ctx;

	ctx.radius = 1.0f;
	ctx.maximum = 1.0f;
	ctx.minimum = -1.0f;
	ctx.i = ft_strlen(*id_r) + (*ct_r);
	ctx.position = point(0, 0, 0);
	ctx.clr = color(255, 255, 255);
	return (ctx);
}

static int	ft_find_bounds(char **line_r, int *i, float *min_r, float *max_r)
{
	char	buffer[100];
	int		j;
	char	*comma_pos;

	ft_skip_spaces(line_r, i);
	j = 0;
	while ((*line_r)[*i] && (*line_r)[*i] != ' ' && (*line_r)[*i] != '\t'
			&& (*line_r)[*i] != '\n' && j < 99)
	{
		buffer[j] = (*line_r)[*i];
		(*i)++;
		j++;
	}
	buffer[j] = '\0';
	comma_pos = ft_strchr(buffer, ',');
	if (!comma_pos)
		return (-1);
	*comma_pos = '\0';
	*min_r = (float)ft_atoi(buffer);
	*max_r = (float)ft_atoi(comma_pos + 1);
	return (0);
}

int	ft_fill_hyperboloid_data(t_hypbparsectx ctx, t_world **data_r)
{
	t_shape			*curr;
	t_hyperboloid	*hyp;
	t_matrix4		trans_mat;

	curr = (*data_r)->shapes;
	if (!curr)
		return (ft_indicate_err(
				"Error\nNo shapes in world to fill hyperboloid data\n", -1));
	while (curr->next)
		curr = curr->next;
	hyp = (t_hyperboloid *)curr->data;
	hyp->radius = ctx.radius;
	hyp->minimum = ctx.minimum;
	hyp->maximum = ctx.maximum;
	trans_mat = translation(ctx.position.x, ctx.position.y, ctx.position.z);
	set_transform(curr, trans_mat);
	ft_fill_color(&curr->material.color, ctx.clr);
	ft_fill_color(&(curr->material.ambient_color), (*data_r)->ambient_color);
	curr->material.ambient_ratio = (*data_r)->ambient_ratio;
	return (0);
}

int	ft_parse_hyperboloid_data(char **line_r, t_world **data_r,
	char **id_r, int *ct_r)
{
	t_hypbparsectx	ctx;

	ctx = ft_inithypbctx(id_r, ct_r);
	if (ft_findtuple(line_r, &ctx.i, &ctx.position) < 0)
		return (-1);
	if (ft_findfloat(line_r, &ctx.i, &ctx.radius) < 0)
		return (-1);
	if (ft_find_bounds(line_r, &ctx.i, &ctx.minimum, &ctx.maximum) < 0)
		return (-1);
	if (ft_find_rgbvalues(line_r, &ctx.i, &ctx.clr) < 0)
		return (-1);
	if (ctx.radius <= 0)
		return (ft_indicate_err("Error\ninvalid hyperboloid radius\n", -1));
	if (ctx.minimum >= ctx.maximum)
		return (ft_indicate_err("Error\ninvalid hyperboloid bounds\n", -1));
	if (add_hyperboloid(&((*data_r)->shapes)) < 0)
		return (-1);
	if (!ft_check_endof_line(line_r, &ctx.i))
	{
		if (ft_parse_bonus_values(line_r, data_r, &ctx.i) < 0)
			return (-1);
	}
	if (ft_fill_hyperboloid_data(ctx, data_r) < 0)
		return (-1);
	return (0);
}
