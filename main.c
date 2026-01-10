/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:38:20 by tsaeed            #+#    #+#             */
/*   Updated: 2025/11/26 21:19:20 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "libft.h"
#include "shape.h"
#include "minirt.h"
#include "parsing.h"

static int	validate_scene(t_world *world)
{
	if (world->camera.hsize == 0 || world->camera.vsize == 0)
	{
		ft_del_world(&world);
		return (ft_indicate_err("Camera not defined in the scene\n", 7));
	}
	if (!world->lights)
	{
		ft_del_world(&world);
		return (ft_indicate_err("Light source not defined\n", 6));
	}
	if (!world->shapes)
	{
		ft_del_world(&world);
		return (ft_indicate_err("No shapes defined in the scene\n", 9));
	}
	return (0);
}

static int	init_canvas_and_render(t_world *world)
{
	world->camera.canvas = canvas_create(WIDTH, HEIGHT, "miniRT");
	if (!world->camera.canvas)
	{
		ft_del_world(&world);
		return (ft_indicate_err("failed_to_allocate canvas\n", 8));
	}
	if (camera_render(world) < 0)
	{
		ft_del_world(&world);
		return (1);
	}
	return (0);
}

static int	display_scene(t_world *world)
{
	if (mlx_image_to_window(world->camera.canvas->mlx,
			world->camera.canvas->image, 0, 0) == -1)
	{
		ft_del_world(&world);
		return (ft_indicate_err("Error\nFailed to display canvas\n", 1));
	}
	mlx_key_hook(world->camera.canvas->mlx, key_hook, world);
	mlx_loop_hook(world->camera.canvas->mlx, canvas_render, world);
	mlx_loop(world->camera.canvas->mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_world	*world;

	if (argc != 2)
		return (ft_indicate_err("Error\nminiRT takes one .rt file\n", 1));
	world = ft_init_world();
	if (ft_parse(&world, &argv[1]) < 0)
	{
		ft_del_world(&world);
		return (1);
	}
	if (validate_scene(world) < 0)
		return (1);
	if (init_canvas_and_render(world) < 0)
		return (1);
	if (display_scene(world) < 0)
		return (1);
	ft_del_world(&world);
	return (0);
}
