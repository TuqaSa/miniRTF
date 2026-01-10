/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:32:27 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 19:00:35 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "shape.h"
#include "data_ctxs.h"
/*
Cone:
cn 0.0,0.0,0.0  0.0,1.0,0.0  14.2  21.42  10,0,255  0.6   0,0,0 255,255,255
∗ identifier: cn
∗ x, y, z coordinates of the apex of the cone: 0.0,0.0,0.0
∗ 3D normalized vector of axis of cone, in the range [-1,1] for each x, y,
z axis: 0.0,1.0,0.0
∗ the cone base diameter: 14.2
∗ the cone height: 21.42
∗ R, G, B colors in the range [0,255]: 10, 0, 255
 * ∗ (optional) specular value in the range [0.0,1.0]: 0.6
 ∗ (optional) checker pattern colors in the range [0,255]: 0,0,0 255,255,255
 */

static void	ft_cone_orienmat(t_matrix4 *mat, t_tuple rightv, t_tuple forwardv,
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

static t_matrix4	ft_cone_orientation(t_tuple orientatiov)
{
	t_cyl_orint		cort;

	cort.result = matrix4_identity();
	cort.forwardv = vector(0, 0, 0);
	cort.upv = tuple_norm(&orientatiov);
	if (fabsf(fabsf(cort.upv.x) - 1.0f) < EPSILON)
		cort.tmpv = vector(0, 1, 0);
	else
		cort.tmpv = vector(1, 0, 0);
	cort.dotproduct = tuple_dot_product(&cort.tmpv, &cort.upv);
	cort.projection = tuple_scale(&cort.upv, cort.dotproduct);
	cort.rightv = tuple_sub(&cort.tmpv, &cort.projection);
	cort.rightv = tuple_norm(&cort.rightv);
	tuple_cross_product(&cort.forwardv, cort.rightv, cort.upv);
	cort.forwardv = tuple_norm(&cort.forwardv);
	ft_cone_orienmat(&cort.result, cort.rightv,
		cort.forwardv, cort.upv);
	return (cort.result);
}

// The cone base is larger than the diameter of the passed diameter
int	ft_fill_cone_data(t_cylparsectx ctx, t_world **data_r)
{
	t_shape		*curr;
	t_cylinder	*cone;
	t_matrix4	orient_mat;
	t_matrix4	tmp_mat;

	tmp_mat = matrix4_identity();
	curr = (*data_r)->shapes;
	if (!curr)
		return (ft_indicate_err("Error\nNo shapes in world\n", -1));
	while (curr->next)
		curr = curr->next;
	cone = (t_cylinder *)curr->data;
	cone->radius = ctx.diameter / 2.0f;
	cone->minimum = 0.0f;
	cone->maximum = ctx.height;
	orient_mat = ft_cone_orientation(ctx.orientationv);
	mat4_multiplication(&tmp_mat,
		orient_mat, scaling(cone->radius, ctx.height, cone->radius));
	mat4_multiplication(&tmp_mat,
		translation(ctx.position.x, ctx.position.y, ctx.position.z), tmp_mat);
	set_transform(curr, tmp_mat);
	ft_fill_color(&curr->material.color, ctx.clr);
	ft_fill_color(&(curr->material.ambient_color), (*data_r)->ambient_color);
	curr->material.ambient_ratio = (*data_r)->ambient_ratio;
	return (0);
}

int	ft_parse_cone_data(char **line_r, t_world **data_r, char **id_r, int *ct_r)
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
	if (add_cone(&((*data_r)->shapes)) < 0)
		return (-1);
	if (!ft_check_endof_line(line_r, &ctx.i))
	{
		if (ft_parse_bonus_values(line_r, data_r, &ctx.i) < 0)
			return (-1);
	}
	if (ft_fill_cone_data(ctx, data_r) < 0)
		return (-1);
	return (0);
}
