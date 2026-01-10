/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:38:55 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 19:56:26 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_check_extention(char **file_name)
{
	int	i;
	int	len;
	int	status;

	if (!file_name || !*file_name)
		return (-1);
	i = 0;
	status = 0;
	len = ft_strlen(*file_name);
	while (i < len)
	{
		if ((*file_name)[i] == '.')
		{
			if (ft_strcmp((*file_name) + i, ".rt"))
				return (ft_indicate_err(
						"Error\ninvalid extension, only .rt allowed\n", -1));
			else
				status = 1;
		}
		i++;
	}
	if (status == 0)
		return (ft_indicate_err(
				"Error\ninvalid extension, only .rt allowed\n", -1));
	return (0);
}

int	ft_valid_info(char **line_r, char **id_r, int *ct_r)
{
	int	i;

	if (!id_r || !(*id_r))
		return (ft_indicate_err("Error\n", -1));
	i = ft_strlen(*id_r) + (*ct_r);
	while ((*line_r)[i])
	{
		if ((i - ft_strlen(*id_r)) == 0
			&& ((*line_r)[i] != ' ' && (*line_r)[i] != '\t'))
			return (ft_indicate_err(
					"Error\ninvalid syntax, expect space after id\n", -1));
		if (!ft_valid_char((*line_r)[i]))
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_validate_line(char **line_r, t_valid *valid_r, int *ct_r)
{
	char	*id;

	if (!line_r || !(*line_r))
	{
		ft_indicate_err("Error\nline is emtpy\n", -1);
		return (NULL);
	}
	id = ft_validate_idlen(line_r, ct_r);
	if (!id)
		return (NULL);
	if (ft_fill_id(valid_r, &id) < 0)
	{
		free(id);
		return (NULL);
	}
	if (ft_valid_info(line_r, &id, ct_r) < 0)
	{
		free(id);
		return (NULL);
	}
	return (id);
}
