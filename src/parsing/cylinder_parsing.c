/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:48:46 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 23:04:02 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_ctxs.h"
#include "parsing.h"
#include "shape.h"

/*
Cylinder:
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255 0.6 0,0,0 255,255,255
∗ identifier: cy
∗ x, y, z coordinates of the center of the cylinder: 50.0,0.0,20.6
∗ 3D normalized vector of axis of cylinder, in the range [-1,1] for each x, y,
z axis: 0.0,0.0,1.0
∗ the cylinder diameter: 14.2
∗ the cylinder height: 21.42
∗ R, G, B colors in the range [0,255]: 10, 0, 255
 * ∗ (optional) specular value in the range [0.0,1.0]: 0.6
 ∗ (optional) checker pattern
 colors in the range [0,255]: 0,0,0 255,255,255 same for all shapes
 */

int	ft_validate_cylinder_data(t_cylparsectx *ctx)
{
	float	magnitude;
	t_tuple	orietv;

	orietv = ctx->orientationv;
	if (orietv.x < -1.0 || orietv.x > 1.0 || orietv.y < -1.0 || orietv.y > 1.0
		|| orietv.z < -1.0 || orietv.z > 1.0)
		return (ft_indicate_err("Error\nCOV values out of range\n", -1));
	magnitude = tuple_magnitude(&orietv);
	if (fabsf(magnitude) < EPSILON)
		return (ft_indicate_err("Error\nCOV magnitude is zero\n", -1));
	if (fabsf(magnitude - 1) > EPSILON)
		return (ft_indicate_err("Error\nCOV is not normalized\n", -1));
	if (ctx->diameter <= 0.0)
		return (ft_indicate_err(
				"Error\nCylinder diameter must be greater than zero\n",
				-1));
	if (ctx->height <= 0.0)
		return (ft_indicate_err(
				"Error\nCylinder height must be greater than zero\n",
				-1));
	return (0);
}

static void	ft_cyl_orienmat(t_matrix4 *mat, t_tuple rightv, t_tuple forwardv,
		t_tuple upv)
{
	mat->m[0][0] = rightv.x;
	mat->m[0][1] = upv.x;
	mat->m[0][2] = forwardv.x;
	mat->m[1][0] = rightv.y;
	mat->m[1][1] = upv.y;
	mat->m[1][2] = forwardv.y;
	mat->m[2][0] = rightv.z;
	mat->m[2][1] = upv.z;
	mat->m[2][2] = forwardv.z;
}

static t_matrix4	ft_cylinder_orientation(t_tuple orientatiov)
{
	t_cyl_orint		cylort;

	cylort.result = matrix4_identity();
	cylort.forwardv = vector(0, 0, 0);
	cylort.upv = tuple_norm(&orientatiov);
	if (fabsf(cylort.upv.x - 1.0f) < EPSILON)
		cylort.tmpv = vector(0, 1, 0);
	else
		cylort.tmpv = vector(1, 0, 0);
	cylort.dotproduct = tuple_dot_product(&cylort.tmpv, &cylort.upv);
	cylort.projection = tuple_scale(&cylort.upv, cylort.dotproduct);
	cylort.rightv = tuple_sub(&cylort.tmpv, &cylort.projection);
	cylort.rightv = tuple_norm(&cylort.rightv);
	tuple_cross_product(&cylort.forwardv, cylort.upv, cylort.rightv);
	cylort.forwardv = tuple_norm(&cylort.forwardv);
	ft_cyl_orienmat(&cylort.result, cylort.rightv,
		cylort.forwardv, cylort.upv);
	return (cylort.result);
}

static int	ft_fill_cylinder_data(t_cylparsectx *ctx, t_world **data_r)
{
	t_shape		*curr;
	t_cylinder	*cyl;
	t_matrix4	orientmat;
	t_matrix4	tmpmat;

	tmpmat = matrix4_identity();
	curr = (*data_r)->shapes;
	if (!curr)
		return (ft_indicate_err("Error\nNo shapes in world\n",
				-1));
	while (curr->next)
		curr = curr->next;
	cyl = (t_cylinder *)curr->data;
	cyl->radius = ctx->diameter / 2.0;
	cyl->minimum = ctx->position.y;
	cyl->maximum = ctx->position.y + ctx->height;
	ft_fill_color(&curr->material.color, ctx->clr);
	ft_fill_color(&(curr->material.ambient_color), (*data_r)->ambient_color);
	orientmat = ft_cylinder_orientation(ctx->orientationv);
	mat4_multiplication(&tmpmat, orientmat, scaling(cyl->radius, 1,
			cyl->radius));
	mat4_multiplication(&tmpmat, translation(ctx->position.x, ctx->position.y,
			ctx->position.z), tmpmat);
	set_transform(curr, tmpmat);
	return (0);
}

int	ft_parse_cylinder_data(char **line_r, t_world **data_r,
	char **id_r, int *ct_r)
{
	t_cylparsectx	ctx;

	ctx = ft_initcylctx(id_r, ct_r);
	if (ft_findtuple(line_r, &ctx.i, &ctx.position) < 0)
		return (-1);
	if (ft_findtuple(line_r, &ctx.i, &ctx.orientationv) < 0)
		return (-1);
	if (ft_findfloat(line_r, &ctx.i, &ctx.diameter) < 0)
		return (-1);
	if (ft_findfloat(line_r, &ctx.i, &ctx.height) < 0)
		return (-1);
	if (ft_find_rgbvalues(line_r, &ctx.i, &ctx.clr) < 0)
		return (-1);
	if (ft_validate_cylinder_data(&ctx) < 0)
		return (-1);
	if (add_cylinder(&((*data_r)->shapes)) < 0)
		return (-1);
	if (!ft_check_endof_line(line_r, &ctx.i))
	{
		if (ft_parse_bonus_values(line_r, data_r, &ctx.i) < 0)
			return (-1);
	}
	if (ft_fill_cylinder_data(&ctx, data_r) < 0)
		return (-1);
	return (0);
}
