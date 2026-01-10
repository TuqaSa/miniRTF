/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/11 10:37:23 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

float	mat_det(void *_base_mat)
{
	t_mat	*base;
	float	det;

	det = 0;
	base = (t_mat *)_base_mat;
	if (base->det)
		det = base->det(_base_mat);
	return (det);
}

float	mat4_det(void *self)
{
	int			j;
	float		det;
	t_matrix4	*mat;
	t_matrix3	submat;

	j = 0;
	det = 0;
	mat = (t_matrix4 *)self;
	while (j < 4)
	{
		submat = init_mat3();
		ft_sub_mat(mat, &submat, 0, j);
		det += mat->m[0][j] * mat_cofactor(mat, &submat, 0, j);
		j++;
	}
	mat->mat.det_value = det;
	return (det);
}

float	mat3_det(void *self)
{
	int			j;
	float		det;
	t_matrix3	*mat;
	t_matrix2	submat;

	j = 0;
	det = 0;
	submat = init_mat2();
	mat = (t_matrix3 *)self;
	while (j < 3)
	{
		det += mat->m[0][j] * mat_cofactor(self, &submat, 0, j);
		j++;
	}
	return (det);
}

float	mat2_det(void *self)
{
	t_matrix2	*mat;
	float		det;

	mat = (t_matrix2 *)self;
	det = mat->m[0][0] * mat->m[1][1] - mat->m[0][1] * mat->m[1][0];
	return (det);
}
