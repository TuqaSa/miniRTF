/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:45:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/09 17:00:19 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	canvas_write_pixel(t_canvas *canvas, int x, int y, t_color color)
{
	uint32_t	rgba;

	if (!canvas || x < 0 || x >= canvas->width || y < 0
		|| y >= canvas->height)
		return ;
	rgba = color_to_rgba(color);
	mlx_put_pixel(canvas->image, x, y, rgba);
}
