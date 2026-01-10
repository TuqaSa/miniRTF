/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:09 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 19:55:54 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_fill_scenesetting(char **line_r, t_world **data_r,
	char **id_r, int *ct_r)
{
	if (!line_r || !(*line_r) || !data_r
		|| !(*data_r) || !id_r || !(*id_r))
		return (-1);
	if (!ft_strcmp((*id_r), "A"))
	{
		if (ft_fill_ambient_data(line_r, data_r, id_r, ct_r) < 0)
			return (-1);
	}
	if (!ft_strcmp((*id_r), "C"))
	{
		if (ft_parse_camera_data(line_r, data_r, id_r, ct_r) < 0)
			return (-1);
	}
	if (!ft_strcmp((*id_r), "L") || !ft_strcmp((*id_r), "l"))
	{
		if (ft_parse_light_data(line_r, data_r, id_r, ct_r) < 0)
			return (-1);
	}
	return (0);
}

static int	ft_fill_objs2(char **line_r, t_world **data_r,
	char **id_r, int *ct_r)
{
	if (!ft_strcmp((*id_r), "cn"))
	{
		if (ft_parse_cone_data(line_r, data_r, id_r, ct_r) < 0)
			return (-1);
	}
	if (!ft_strcmp((*id_r), "hy"))
	{
		if (ft_parse_hyperboloid_data(line_r, data_r, id_r, ct_r) < 0)
			return (-1);
	}
	return (0);
}

static int	ft_fill_objs(char **line_r, t_world **data_r,
	char **id_r, int *ct_r)
{
	if (!line_r || !(*line_r) || !data_r
		|| !(*data_r) || !id_r || !(*id_r))
		return (-1);
	if (!ft_strcmp((*id_r), "sp"))
	{
		if (ft_parse_sphere_data(line_r, data_r, id_r, ct_r) < 0)
			return (-1);
	}
	if (!ft_strcmp((*id_r), "pl"))
	{
		if (ft_parse_plane_data(line_r, data_r, id_r, ct_r) < 0)
			return (-1);
	}
	if (!ft_strcmp((*id_r), "cy"))
	{
		if (ft_parse_cylinder_data(line_r, data_r, id_r, ct_r) < 0)
			return (-1);
	}
	return (0);
}

int	ft_fill_info(char **line_r, t_world **data_r,
	char **id_r, int *ct_r)
{
	if (!line_r || !(*line_r) || !data_r
		|| !(*data_r) || !id_r || !(*id_r))
		return (-1);
	if (ft_fill_scenesetting(line_r, data_r, id_r, ct_r) < 0)
		return (-1);
	if (ft_fill_objs(line_r, data_r, id_r, ct_r) < 0)
		return (-1);
	if (ft_fill_objs2(line_r, data_r, id_r, ct_r) < 0)
		return (-1);
	return (0);
}
