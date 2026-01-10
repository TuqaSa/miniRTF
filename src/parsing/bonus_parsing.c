/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:39 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/05 17:20:30 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static	t_bonusparsectx	ft_initbonusctx(void)
{
	t_bonusparsectx	ctx;

	ctx.specular = 0.0f;
	ctx.checker_flag = 0;
	ctx.checker_c1 = color(0, 0, 0);
	ctx.checker_c2 = color(0, 0, 0);
	return (ctx);
}

int	ft_check_endof_line(char **line_r, int *i_r)
{
	size_t	len;

	if (!line_r || !(*line_r) || !i_r)
		return (1);
	len = ft_strlen(*line_r);
	if (*i_r < 0 || (size_t)(*i_r) >= len)
		return (1);
	while ((*line_r)[*i_r] == ' ' || (*line_r)[*i_r] == '\t')
		(*i_r)++;
	if ((*line_r)[*i_r] == '\n' || (*line_r)[*i_r] == '\0')
		return (1);
	return (0);
}

static int	ft_validate_bonus_values(t_bonusparsectx *ctx_r)
{
	if (ctx_r->specular < 0.0f)
		return (ft_indicate_err(
				"Error\nSpecular value cannot be negative\n", -1));
	if (ctx_r->specular > 1.0f)
		return (ft_indicate_err(
				"Error\nSpecular value cannot be greater than 1.0\n", -1));
	return (0);
}

static int	ft_fill_bonus(t_world **data_r, t_bonusparsectx *ctx_r)
{
	t_shape	*shape;

	if (!data_r || !(*data_r) || !(*data_r)->shapes)
		return (-1);
	shape = (*data_r)->shapes;
	while (shape->next)
		shape = shape->next;
	shape->material.specular = ctx_r->specular;
	if (ctx_r->checker_flag == 1)
		shape->material.pattern = checkers_pattern(
				ctx_r->checker_c1, ctx_r->checker_c2, 1);
	return (0);
}

int	ft_parse_bonus_values(char **line_r, t_world **data_r, int *i_r)
{
	t_bonusparsectx	ctx;

	ctx = ft_initbonusctx();
	if (ft_findfloat(line_r, i_r, &(ctx.specular)) < 0)
		return (-1);
	if (!ft_check_endof_line(line_r, i_r))
	{
		if (ft_find_rgbvalues(line_r, i_r, &(ctx.checker_c1)) < 0)
			return (-1);
		if (ft_find_rgbvalues(line_r, i_r, &(ctx.checker_c2)) < 0)
			return (-1);
		ctx.checker_flag = 1;
	}
	if (!ft_check_endof_line(line_r, i_r))
		return (ft_indicate_err(
				"Error\nextra characters at end of line\n", -1));
	if (ft_validate_bonus_values(&ctx) < 0)
		return (-1);
	if (ft_fill_bonus(data_r, &ctx) < 0)
		return (-1);
	return (0);
}
