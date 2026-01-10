/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:45:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/09 17:00:14 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	*init_canvas_mlx(int width, int height, const char *title)
{
	t_canvas	*canvas;

	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
		return (NULL);
	canvas->mlx = mlx_init(width, height, title, true);
	if (!canvas->mlx)
	{
		free(canvas);
		return (NULL);
	}
	canvas->image = mlx_new_image(canvas->mlx, width, height);
	if (!canvas->image)
	{
		mlx_close_window(canvas->mlx);
		mlx_terminate(canvas->mlx);
		free(canvas);
		return (NULL);
	}
	canvas->width = width;
	canvas->height = height;
	return (canvas);
}

t_canvas	*canvas_create(int width, int height, const char *title)
{
	t_canvas	*canvas;

	canvas = init_canvas_mlx(width, height, title);
	if (!canvas)
		return (NULL);
	canvas_clear(canvas, color(0, 0, 0));
	return (canvas);
}
