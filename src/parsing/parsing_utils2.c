/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:00:26 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/08 00:17:58 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_ctxs.h"
#include "parsing.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_allspc(char *line)
{
	size_t	i;

	i = 0;
	while ((i < ft_strlen(line) - 1) && line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_initvlline(t_vallinectx *ctx_r)
{
	ctx_r->j = 0;
	ctx_r->i = 0;
	ctx_r->id = malloc(3 * sizeof(char));
	if (!ctx_r->id)
	{
		ft_indicate_err("Error\nallocation failure\n", -1);
		return (-1);
	}
	return (0);
}
