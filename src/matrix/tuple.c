/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:38:44 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 16:10:50 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "libft.h"

float	tuple_magnitude(t_tuple *t_r)
{
	float	mag;

	mag = sqrtf(powf(t_r->x, 2) + powf(t_r->y, 2) + powf(t_r->z, 2));
	return (mag);
}

t_tuple	point(float x, float y, float z)
{
	t_tuple	new;

	ft_memset(&new, 0, sizeof(new));
	new.x = x;
	new.y = y;
	new.z = z;
	new.w = 1;
	return (new);
}

t_tuple	vector(float x, float y, float z)
{
	t_tuple	new;

	ft_memset(&new, 0, sizeof(new));
	new.x = x;
	new.y = y;
	new.z = z;
	new.w = 0;
	return (new);
}
