/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/12/01 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"
#include "libft.h"
#include <math.h>

t_shape	*init_hyperboloid(void)
{
	t_shape			*shape;
	t_hyperboloid	*hyp_data;

	shape = init_shape();
	if (!shape)
		return (NULL);
	hyp_data = ft_calloc(1, sizeof(t_hyperboloid));
	if (!hyp_data)
	{
		free(shape);
		return (NULL);
	}
	hyp_data->radius = 1.0;
	hyp_data->minimum = -1.0;
	hyp_data->maximum = 1.0;
	shape->ops.info = NULL;
	shape->ops.normal = hyperboloid_normal;
	shape->ops.intersect = intersect_hyperboloid;
	shape->data = hyp_data;
	return (shape);
}

int	add_hyperboloid(t_shape **root_r)
{
	t_shape	*new;
	t_shape	*curr;

	if (!root_r)
		return (-1);
	new = init_hyperboloid();
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

float	hyperboloid_calculate_discriminant(t_hyperboloid *hyp, t_ray ray)
{
	float	discr;

	hyp->a = powf(ray.direction.x, 2)
		- powf(ray.direction.y, 2)
		+ powf(ray.direction.z, 2);
	hyp->b = 2 * (ray.origin.x * ray.direction.x
			- ray.origin.y * ray.direction.y
			+ ray.origin.z * ray.direction.z);
	hyp->c = powf(ray.origin.x, 2)
		- powf(ray.origin.y, 2)
		+ powf(ray.origin.z, 2)
		- powf(hyp->radius, 2);
	discr = powf(hyp->b, 2) - (4 * hyp->a * hyp->c);
	return (discr);
}

float	hyperboloid_calculate_parallel_t(t_hyperboloid *hyp, t_ray ray)
{
	float	t;

	(void)ray;
	if (fabsf(hyp->b) < EPSILON)
		return (-1.0f);
	t = -hyp->c / (2 * hyp->b);
	return (t);
}

int	hyperboloid_calculate_t(t_hyperboloid *hyp,
	t_ray ray, t_intersections *result_r, t_shape *shape)
{
	float			t[2];
	float			y[2];
	int				i;
	int				count;
	float			discr;

	count = 0;
	discr = powf(hyp->b, 2) - (4 * hyp->a * hyp->c);
	if (discr < 0)
		return (0);
	t[0] = (-hyp->b - sqrtf(discr)) / (2 * hyp->a);
	t[1] = (-hyp->b + sqrtf(discr)) / (2 * hyp->a);
	i = 0;
	while (i < 2)
	{
		y[i] = ray.origin.y + t[i] * ray.direction.y;
		if (hyp->minimum < y[i] && y[i] < hyp->maximum)
		{
			result_r->xs[count] = intersection(t[i], shape);
			count++;
		}
		i++;
	}
	return (count);
}
