/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:36:18 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 17:05:22 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	addcolor(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r + b.r;
	c.g = a.g + b.g;
	c.b = a.b + b.b;
	return (c);
}

t_color	subcolor(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r - b.r;
	c.g = a.g - b.g;
	c.b = a.b - b.b;
	return (c);
}

t_color	multcolor(t_color a, float b)
{
	t_color	c;

	c.r = a.r * b;
	c.g = a.g * b;
	c.b = a.b * b;
	return (c);
}

t_color	hadamard(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r * b.r;
	c.g = a.g * b.g;
	c.b = a.b * b.b;
	return (c);
}

t_tuple	reflect(t_tuple *incident_r, t_tuple *normal_r)
{
	t_tuple	reflected;
	float	dot_product;
	t_tuple	scale_product;

	dot_product = tuple_dot_product(incident_r, normal_r);
	scale_product = tuple_scale(normal_r, 2.0f * dot_product);
	reflected = tuple_sub(incident_r, &scale_product);
	return (reflected);
}
