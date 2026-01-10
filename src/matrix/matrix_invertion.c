/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invertion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:35 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/10 09:50:36 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

void	inverse_mat(void *base_mat, void *inv_mat)
{
	t_mat	*mat;

	mat = (t_mat *)base_mat;
	if (mat->inverse)
		mat->inverse(base_mat, inv_mat);
	return ;
}

void	mat4_inverse(void *self, void *invmat)
{
	int			i;
	int			j;
	t_matrix4	*mat;
	t_matrix4	*inv_mat;
	t_matrix3	submat;

	mat = (t_matrix4 *)self;
	inv_mat = (t_matrix4 *)invmat;
	mat_det(mat);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			submat = init_mat3();
			ft_sub_mat(mat, &submat, i, j);
			inv_mat->m[j][i] = mat_cofactor(mat,
					&submat, i, j) / mat->mat.det_value;
			j++;
		}
		i++;
	}
}
