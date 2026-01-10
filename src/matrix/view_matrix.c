/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:38:47 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/19 17:08:36 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "minirt.h"
#include "libft.h"

static void	orientation_matrix(t_matrix4 *mat4,
	t_tuple leftv, t_tuple viewupv, t_tuple forwardv)
{
	mat4->m[0][0] = leftv.x;
	mat4->m[0][1] = leftv.y;
	mat4->m[0][2] = leftv.z;
	mat4->m[1][0] = viewupv.x;
	mat4->m[1][1] = viewupv.y;
	mat4->m[1][2] = viewupv.z;
	mat4->m[2][0] = -forwardv.x;
	mat4->m[2][1] = -forwardv.y;
	mat4->m[2][2] = -forwardv.z;
}

t_matrix4	view_transform(t_tuple original_p, t_tuple to_p, t_tuple upv)
{
	t_tuple		leftv;
	t_tuple		viewupv;
	t_tuple		forwardv;
	t_matrix4	viewmat;
	t_matrix4	transmat;

	viewmat = matrix4_identity();
	transmat = translation(-original_p.x, -original_p.y, -original_p.z);
	ft_memset(&leftv, 0, sizeof(t_tuple));
	ft_memset(&viewupv, 0, sizeof(t_tuple));
	forwardv = tuple_sub(&to_p, &original_p);
	forwardv = tuple_norm(&forwardv);
	tuple_cross_product(&leftv, forwardv, tuple_norm(&upv));
	tuple_cross_product(&viewupv, leftv, forwardv);
	orientation_matrix(&viewmat, leftv, viewupv, forwardv);
	mat4_multiplication(&viewmat, viewmat, transmat);
	return (viewmat);
}
