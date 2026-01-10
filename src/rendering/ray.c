/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:42:11 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/09 16:56:43 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "data_ctxs.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	position(t_ray ray, float t)
{
	t_tuple	scaled_directon;

	scaled_directon = tuple_scale(&ray.direction, t);
	scaled_directon = tuple_add(&ray.origin, &scaled_directon);
	return (scaled_directon);
}

t_ray	transform(t_ray ray, t_matrix4 matrix)
{
	t_ray	transformed_ray;

	transformed_ray.origin = mat4_multi_tuple(matrix, ray.origin);
	transformed_ray.direction = mat4_multi_tuple(matrix, ray.direction);
	return (transformed_ray);
}

t_rayctx	init_rctx(t_camera camera, int px, int py)
{
	t_rayctx	rctx;

	ft_memset(&rctx, 0, sizeof(t_rayctx));
	rctx.xoffset = (px + 0.5) * camera.pixel_size;
	rctx.yoffset = (py + 0.5) * camera.pixel_size;
	rctx.world_x = camera.half_width - rctx.xoffset;
	rctx.world_y = camera.half_height - rctx.yoffset;
	return (rctx);
}

t_ray	ray_for_pixel(t_camera camera, int px, int py, t_matrix4 invmat)
{
	t_ray		ray;
	t_tuple		tmpp;
	t_rayctx	rctx;

	rctx = init_rctx(camera, px, py);
	tmpp = point(rctx.world_x, rctx.world_y, -1);
	rctx.pixel = mat4_multi_tuple(invmat, tmpp);
	rctx.origin = camera.cached_origin;
	tmpp = tuple_sub(&rctx.pixel, &rctx.origin);
	rctx.direction = tuple_norm(&tmpp);
	ray = create_ray(rctx.origin, rctx.direction);
	return (ray);
}
