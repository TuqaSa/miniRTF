/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:45:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/09 16:58:23 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	canvas_destroy(t_canvas *canvas)
{
	if (!canvas)
		return ;
	if (canvas->image)
		mlx_delete_image(canvas->mlx, canvas->image);
	if (canvas->mlx)
	{
		mlx_close_window(canvas->mlx);
		mlx_terminate(canvas->mlx);
	}
	free(canvas);
}
