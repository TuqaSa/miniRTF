/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:40:28 by tsaeed            #+#    #+#             */
/*   Updated: 2025/11/26 01:31:32 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shape.h"
#include "libft.h"

t_shape	*init_sphere(void)
{
	t_sphere	*sphere_data;
	t_shape		*shape;

	shape = init_shape();
	if (!shape)
		return (NULL);
	sphere_data = ft_calloc(1, sizeof(t_sphere));
	if (!sphere_data)
	{
		free(shape);
		return (NULL);
	}
	sphere_data->center = point(0, 0, 0);
	sphere_data->radius = 1.0;
	shape->ops.info = sphere_info;
	shape->ops.normal = sphere_normal;
	shape->ops.intersect = intersect_sphere;
	shape->data = sphere_data;
	return (shape);
}

int	add_sphere(t_shape **root_r)
{
	t_shape	*new;
	t_shape	*curr;

	if (!root_r)
		return (-1);
	new = init_sphere();
	if (!new)
		return (-1);
	if ((*root_r) == NULL)
	{
		(*root_r) = new;
		return (0);
	}
	curr = (*root_r);
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (0);
}

float	sphere_calculate_discriminant(t_sphere *sphere, t_ray ray)
{
	t_tuple	sphere_to_ray;
	float	a;
	float	b;
	float	c;

	sphere_to_ray = tuple_sub(&(ray.origin), &(sphere->center));
	a = tuple_dot_product(&(ray.direction), &(ray.direction));
	b = 2 * tuple_dot_product(&(ray.direction), &sphere_to_ray);
	c = tuple_dot_product(&sphere_to_ray, &sphere_to_ray)
		- (sphere->radius * sphere->radius);
	return (b * b - 4 * a * c);
}

void	calculate_t_values(t_ray ray, float discriminant, float *t1,
		float *t2)
{
	t_tuple	sphere_to_ray;
	float	a;
	float	b;
	float	sqrt_discriminant;
	t_tuple	origin_point;

	origin_point = point(0, 0, 0);
	sphere_to_ray = tuple_sub(&(ray.origin), &origin_point);
	a = tuple_dot_product(&(ray.direction), &(ray.direction));
	b = 2 * tuple_dot_product(&(ray.direction), &sphere_to_ray);
	sqrt_discriminant = sqrt(discriminant);
	*t1 = (-b - sqrt_discriminant) / (2 * a);
	*t2 = (-b + sqrt_discriminant) / (2 * a);
}
