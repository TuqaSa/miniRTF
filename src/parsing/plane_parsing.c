/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 06:51:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 19:02:34 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "shape.h"

/*
Plane:
pl 0.0,0.0,-10.0   0.0,1.0,0.0    0,0,225
∗ identifier: pl
∗ x, y, z coordinates of a point in the plane: 0.0,0.0,-10.0
∗ 3D normalized normal vector, in the range [-1,1] for each x, y, z axis:
0.0,1.0,0.0
∗ R,G,B colors in the range [0-255]: 0,0,225
*/

static t_planeparsectx	ft_initplanectx(char **id_r, int *ct_r)
{
	t_planeparsectx	ctx;

	ctx.i = ft_strlen(*id_r) + (*ct_r);
	ctx.clr = color(0, 0, 0);
	ctx.normalv = vector(0, 0, 0);
	ctx.point_coord = point(0, 0, 0);
	return (ctx);
}

static int	ft_fill_plane_data(t_world **data_r, t_planeparsectx *ctx_r)
{
	t_plane	*plane_data;
	t_shape	*shape;

	if (!data_r || !(*data_r) || !(*data_r)->shapes)
		return (-1);
	shape = (*data_r)->shapes;
	while (shape->next)
		shape = shape->next;
	plane_data = (t_plane *)shape->data;
	if (!plane_data)
		return (ft_indicate_err("Error\nplane data not allocated\n", -1));
	plane_data->point_coord = ctx_r->point_coord;
	plane_data->normalv = ctx_r->normalv;
	ft_fill_color(&shape->material.color, ctx_r->clr);
	ft_fill_color(&(shape->material.ambient_color), (*data_r)->ambient_color);
	shape->material.ambient_ratio = (*data_r)->ambient_ratio;
	return (0);
}

static int	ft_validate_plane_values(t_planeparsectx *ctx)
{
	float	magnitude;

	magnitude = tuple_magnitude(&(ctx->normalv));
	if (ctx->normalv.x < -1 || ctx->normalv.x > 1 || ctx->normalv.y < -1
		|| ctx->normalv.y > 1 || ctx->normalv.z < -1 || ctx->normalv.z > 1)
		return (ft_indicate_err(
				"Error\nPlane normal vector out of range [-1,1]\n", -1));
	if (fabsf(magnitude) < EPSILON)
		return (ft_indicate_err(
				"Error\nplane normal vector magnitude is zero\n", -1));
	if (fabsf(magnitude - 1.0f) > EPSILON)
		return (ft_indicate_err(
				"Error\nplane normal vector is not normalized\n", -1));
	return (0);
}

int	ft_parse_plane_data(char **line_r, t_world **data_r, char **id_r, int *ct_r)
{
	t_planeparsectx	ctx;

	ctx = ft_initplanectx(id_r, ct_r);
	if (ft_findtuple(line_r, &ctx.i, &ctx.point_coord) < 0)
		return (-1);
	if (ft_findtuple(line_r, &ctx.i, &ctx.normalv) < 0)
		return (-1);
	if (ft_find_rgbvalues(line_r, &ctx.i, &ctx.clr) < 0)
		return (-1);
	if (ft_validate_plane_values(&ctx) < 0)
		return (-1);
	if (add_plane(&((*data_r)->shapes)) < 0)
		return (-1);
	if (!ft_check_endof_line(line_r, &ctx.i))
	{
		if (ft_parse_bonus_values(line_r, data_r, &ctx.i) < 0)
			return (-1);
	}
	if (ft_fill_plane_data(data_r, &ctx) < 0)
		return (-1);
	return (0);
}
