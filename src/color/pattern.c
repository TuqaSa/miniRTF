/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:09:20 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 14:38:14 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "parsing.h"

t_pattern	checkers_pattern(t_color c1, t_color c2, int flag)
{
	t_pattern	ptn;

	ft_memset(&ptn, 0, sizeof(t_pattern));
	ptn.flag = flag;
	ft_fill_color(&(ptn.c1), c1);
	ft_fill_color(&(ptn.c2), c2);
	ptn.transform = matrix4_identity();
	return (ptn);
}

void	set_pattern_transform(t_pattern *ptn, t_matrix4 transform)
{
	ptn->transform = transform;
}

static t_color	pattern_at(t_pattern ptn, t_tuple point)
{
	int	x;
	int	y;
	int	z;
	int	sum;

	x = (int)floor(point.x + 0.1f);
	y = (int)floor(point.y + 0.1f);
	z = (int)floor(point.z + 0.1f);
	sum = x + y + z;
	if (sum % 2 == 0)
		return (ptn.c1);
	else
		return (ptn.c2);
}

t_color	checker_at_object(t_shape *object, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		pattern_point;
	t_matrix4	inv_obj;
	t_matrix4	inv_ptn;
	t_color		result;

	inv_obj = matrix4_identity();
	inv_ptn = matrix4_identity();
	mat4_inverse(&(object->transform), &inv_obj);
	mat4_inverse(&(object->material.pattern.transform), &inv_ptn);
	object_point = mat4_multi_tuple(inv_obj, world_point);
	pattern_point = mat4_multi_tuple(inv_ptn, object_point);
	result = pattern_at(object->material.pattern, pattern_point);
	return (result);
}
