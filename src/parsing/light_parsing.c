/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:12 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 19:47:11 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	add_light(t_light **root_r,
	t_tuple position, t_color intensity, float brightness)
{
	t_light	*new;
	t_light	*curr;

	if (!root_r)
		return (-1);
	new = point_light(position, intensity, brightness);
	if (!new)
		return (-1);
	if ((*root_r) == NULL)
	{
		(*root_r) = new;
		return (0);
	}
	curr = *root_r;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (0);
}

void	delete_lights(t_light **root_r)
{
	t_light	*curr;
	t_light	*next;

	if (!root_r || !*root_r)
		return ;
	curr = *root_r;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*root_r = NULL;
	root_r = NULL;
}

/*
◦ Light:
L -40.0,50.0,0.0   0.6   10,0,255
∗ identifier: L
∗ x, y, z coordinates of the light point: -40.0,50.0,0.0
∗ the light brightness ratio in the range [0.0,1.0]: 0.6
∗ (unused in mandatory part) R, G, B colors in the range [0-255]: 10, 0,
255
*/

int	ft_parse_light_data(char **line_r, t_world **data_r, char **id_r, int *ct_r)
{
	int		i;
	float	brightness;
	t_tuple	position;
	t_color	intensity;

	brightness = 0;
	i = ft_strlen(*id_r) + (*ct_r);
	position = point(0, 0, 0);
	intensity = color(1, 1, 1);
	if (ft_findtuple(line_r, &i, &position) < 0)
		return (-1);
	if (ft_findfloat(line_r, &i, &brightness) < 0)
		return (-1);
	if (brightness < 0.0 || brightness > 1.0)
		return (ft_indicate_err("Error\nbrightness value out of range\n", -1));
	if (ft_find_rgbvalues(line_r, &i, &intensity) < 0)
		return (-1);
	if (ft_check_endof_line(line_r, &i) == 0)
		return (ft_indicate_err(
				"Error\nextraneous characters after light data\n", -1));
	if (add_light(&((*data_r)->lights), position, intensity, brightness) < 0)
		return (-1);
	return (0);
}

int	ft_fill_ambient_data(char **line_r, t_world **data_r,
	char **id_r, int *ct_r)
{
	int		i;
	float	ratio;
	t_color	a_color;

	i = ft_strlen(*id_r) + (*ct_r);
	ratio = 0;
	a_color = color(1, 1, 1);
	if (ft_findfloat(line_r, &i, &ratio) < 0)
		return (-1);
	if (ratio < 0.0 || ratio > 1.0)
		return (ft_indicate_err("Error\nbrightness value out of range\n", -1));
	if (ft_find_rgbvalues(line_r, &i, &a_color) < 0)
		return (-1);
	if (ft_check_endof_line(line_r, &i) == 0)
		return (ft_indicate_err(
				"Error\nextraneous characters after ambient light data\n", -1));
	(*data_r)->ambient_ratio = ratio;
	ft_fill_color(&((*data_r)->ambient_color), a_color);
	return (0);
}
