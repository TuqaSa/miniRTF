/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:12 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/11 10:37:13 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float	ft_abs(float a)
{
	if (a > 0)
		return (a);
	return (-a);
}

int	ft_float_equal(float a, float b)
{
	if (ft_abs(a - b) < EPSILON)
		return (1);
	return (0);
}

void	swap(float *a, float *b)
{
	float	tmp;

	if (*a > *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
	return ;
}
