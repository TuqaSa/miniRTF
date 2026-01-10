/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:25 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 16:10:17 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "minirt.h"
#include "libft.h"
#include <string.h>

t_matrix4	init_mat4(void)
{
	t_matrix4	new;

	ft_memset(&new, 0, sizeof(new));
	new.mat.det = mat4_det;
	new.mat.info = mat4_info;
	new.mat.is_invertable = 0;
	new.mat.minor = mat4_minor;
	new.mat.sub_mat = mat4_submat;
	new.mat.cofactor = mat4_cofactor;
	new.mat.inverse = mat4_inverse;
	return (new);
}

t_matrix3	init_mat3(void)
{
	t_matrix3	new;

	ft_memset(&new, 0, sizeof(new));
	new.mat.det = mat3_det;
	new.mat.info = mat3_info;
	new.mat.is_invertable = 0;
	new.mat.minor = mat3_minor;
	new.mat.sub_mat = mat3_submat;
	new.mat.cofactor = mat3_cofactor;
	return (new);
}

t_matrix2	init_mat2(void)
{
	t_matrix2	new;

	ft_memset(&new, 0, sizeof(new));
	new.mat.minor = NULL;
	new.mat.det = mat2_det;
	new.mat.sub_mat = NULL;
	new.mat.cofactor = NULL;
	new.mat.info = mat2_info;
	new.mat.is_invertable = 0;
	return (new);
}

t_matrix4	matrix4_identity(void)
{
	t_matrix4	new;

	new = init_mat4();
	new.m[0][0] = 1;
	new.m[1][1] = 1;
	new.m[2][2] = 1;
	new.m[3][3] = 1;
	return (new);
}
