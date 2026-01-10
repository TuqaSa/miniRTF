/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_ops_mutable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:38:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/22 12:08:36 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "matrix.h"

void	tuple_neg_set(t_tuple *tup)
{
	tup->x = 0 - tup->x;
	tup->y = 0 - tup->y;
	tup->z = 0 - tup->z;
	tup->w = 0 - tup->w;
}

void	tuple_add_set(t_tuple *t1, t_tuple *t2)
{
	t1->x = t1->x + t2->x;
	t1->y = t1->y + t2->y;
	t1->z = t1->z + t2->z;
	t1->w = t1->w + t2->w;
}

void	tuple_sub_set(t_tuple *t1, t_tuple t2)
{
	t1->p[0] = t1->p[0] - t2.p[0];
	t1->p[1] = t1->p[1] - t2.p[1];
	t1->p[2] = t1->p[2] - t2.p[2];
	t1->p[3] = t1->p[3] - t2.p[3];
}

void	tuple_scale_set(t_tuple *t, float sc)
{
	t->p[0] = t->p[0] * sc;
	t->p[1] = t->p[1] * sc;
	t->p[2] = t->p[2] * sc;
	t->p[3] = t->p[3] * sc;
}

void	tuple_norm_set(t_tuple *t_r)
{
	t_tuple	new;
	float	magnitude;

	magnitude = tuple_magnitude(t_r);
	if (magnitude < EPSILON)
		return (vector(0, 0, 0));
	t_r->x = t_r->x / magnitude;
	t_r->y = t_r->y / magnitude;
	t_r->z = t_r->z / magnitude;
	t_r->w = t_r->w / magnitude;
	return (new);
}
