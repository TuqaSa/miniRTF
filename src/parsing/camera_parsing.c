/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:03:10 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 23:03:17 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
Camera:
C -50.0,0,20 0,0,1 70
∗ identifier: C
∗ x, y, z coordinates of the viewpoint: -50.0,0,20
∗ 3D normalized orientation vector, in the range [-1,1] for each x, y, z axis:
0.0,0.0,1.0
∗ FOV: Horizontal field of view in degrees in the range [0,180]: 70
*/

static int	ft_orientv_inrange(t_tuple orientv)
{
	if (orientv.x < -1 || orientv.x > 1 || orientv.y < -1
		|| orientv.y > 1 || orientv.z < -1 || orientv.z > 1)
		return (ft_indicate_err(
				"Error\norientation vector out of range [-1,1]\n", -1));
	return (0);
}

static int	ft_validate_camera(t_tuple orientv, float fov)
{
	float	magnitude;

	magnitude = tuple_magnitude(&orientv);
	if (fabsf(magnitude) < EPSILON)
		return (ft_indicate_err("Error\nZero orientation vector\n", -1));
	if (ft_orientv_inrange(orientv) < 0)
		return (-1);
	if (fabsf(magnitude - 1) > EPSILON)
		return (ft_indicate_err(
				"Error\norientation vector is no normalized\n", -1));
	if (fov < 0 || fov > 180)
		return (ft_indicate_err("Error\nFOV out of range (0, 180)\n", -1));
	return (0);
}

static void	ft_fill_camera(t_tuple position,
		t_tuple orientv, float fov, t_world **data_r)
{
	t_camera	camera;
	t_tuple		viewpoint;
	t_tuple		upv;
	float		fovrad;

	viewpoint = tuple_add(&position, &orientv);
	upv = vector(0, 1, 0);
	if (fabsf(tuple_dot_product(&orientv, &upv)) > 0.999f)
		upv = vector(0, 0, 1);
	fovrad = (fov * M_PI) / 180.0f;
	camera = init_camera(fovrad, position, viewpoint, upv);
	(*data_r)->camera = camera;
}

int	ft_parse_camera_data(char **line_r, t_world **data_r,
	char **id_r, int *ct_r)
{
	int		i;
	t_tuple	position;
	t_tuple	orientv;
	float	fov;

	i = ft_strlen(*id_r) + (*ct_r);
	fov = 0;
	position = point(0, 0, 0);
	orientv = vector(0, 0, 0);
	if (ft_findtuple(line_r, &i, &position) < 0)
		return (-1);
	if (ft_findtuple(line_r, &i, &orientv) < 0)
		return (-1);
	if (ft_findfloat(line_r, &i, &fov) < 0)
		return (-1);
	if (ft_validate_camera(orientv, fov) < 0)
		return (-1);
	if (!ft_check_endof_line(line_r, &i))
		return (ft_indicate_err(
				"Error\nextraneous characters after camera data\n", -1));
	ft_fill_camera(position, orientv, fov, data_r);
	return (0);
}
