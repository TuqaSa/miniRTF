/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:07:04 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 23:10:32 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shape.h"
#include "minirt.h"
#include "parsing.h"

/*
Sphere:
sp 0.0,0.0,20.6 12.6 10,0,255
∗ identifier: sp
∗ x, y, z coordinates of the sphere center: 0.0,0.0,20.6
∗ the sphere diameter: 12.6
∗ R,G,B colors in the range [0-255]: 10, 0, 255
*/

static int	ft_validate_sphere_data(float diameter)
{
	if (diameter <= 0.0f)
		return (ft_indicate_err(
				"Error\nSphere diameter must be greater than zero\n", -1));
	return (0);
}

static int	ft_fill_sphere(t_tuple position, float diameter, t_color clr,
	t_world **data_r)
{
	t_shape		*sphere;
	t_matrix4	tmat;
	float		radius;

	radius = diameter / 2.0f;
	tmat = matrix4_identity();
	sphere = (*data_r)->shapes;
	while (sphere->next)
		sphere = sphere->next;
	mat4_multiplication(&tmat, translation(position.x, position.y, position.z),
		scaling(radius, radius, radius));
	set_transform(sphere, tmat);
	ft_fill_color(&sphere->material.color, clr);
	ft_fill_color(&(sphere->material.ambient_color), (*data_r)->ambient_color);
	sphere->material.ambient_ratio = (*data_r)->ambient_ratio;
	if (sphere->material.pattern.flag)
	{
		set_pattern_transform(&sphere->material.pattern,
			scaling(1 / radius, 1 / radius, 1 / radius));
	}
	return (0);
}

int	ft_parse_sphere_data(char **line_r, t_world **data_r,
	char **id_r, int *ct_r)
{
	t_sphparse_ctx	ctx;

	ctx.i = ft_strlen(*id_r) + (*ct_r);
	ctx.diameter = 0;
	ctx.position = point(0, 0, 0);
	ctx.clr = color(0, 0, 0);
	if (ft_findtuple(line_r, &ctx.i, &ctx.position) < 0)
		return (-1);
	if (ft_findfloat(line_r, &ctx.i, &ctx.diameter) < 0)
		return (-1);
	if (ft_find_rgbvalues(line_r, &ctx.i, &ctx.clr) < 0)
		return (-1);
	if (ft_validate_sphere_data(ctx.diameter) < 0)
		return (-1);
	if (add_sphere(&((*data_r)->shapes)) < 0)
		return (-1);
	if (!ft_check_endof_line(line_r, &ctx.i))
	{
		if (ft_parse_bonus_values(line_r, data_r, &ctx.i) < 0)
			return (-1);
	}
	if (ft_fill_sphere(ctx.position, ctx.diameter, ctx.clr, data_r) < 0)
		return (-1);
	return (0);
}
