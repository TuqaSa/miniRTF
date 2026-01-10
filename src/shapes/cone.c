/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:09:51 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/07 16:57:22 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"
#include "libft.h"

t_shape	*init_cone(void)
{
	t_shape		*shape;
	t_cylinder	*cone_data;

	shape = init_shape();
	if (!shape)
		return (NULL);
	cone_data = ft_calloc(1, sizeof(t_cylinder));
	if (!cone_data)
	{
		free(shape);
		return (NULL);
	}
	cone_data->radius = 1.0;
	cone_data->closed = 1;
	cone_data->minimum = -1.0;
	cone_data->maximum = 1.0;
	shape->ops.info = NULL;
	shape->ops.normal = cone_normal;
	shape->ops.intersect = intersect_cone;
	shape->data = cone_data;
	return (shape);
}

int	add_cone(t_shape **root_r)
{
	t_shape	*new;
	t_shape	*curr;

	if (!root_r)
		return (-1);
	new = init_cone();
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

t_tuple	cone_normal(t_shape *shape, t_tuple object_point)
{
	t_tuple		object_normalv;
	t_cylinder	*cone;
	float		dist;
	float		radius_at_y;
	float		height;

	cone = (t_cylinder *)shape->data;
	dist = powf(object_point.x, 2) + powf(object_point.z, 2);
	height = cone->maximum - cone->minimum;
	if (dist < powf(fabsf(cone->maximum), 2)
		&& object_point.y >= cone->maximum - EPSILON)
		object_normalv = vector(0, 1, 0);
	else if (dist < powf(fabsf(cone->minimum), 2)
		&& object_point.y <= cone->minimum + EPSILON)
		object_normalv = vector(0, -1, 0);
	else
	{
		radius_at_y = (height - (object_point.y - cone->minimum)) / height;
		object_normalv = vector(object_point.x, radius_at_y, object_point.z);
	}
	return (object_normalv);
}
