/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_ops_immutable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:38:37 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 17:05:18 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "matrix.h"

inline t_tuple	tuple_neg(t_tuple *tup_r)
{
	t_tuple	new;

	new.x = 0 - tup_r->x;
	new.y = 0 - tup_r->y;
	new.z = 0 - tup_r->z;
	new.w = 0 - tup_r->w;
	return (new);
}

inline t_tuple	tuple_add(t_tuple *t1_r, t_tuple *t2_r)
{
	t_tuple	new;

	new.x = t1_r->x + t2_r->x;
	new.y = t1_r->y + t2_r->y;
	new.z = t1_r->z + t2_r->z;
	new.w = t1_r->w + t2_r->w;
	return (new);
}

inline t_tuple	tuple_sub(t_tuple *t1_r, t_tuple *t2_r)
{
	t_tuple	new;

	new.x = t1_r->x - t2_r->x;
	new.y = t1_r->y - t2_r->y;
	new.z = t1_r->z - t2_r->z;
	new.w = t1_r->w - t2_r->w;
	return (new);
}

inline t_tuple	tuple_scale(t_tuple *t_r, float sc)
{
	t_tuple	new;

	new.x = t_r->x * sc;
	new.y = t_r->y * sc;
	new.z = t_r->z * sc;
	new.w = t_r->w * sc;
	return (new);
}

t_tuple	tuple_norm(t_tuple *t_r)
{
	t_tuple	new;
	float	magnitude;

	magnitude = tuple_magnitude(t_r);
	if (magnitude < EPSILON)
		return (vector(0, 0, 0));
	new.x = t_r->x / magnitude;
	new.y = t_r->y / magnitude;
	new.z = t_r->z / magnitude;
	new.w = t_r->w / magnitude;
	return (new);
}
