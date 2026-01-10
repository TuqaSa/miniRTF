/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:38:21 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 17:02:49 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>
#include "data_ctxs.h"

void	ft_sub_mat(void *_base_mat, void *sub_mat, int row, int col)
{
	t_mat	*base;

	base = (t_mat *)_base_mat;
	if (base->sub_mat)
		base->sub_mat(_base_mat, sub_mat, row, col);
}

void	mat4_submat(void *self, void *sub_mat, int row, int col)
{
	t_submat4_ctx	ctx;

	ctx.mat = (t_matrix4 *)self;
	ctx.submat = (t_matrix3 *)sub_mat;
	ctx.i = 0;
	ctx.k = 0;
	while (ctx.i < 4)
	{
		ctx.j = 0;
		ctx.l = 0;
		while (ctx.j < 4)
		{
			if (ctx.i == row || ctx.j == col)
			{
				ctx.j++;
				continue ;
			}
			ctx.submat->m[ctx.k][ctx.l] = ctx.mat->m[ctx.i][ctx.j];
			ctx.j++;
			ctx.l++;
			if (ctx.l > 2)
				ctx.k++;
		}
		ctx.i++;
	}
}

void	mat3_submat(void *self, void *sub_mat, int row, int col)
{
	t_submat3_ctx	ctx;

	ctx.mat = (t_matrix3 *)self;
	ctx.submat = (t_matrix2 *)sub_mat;
	ctx.i = 0;
	ctx.k = 0;
	while (ctx.i < 3)
	{
		ctx.j = 0;
		ctx.l = 0;
		while (ctx.j < 3)
		{
			if (ctx.i == row || ctx.j == col)
			{
				ctx.j++;
				continue ;
			}
			ctx.submat->m[ctx.k][ctx.l] = ctx.mat->m[ctx.i][ctx.j];
			ctx.j++;
			ctx.l++;
			if (ctx.l > 1)
				ctx.k++;
		}
		ctx.i++;
	}
}
