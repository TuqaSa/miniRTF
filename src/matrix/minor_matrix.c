/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:38:15 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/11 10:38:16 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float	mat_minor(void *_base_mat, void *sub_mat, int row, int col)
{
	t_mat	*base;
	float	minorf;

	minorf = 0;
	base = (t_mat *)_base_mat;
	if (base->minor)
		minorf = base->minor(_base_mat, sub_mat, row, col);
	return (minorf);
}

float	mat4_minor(void *self, void *sub_mat, int row, int col)
{
	float	minor;

	(void)self;
	(void)row;
	(void)col;
	minor = mat_det(sub_mat);
	return (minor);
}

float	mat3_minor(void *self, void *sub_mat, int row, int col)
{
	float	det;

	ft_sub_mat(self, sub_mat, row, col);
	det = mat_det(sub_mat);
	return (det);
}
