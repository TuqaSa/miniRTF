/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:45:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/09 17:00:13 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

uint32_t	color_to_rgba(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(fmaxf(0.0f, fminf(1.0f, color.r)) * 255);
	g = (int)(fmaxf(0.0f, fminf(1.0f, color.g)) * 255);
	b = (int)(fmaxf(0.0f, fminf(1.0f, color.b)) * 255);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

void	canvas_render(void *param)
{
	t_world		*world;

	world = (t_world *)param;
	if (!world || !world->camera.canvas)
		return ;
	if (world->should_exit)
	{
		ft_del_world(&world);
		exit(0);
	}
}

void	canvas_clear(t_canvas *canvas, t_color clear_color)
{
	uint32_t	x;
	uint32_t	clear_rgb;
	uint32_t	*pixels;
	uint32_t	total;

	if (!canvas)
		return ;
	x = 0;
	clear_rgb = color_to_rgba(clear_color);
	pixels = (uint32_t *)canvas->image->pixels;
	total = WIDTH * HEIGHT;
	while (x < total)
	{
		pixels[x] = clear_rgb;
		x++;
	}
}
