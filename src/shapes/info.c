/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:26 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/11 10:39:27 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "minirt.h"

void	material_info(t_material mat)
{
	color_info(&mat.color);
	printf("ambient ratio: %f\n", mat.ambient_ratio);
	printf("ambient color:\n");
	color_info(&mat.ambient_color);
	printf("diffuse: %f\n", mat.diffuse);
	printf("specular: %f\n", mat.specular);
	printf("shininess: %f\n", mat.shininess);
}

void	shape_info(t_shape *shape)
{
	if (shape->ops.info)
		shape->ops.info(shape);
	printf("shape id:%d\n", shape->id);
	printf("material info:\n");
	material_info(shape->material);
	printf("transformation matrix:\n");
	mat4_info(&shape->transform);
}

void	sphere_info(t_shape *shape)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)shape->data;
	printf("radius: %f\n", sphere->radius);
	printf("center:\n");
	tuple_info(&sphere->center);
}

void	plane_info(t_shape *shape)
{
	t_plane	*plane;

	plane = (t_plane *)shape->data;
	printf("point_coord:\n");
	tuple_info(&plane->point_coord);
	printf("normalv:\n");
	tuple_info(&plane->normalv);
}

void	cylinder_info(t_shape *shape)
{
	t_cylinder	*cyl;

	cyl = (t_cylinder *)shape->data;
	printf("radius: %f\n", cyl->radius);
	printf("minimum: %f\n", cyl->minimum);
	printf("maximum: %f\n", cyl->maximum);
	printf("(a:%f, b:%f, c:%f)\n", cyl->a, cyl->b, cyl->c);
}
