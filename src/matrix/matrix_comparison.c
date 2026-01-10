/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_comparison.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:18 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/11 10:37:19 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>
#include <MLX42/MLX42.h>

// can we use polymorphism for these functions?

int32_t	mat4_equality(t_matrix4 *r_m1, t_matrix4 *r_m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!ft_float_equal(r_m1->m[i][j], r_m2->m[i][j]))
			{
				printf("r_m1->m[%d][%d] (%f) != r_m2->m[%d][%d (%f)]\n",
					i, j, r_m1->m[i][j], i, j, r_m2->m[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int32_t	mat3_equality(t_matrix3 *r_m1, t_matrix3 *r_m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (r_m1->m[i][j] != r_m2->m[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int32_t	mat2_equality(t_matrix2 *r_m1, t_matrix2 *r_m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			if (r_m1->m[i][j] != r_m2->m[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
