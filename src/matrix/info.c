/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:36:56 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/11 10:36:57 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "matrix.h"

void	tuple_info(t_tuple *t_r)
{
	printf("(%f, %f, %f, %f)\n", t_r->x, t_r->y, t_r->z, t_r->w);
}

void	mat_info(void *_base_mat)
{
	t_mat	*base;

	base = (t_mat *)_base_mat;
	if (base->info)
		base->info(_base_mat);
	if (base->info == NULL)
		printf("%s:%d, mat->info is NULL\n", __func__, __LINE__);
}

void	mat4_info(void *self)
{
	t_matrix4	*mat;

	printf("%s,%d: here:\n", __func__, __LINE__);
	mat = (t_matrix4 *)self;
	printf("|%10f|%10f|%10f|%10f|\n", mat->m[0][0],
		mat->m[0][1], mat->m[0][2], mat->m[0][3]);
	printf("|%10f|%10f|%10f|%10f|\n", mat->m[1][0],
		mat->m[1][1], mat->m[1][2], mat->m[1][3]);
	printf("|%10f|%10f|%10f|%10f|\n", mat->m[2][0],
		mat->m[2][1], mat->m[2][2], mat->m[2][3]);
	printf("|%10f|%10f|%10f|%10f|\n", mat->m[3][0],
		mat->m[3][1], mat->m[3][2], mat->m[3][3]);
}

void	mat3_info(void *self)
{
	t_matrix3	*mat;

	mat = (t_matrix3 *)self;
	printf("|%10f|%10f|%10f|\n", mat->m[0][0], mat->m[0][1], mat->m[0][2]);
	printf("|%10f|%10f|%10f|\n", mat->m[1][0], mat->m[1][1], mat->m[1][2]);
	printf("|%10f|%10f|%10f|\n", mat->m[2][0], mat->m[2][1], mat->m[2][2]);
}

void	mat2_info(void *self)
{
	t_matrix2	*mat;

	mat = (t_matrix2 *)self;
	printf("|%10f|%10f|\n", mat->m[0][0], mat->m[0][1]);
	printf("|%10f|%10f|\n", mat->m[1][0], mat->m[1][1]);
}
