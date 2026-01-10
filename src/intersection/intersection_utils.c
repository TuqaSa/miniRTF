/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:36:39 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/11 10:36:40 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "shape.h"

t_intersection	*init_xs(int size)
{
	t_intersection	*newxs;

	newxs = ft_calloc(size, sizeof(t_intersection));
	if (!newxs)
		return (NULL);
	return (newxs);
}

t_intersection	*realloc_xs(t_intersection *xs, int newsize, int oldsize)
{
	int				i;
	t_intersection	*new;

	new = init_xs(newsize);
	if (!new)
		return (NULL);
	i = 0;
	while (i < oldsize)
	{
		new[i] = xs[i];
		i++;
	}
	return (new);
}

void	txs_info(t_intersections txs, int print_shape)
{
	int				i;
	t_intersection	*xs;

	i = 0;
	xs = txs.xs;
	printf("txs count = %d\n", txs.count);
	while (i < txs.count)
	{
		printf("xs[%d].t = %f\n", i, xs[i].t);
		if (print_shape)
		{
			printf("attached shape:\n");
			shape_info(xs[i].object);
		}
		i++;
	}
}
