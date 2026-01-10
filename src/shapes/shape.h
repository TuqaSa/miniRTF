/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:47 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 16:56:07 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "minirt.h"

t_shape		*init_shape(void);
void		del_shape(t_shape *shape);
void		del_shapes(t_shape **root_r);

t_shape		*init_sphere(void);
int			add_sphere(t_shape **shapes_r);
float		sphere_calculate_discriminant(t_sphere *sphere, t_ray ray);
void		calculate_t_values(t_ray ray, float discriminant, float *t1,
				float *t2);

t_shape		*init_plane(void);
int			add_plane(t_shape **root_r);
float		calculate_plane_t(t_shape *shape,
				t_ray ray, t_intersections *result_r);

t_shape		*init_cylinder(void);
int			add_cylinder(t_shape **root_r);
float		cylinder_calculate_discriminant(t_cylinder *cyl, t_ray ray);
void		intersect_cylinder_caps(t_shape *shape,
				t_ray ray, t_intersections *txs_r, int *count);
int			calculate_cylinder_body_t(float discr,
				t_shape *shape, t_intersections *result_r, t_ray ray);

t_shape		*init_cone(void);
int			add_cone(t_shape **root_r);
float		cone_calculate_discriminant(t_cylinder *cone, t_ray ray);
void		intersect_cone_caps(t_shape *shape,
				t_ray ray, t_intersections *txs_r, int *count);
int			calculate_cone_t(float discr,
				t_shape *shape, t_intersections *result_r, t_ray ray);
int			calculate_parallel_t(t_shape *shape,
				t_intersections *result_r, t_ray ray);

t_shape		*init_hyperboloid(void);
int			add_hyperboloid(t_shape **root_r);
float		hyperboloid_calculate_discriminant(t_hyperboloid *hyp, t_ray ray);
float		hyperboloid_calculate_parallel_t(t_hyperboloid *hyp, t_ray ray);
int			hyperboloid_calculate_t(t_hyperboloid *hyp,
				t_ray ray, t_intersections *result_r, t_shape *shape);
int			intersect_hyperboloid(t_shape *shape,
				t_ray *ray_r, t_intersections *result_r);

int			intersect(t_shape *base_shape,
				t_ray *ray_r, t_intersections *result_r);
int			intersect_cone(t_shape *shape,
				t_ray *ray_r, t_intersections *result_r);
int			intersect_plane(t_shape *shape,
				t_ray *ray_r, t_intersections *result_r);
int			intersect_sphere(t_shape *shape,
				t_ray *ray_r, t_intersections *result_r);
int			intersect_cylinder(t_shape *shape,
				t_ray *ray_r, t_intersections *result_r);
int			calculate_cylinderbdy_t(float discr, t_shape *shape,
				t_intersections *result_r, t_ray ray);

void		plane_info(t_shape *shape);
void		shape_info(t_shape *shape);
void		sphere_info(t_shape *shape);
void		cylinder_info(t_shape *shape);
void		material_info(t_material mat);

t_material	material(void);
void		set_transform(t_shape *shape, t_matrix4 transform);

t_tuple		cone_normal(t_shape *shape, t_tuple object_point);
t_tuple		plane_normal(t_shape *shape, t_tuple object_point);
t_tuple		normal_at(t_shape *base_shape, t_tuple world_point);
t_tuple		sphere_normal(t_shape *shape, t_tuple object_point);
t_tuple		cylinder_normal(t_shape *shape, t_tuple object_point);
t_tuple		hyperboloid_normal(t_shape *shape, t_tuple object_point);

#endif
