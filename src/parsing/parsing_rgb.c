/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:04:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 23:12:24 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_skip_spaces(char **line_r, int *i_r)
{
	size_t	len;

	len = ft_strlen(*line_r);
	if (*i_r < 0 || (size_t)(*i_r) >= len)
		return (-1);
	while ((*line_r)[*i_r] == ' ' || (*line_r)[*i_r] == '\t')
		(*i_r)++;
	return (0);
}

static int	ft_validc(char c)
{
	if (c != ',' && c != ' ' && c != '\n' && c != '\t')
		return (1);
	return (0);
}

static int	ft_rgb_segment(char **line_r, int *i_r, char **vlu_r)
{
	int	j;

	j = 0;
	if (ft_skip_spaces(line_r, i_r) < 0)
		return (ft_indicate_err("Error\nline ends before rgb value\n", -1));
	while ((*line_r)[*i_r] && ft_validc((*line_r)[*i_r]))
	{
		if (!ft_isdigit((*line_r)[*i_r]))
			return (ft_indicate_err("Error\nnonnumeric value in rgb\n", -1));
		if ((j == 0 && (*line_r)[*i_r] == '-' && (*line_r)[*i_r] == '+')
			|| ft_isdigit((*line_r)[*i_r]))
		{
			(*vlu_r)[j] = (*line_r)[*i_r];
			ft_increament(&j, i_r, NULL);
		}
	}
	(*vlu_r)[j] = '\0';
	if ((*vlu_r)[0] == '\0')
		return (ft_indicate_err("Error\nmissing rgb value\n", -1));
	return (0);
}

static int	ft_rgbparse(char **line_r, int *i_r, long ivlu[3], char *vlu)
{
	int	iter;

	iter = 0;
	while (iter < 3)
	{
		if (ft_rgb_segment(line_r, i_r, &vlu) < 0)
			return (-1);
		(*i_r)++;
		if (iter == 2 && (*line_r)[*i_r - 1] == ',')
			return (ft_indicate_err("Error\nextra comma in rgb value\n", -1));
		ivlu[iter] = ft_atoi((const char *) vlu);
		if (ivlu[iter] > 255 || ivlu[iter] < 0)
			return (ft_indicate_err("Error\nRGB value out of range\n", -1));
		iter++;
	}
	return (0);
}

int	ft_find_rgbvalues(char **line_r, int *i_r, t_color *color)
{
	char		*vlu;
	long		ivlu[3];

	if (ft_skip_spaces(line_r, i_r) < 0)
		return (ft_indicate_err("Error\nline ends before rgb value\n", -1));
	vlu = malloc(4 * sizeof(char));
	if (!vlu)
		return (ft_indicate_err("Error\n failed memory allocation\n", -1));
	while ((*line_r)[*i_r] == ' ')
		(*i_r)++;
	if (ft_rgbparse(line_r, i_r, ivlu, vlu) < 0)
	{
		free(vlu);
		return (-1);
	}
	color->r = (float)ivlu[0];
	color->g = (float)ivlu[1];
	color->b = (float)ivlu[2];
	if (vlu)
		free(vlu);
	return (0);
}
