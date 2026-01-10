/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:51:20 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/10 09:51:53 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "MLX42/include/MLX42/MLX42.h"
# include "color.h"
# include "matrix.h"
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 700
# define HEIGHT 700

typedef struct s_canvas
{
	int							width;
	int							height;
	mlx_t						*mlx;
	mlx_image_t					*image;
}								t_canvas;

typedef struct s_ray
{
	t_tuple						origin;
	t_tuple						direction;
}								t_ray;

typedef struct s_color			t_color;

typedef struct s_pattern
{
	int							flag;
	t_color						c1;
	t_color						c2;
	t_matrix4					transform;
}								t_pattern;

/* The t_material struct encapsulates:
 * - The surface color.
 * - ambient, value between 0 and 1
 * - diffuse, value between 0 and 1
 * - specular, value between 0 and 1
 * - shininess,
	values between 10 (very large highlight) and 200 (very small hightlight)
 */

typedef struct s_material
{
	t_pattern					pattern;
	t_color						color;
	float						ambient_ratio;
	t_color						ambient_color;
	float						diffuse;
	float						specular;
	float						shininess;
}								t_material;

typedef struct s_intersections	t_intersections;
typedef struct s_shape			t_shape;

typedef struct s_sphape_ops
{
	int							(*intersect)(t_shape *base_shape, t_ray *ray,
			t_intersections *xs);
	t_tuple						(*normal)(t_shape	*base_shape,
		t_tuple world_point);
	void						(*info)(t_shape *base_shape);
}								t_shape_ops;

typedef struct s_cylinder
{
	float						radius;
	float						minimum;
	float						maximum;
	int							closed;
	float						a;
	float						b;
	float						c;
}								t_cylinder;

typedef struct s_sphere
{
	t_tuple						center;
	float						radius;
}								t_sphere;

typedef struct s_plane
{
	t_tuple						point_coord;
	t_tuple						normalv;
}								t_plane;

typedef struct s_hyperboloid
{
	float						radius;
	float						minimum;
	float						maximum;
	float						a;
	float						b;
	float						c;
}								t_hyperboloid;

typedef struct s_shape
{
	t_shape_ops					ops;
	void						*data;
	t_matrix4					transform;
	t_matrix4					transform_inv;
	t_matrix4					transpose_inv;
	int							inv_computed;
	t_material					material;
	t_ray						saved_ray;
	struct s_shape				*next;
	int							id;
}								t_shape;

typedef struct s_intersection
{
	float						t;
	t_shape						*object;
}								t_intersection;

typedef struct s_intersections
{
	int							count;
	int							capacity;
	t_intersection				*xs;
}								t_intersections;

typedef struct s_light
{
	float						brightness;
	t_tuple						position;
	t_color						intensity;
	struct s_light				*next;
}								t_light;

typedef struct s_camera
{
	float						fov;
	int							hsize;
	int							vsize;
	t_matrix4					transform;
	t_matrix4					transform_inv;
	t_tuple						cached_origin;
	float						pixel_size;
	float						half_width;
	float						half_height;
	t_canvas					*canvas;
}								t_camera;

typedef struct s_world
{
	float						ambient_ratio;
	t_color						ambient_color;
	t_camera					camera;
	t_light						*lights;
	t_shape						*shapes;
	int							should_exit;
	t_intersections				reusable_txs;
}								t_world;

typedef struct s_precomp
{
	float						t;
	int							inside;
	t_shape						*object;
	t_tuple						eyev;
	t_tuple						point;
	t_tuple						normalv;
	t_tuple						over_point;
}								t_precomp;

t_world							*ft_init_world(void);
void							ft_del_world(t_world **world_r);
int								ft_intersect_world(t_world **world_r,
									t_ray *ray_r, t_intersections *totxs_r);

t_intersection					*init_xs(int size);
t_intersection					*realloc_xs(t_intersection *xs, int newsize,
									int oldsize);
void							sort_intersections(t_intersections *result_r);
void							txs_info(t_intersections txs, int print_shape);
void							light_info(t_light *light);

t_camera						init_camera(float fov, t_tuple originpoint,
									t_tuple viewpoint, t_tuple orientv);
int								camera_render(void *param);

void							key_hook(mlx_key_data_t keydata, void *param);
void							ft_hook(void *param);

t_precomp						prepare_computations(t_ray *ray_r,
									t_intersection *xs_r);
void							precomp_info(t_precomp *comp_r);
t_color							shade_hit(t_world **world_r, t_precomp *comp_r);
int								color_at(t_world **world_r, t_ray *ray,
									t_color *shade_r);

// Canvas operations
t_canvas						*canvas_create(int width, int height,
									const char *title);
void							canvas_destroy(t_canvas *canvas);
void							canvas_write_pixel(t_canvas *canvas, int x,
									int y, t_color color);
uint32_t						color_to_rgba(t_color color);
void							canvas_render(void *param);
void							canvas_clear(t_canvas *canvas, t_color color);
t_canvas						*init_canvas_mlx(int width, int height,
									const char *title);

// Ray operations
t_tuple							position(t_ray ray, float t);
t_ray							transform(t_ray ray, t_matrix4 matrix);
t_ray							create_ray(t_tuple origin, t_tuple direction);
void							ray_info(t_ray ray);
t_ray							ray_for_pixel(t_camera camera, int px, int py,
									t_matrix4 invmat);

// Intersection operations
t_intersection					intersection(float t, void *object);
t_intersections					intersections(int count, ...);
int								hit(t_intersections xs, t_intersection *result);

// Light operations
t_light							*point_light(t_tuple position,
									t_color intensity, float brightness);

// Lighting operations
t_color							lighting(t_light *light, t_precomp *comp_r,
									int shadow);
t_color							diffuse_cal(t_color effective_color,
									float diffuse_factor, t_tuple lightv,
									t_tuple normalv);
t_color							specular_cal(t_light **light_r,
									t_precomp *comp_r, t_tuple lightv);
int								is_shadowed(t_world *world, t_tuple point,
									t_light *light);

// std_utils
int								ft_indicate_err(char *err_msg, int status);
int								ft_clean(char *fmt, ...);

t_pattern						checkers_pattern(t_color c1, t_color c2,
									int flag);
void							set_pattern_transform(t_pattern *ptn,
									t_matrix4 transform);
t_color							checker_at_object(t_shape *object,
									t_tuple world_point);

#endif