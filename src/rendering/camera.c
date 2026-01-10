/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:54 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/09 17:02:56 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "matrix.h"
#include "libft.h"
#include <math.h>

static float	find_ratio(t_camera *camera)
{
	float	aspect;
	float	half_view;

	half_view = tan(camera->fov / 2);
	aspect = camera->hsize / camera->vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	return ((camera->half_width * 2) / camera->hsize);
}

static void	init_camera_transform(t_camera *camera, t_tuple originpoint,
				t_tuple viewpoint, t_tuple upv)
{
	t_tuple		origin_point;

	camera->transform = view_transform(originpoint, viewpoint, upv);
	camera->transform_inv = init_mat4();
	inverse_mat(&camera->transform, &camera->transform_inv);
	origin_point = point(0, 0, 0);
	camera->cached_origin = mat4_multi_tuple(camera->transform_inv,
			origin_point);
}

t_camera	init_camera(float fov, t_tuple originpoint,
				t_tuple viewpoint, t_tuple upv)
{
	t_camera	camera;

	ft_memset(&camera, 0, sizeof(t_camera));
	camera.hsize = WIDTH;
	camera.vsize = HEIGHT;
	camera.fov = fov;
	camera.pixel_size = find_ratio(&camera);
	init_camera_transform(&camera, originpoint, viewpoint, upv);
	return (camera);
}

static void	render_pixel(t_world *world, t_matrix4 invmat, int x, int y)
{
	t_ray		ray;
	t_color		ray_color;
	uint8_t		*pixel;
	t_color		tmp_color;

	ray = ray_for_pixel(world->camera, x, y, invmat);
	if (color_at(&world, &ray, &ray_color) == 0)
	{
		tmp_color.r = (int)(fmaxf(0.0f, fminf(1.0f, ray_color.r)) * 255);
		tmp_color.g = (int)(fmaxf(0.0f, fminf(1.0f, ray_color.g)) * 255);
		tmp_color.b = (int)(fmaxf(0.0f, fminf(1.0f, ray_color.b)) * 255);
		pixel = &world->camera.canvas->image->pixels[(y * WIDTH + x) * 4];
		pixel[0] = tmp_color.r;
		pixel[1] = tmp_color.g;
		pixel[2] = tmp_color.b;
		pixel[3] = 255;
	}
}

int	camera_render(void *param)
{
	t_world		*world;
	int			x;
	int			y;

	world = param;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixel(world, world->camera.transform_inv, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
