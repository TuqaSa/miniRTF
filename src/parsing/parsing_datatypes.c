/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_datatypes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:28:57 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/26 19:44:24 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

static	int	ft_tuplesegment(char **line_r, int *i_r, char **vlu_r)
{
	int	j;

	j = 0;
	if (ft_skip_spaces(line_r, i_r) < 0)
		return (ft_indicate_err("Error\nline ended before tuple value\n", -1));
	while ((*line_r)[*i_r] && (*line_r)[*i_r] != ','
		&& (*line_r)[*i_r] != ' ' && (*line_r)[*i_r] != '\t')
	{
		(*vlu_r)[j] = (*line_r)[*i_r];
		ft_increament(&j, i_r, NULL);
	}
	(*vlu_r)[j] = '\0';
	if ((*vlu_r)[0] == '\0')
		return (ft_indicate_err("Error\nmissing tuple value\n", -1));
	return (0);
}

static int	ft_tupleparse(char **line_r, int *i_r, float fvlu[3], char *vlu)
{
	int	iter;

	iter = 0;
	while (iter < 3)
	{
		if (ft_tuplesegment(line_r, i_r, &vlu) < 0)
			return (-1);
		(*i_r)++;
		if (iter == 2 && (*line_r)[*i_r -1] == ',')
			return (ft_indicate_err("Error\nextra coma in tuple value\n", -1));
		if (ft_atof(&vlu, &fvlu[iter]) < 0)
			return (-1);
		iter++;
	}
	return (0);
}

int	ft_findtuple(char **line_r, int *i_r, t_tuple *position_r)
{
	char	*vlu;
	float	fvlu[3];

	if (ft_skip_spaces(line_r, i_r) < 0)
		return (ft_indicate_err("Error\nline ended before tuple value\n", -1));
	vlu = malloc(12 * sizeof(char));
	if (!vlu)
		return (ft_indicate_err("Error\n failed memory allocation\n", -1));
	ft_memset(fvlu, 0, 3 * sizeof(int));
	if (ft_tupleparse(line_r, i_r, fvlu, vlu) < 0)
	{
		free(vlu);
		return (-1);
	}
	position_r->x = fvlu[0];
	position_r->y = fvlu[1];
	position_r->z = fvlu[2];
	free(vlu);
	return (0);
}

int	ft_findfloat(char **line_r, int *i_r, float *vlu_r)
{
	int		j;
	char	*ratioc;

	if (ft_skip_spaces(line_r, i_r) < 0)
		return (ft_indicate_err("Error\nline ended before float value\n", -1));
	ratioc = malloc((ft_strlen((*line_r)) + 1) * sizeof(char));
	if (!ratioc)
		return (ft_indicate_err("Error\n failed memory allocation\n", -1));
	j = 0;
	while ((*line_r)[*i_r])
	{
		if ((*line_r)[*i_r] == ' ' || (*line_r)[*i_r] == '\n'
			|| (*line_r)[*i_r] == '\t')
			break ;
		ratioc[j] = (*line_r)[*i_r];
		ft_increament(&j, i_r, NULL);
	}
	ratioc[j] = '\0';
	if (ft_atof(&ratioc, vlu_r) < 0)
	{
		free(ratioc);
		return (-1);
	}
	free(ratioc);
	return (0);
}
