/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:14 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 19:00:49 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include <stdio.h>

int	ft_ispunctuaction(char c)
{
	if (c == '.' || c == ',' || c == '-'
		|| c == ' ' || c == '+' || c == '\n'
		|| c == '\t')
		return (1);
	return (0);
}

int	ft_valid_char(char c)
{
	if (ft_isdigit(c) || ft_ispunctuaction(c))
		return (1);
	printf("%s :%d, c = %c\n", __func__, __LINE__, c);
	return (ft_indicate_err("Error\ninvalid character\n", 0));
}

int	ft_increament(int *flt, int *i, int *dig_ind)
{
	int	arb;

	if (flt)
		(*flt)++;
	if (i)
		(*i)++;
	if (dig_ind)
		(*dig_ind)++;
	if (!flt || !i || !dig_ind)
		return (0);
	arb = (*flt) + (*i) + (*dig_ind);
	return (arb);
}

void	ft_fill_color(t_color *destc, t_color sourcec)
{
	destc->r = sourcec.r / 255.0f;
	destc->g = sourcec.g / 255.0f;
	destc->b = sourcec.b / 255.0f;
}

t_cylparsectx	ft_initcylctx(char **id_r, int *ct_r)
{
	t_cylparsectx	ctx;

	ctx.position = point(0, 0, 0);
	ctx.orientationv = point(0, 0, 0);
	ctx.diameter = 0.0;
	ctx.height = 0.0;
	ctx.clr = color(0, 0, 0);
	ctx.i = ft_strlen((*id_r)) + (*ct_r);
	return (ctx);
}
