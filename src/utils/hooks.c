/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:40:02 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/26 21:09:46 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_world	*wrd;

	wrd = (t_world *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		wrd->should_exit = 1;
}

void	ft_hook(void *param)
{
	t_world	*wrd;
	mlx_t	*mlx;

	wrd = (t_world *)param;
	mlx = wrd->camera.canvas->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(mlx, MLX_KEY_Q))
		wrd->should_exit = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		wrd->camera.canvas->image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		wrd->camera.canvas->image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		wrd->camera.canvas->image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		wrd->camera.canvas->image->instances[0].x += 5;
}
