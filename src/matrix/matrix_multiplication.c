/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:38 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/25 23:20:34 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "matrix.h"

float	tuple_dot_product(t_tuple *t1_r, t_tuple *t2_r)
{
	float	dot_prod;

	dot_prod = t1_r->x * t2_r->x + t1_r->y * t2_r->y
		+ t1_r->z * t2_r->z + t1_r->w * t2_r->w;
	return (dot_prod);
}

int	tuple_cross_product(t_tuple *r_res, t_tuple t1, t_tuple t2)
{
	float	x;
	float	y;
	float	z;

	x = t1.y * t2.z - t1.z * t2.y;
	y = -t1.x * t2.z + t1.z * t2.x;
	z = t1.x * t2.y - t1.y * t2.x;
	*r_res = vector(x, y, z);
	return (0);
}

t_tuple	mat4_multi_tuple(t_matrix4 m, t_tuple tup)
{
	t_tuple	new;

	new.x = m.m[0][0] * tup.x + m.m[0][1] * tup.y + m.m[0][2]
		* tup.z + m.m[0][3] * tup.w;
	new.y = m.m[1][0] * tup.x + m.m[1][1] * tup.y + m.m[1][2]
		* tup.z + m.m[1][3] * tup.w;
	new.z = m.m[2][0] * tup.x + m.m[2][1] * tup.y + m.m[2][2]
		* tup.z + m.m[2][3] * tup.w;
	new.w = m.m[3][0] * tup.x + m.m[3][1] * tup.y + m.m[3][2]
		* tup.z + m.m[3][3] * tup.w;
	return (new);
}

void	mat4_multiplication(t_matrix4 *result_r, t_matrix4 a, t_matrix4 b)
{
	int			row;
	int			col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result_r->m[row][col] = a.m[row][0] * b.m[0][col]
				+ a.m[row][1] * b.m[1][col]
				+ a.m[row][2] * b.m[2][col]
				+ a.m[row][3] * b.m[3][col];
			col++;
		}
		row++;
	}
}
