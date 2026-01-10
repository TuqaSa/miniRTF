/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:50:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/11/11 10:38:25 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

t_matrix4	translation(float x, float y, float z)
{
	t_matrix4	matrix;

	matrix = matrix4_identity();
	matrix.m[0][3] = x;
	matrix.m[1][3] = y;
	matrix.m[2][3] = z;
	return (matrix);
}

t_matrix4	scaling(float x, float y, float z)
{
	t_matrix4	matrix;

	matrix = init_mat4();
	matrix.m[0][0] = x;
	matrix.m[1][1] = y;
	matrix.m[2][2] = z;
	matrix.m[3][3] = 1.0;
	return (matrix);
}

t_matrix4	rotation_x(float radians)
{
	t_matrix4	matrix;
	float		cos_r;
	float		sin_r;

	cos_r = cos(radians);
	sin_r = sin(radians);
	matrix = matrix4_identity();
	matrix.m[1][1] = cos_r;
	matrix.m[1][2] = -sin_r;
	matrix.m[2][1] = sin_r;
	matrix.m[2][2] = cos_r;
	return (matrix);
}

t_matrix4	rotation_y(float radians)
{
	t_matrix4	matrix;
	float		cos_r;
	float		sin_r;

	cos_r = cos(radians);
	sin_r = sin(radians);
	matrix = matrix4_identity();
	matrix.m[0][0] = cos_r;
	matrix.m[0][2] = sin_r;
	matrix.m[2][0] = -sin_r;
	matrix.m[2][2] = cos_r;
	return (matrix);
}

t_matrix4	rotation_z(float radians)
{
	t_matrix4	matrix;
	float		cos_r;
	float		sin_r;

	cos_r = cos(radians);
	sin_r = sin(radians);
	matrix = matrix4_identity();
	matrix.m[0][0] = cos_r;
	matrix.m[0][1] = -sin_r;
	matrix.m[1][0] = sin_r;
	matrix.m[1][1] = cos_r;
	return (matrix);
}
