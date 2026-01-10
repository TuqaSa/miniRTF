/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:06:19 by tsaeed            #+#    #+#             */
/*   Updated: 2025/12/07 16:50:33 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "libft.h"
//#include "matrix.h"

t_shape	*init_cylinder(void)
{
	t_shape		*shape;
	t_cylinder	*cyl_data;

	shape = init_shape();
	if (!shape)
		return (NULL);
	cyl_data = ft_calloc(1, sizeof(t_cylinder));
	if (!cyl_data)
	{
		free(shape);
		return (NULL);
	}
	cyl_data->radius = 1.0;
	cyl_data->closed = 1;
	cyl_data->minimum = -INFINITY;
	cyl_data->maximum = INFINITY;
	shape->ops.info = cylinder_info;
	shape->ops.normal = cylinder_normal;
	shape->ops.intersect = intersect_cylinder;
	shape->data = cyl_data;
	return (shape);
}

int	add_cylinder(t_shape **root_r)
{
	t_shape	*new;
	t_shape	*curr;

	if (!root_r)
		return (-1);
	new = init_cylinder();
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
