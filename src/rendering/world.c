/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:40:44 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/10 09:40:11 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shape.h"
#include "minirt.h"
#include <stdlib.h>
#include "parsing.h"
#include "ft_printf.h"

t_world	*ft_init_world(void)
{
	t_world	*world;

	world = ft_calloc(1, sizeof(t_world));
	world->shapes = NULL;
	world->lights = NULL;
	world->should_exit = 0;
	world->reusable_txs.xs = NULL;
	world->reusable_txs.count = 0;
	world->reusable_txs.capacity = 0;
	if (!world)
		return (NULL);
	return (world);
}

void	ft_del_world(t_world **world_r)
{
	if (!world_r || !*world_r)
		return ;
	if ((*world_r)->reusable_txs.xs)
	{
		free((*world_r)->reusable_txs.xs);
		(*world_r)->reusable_txs.xs = NULL;
	}
	if ((*world_r)->camera.canvas)
		canvas_destroy((*world_r)->camera.canvas);
	if ((*world_r)->lights)
		delete_lights(&((*world_r)->lights));
	if ((*world_r)->shapes)
		del_shapes(&((*world_r)->shapes));
	free(*world_r);
	*world_r = NULL;
	world_r = NULL;
}
