/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 23:50:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/10/22 13:59:14 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	shearing(t_shear params)
{
	t_matrix4	matrix;

	matrix = matrix4_identity();
	matrix.m[0][1] = params.xy;
	matrix.m[0][2] = params.xz;
	matrix.m[1][0] = params.yx;
	matrix.m[1][2] = params.yz;
	matrix.m[2][0] = params.zx;
	matrix.m[2][1] = params.zy;
	return (matrix);
}
