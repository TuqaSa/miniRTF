/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:18 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 23:13:55 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_ctxs.h"
#include "get_next_line.h"
#include "parsing.h"
#include "stdio.h"

static int	ft_full_scene_validity(t_valid *valid)
{
	if (valid->a[1] != 1)
		return (ft_indicate_err("Error\nAmbient light must be declared once\n",
				-1));
	if (valid->c[1] != 1)
		return (ft_indicate_err("Error\nCamera must be declared once\n", -1));
	if (valid->l[1] < 1)
		return (ft_indicate_err("Error\nAt least one light must be declared\n",
				-1));
	if (valid->sp[1] < 1 && valid->pl[1] < 1 && valid->cy[1] < 1
		&& valid->cn[1] < 1 && valid->hy[1] < 1)
		return (ft_indicate_err("Error\nAt least one shape must be declared\n",
				-1));
	return (0);
}

static int	ft_readline(t_world **data_r, t_valid *valid, char **line_r)
{
	char	*id;
	int		ct;

	if ((*line_r)[0] == '\n' || (*line_r)[0] == '\0' || ft_allspc(*line_r))
		return (1);
	ct = 0;
	id = ft_validate_line(line_r, valid, &ct);
	if (!id)
	{
		get_next_line(-1);
		return (-1);
	}
	if (ft_fill_info(line_r, data_r, &id, &ct) < 0)
	{
		get_next_line(-1);
		ft_clean("$s", id);
		return (-1);
	}
	ft_clean("$s", id);
	return (0);
}

static int	ft_read_file(t_world **data_r, char **file_name, t_valid *valid)
{
	t_linectx	ctx;

	ctx.fd = open(*file_name, O_RDONLY);
	if (ctx.fd == -1)
		return (ft_indicate_err("Error\ncannot open file\n", -1));
	ctx.line = get_next_line(ctx.fd);
	if (!ctx.line)
	{
		close(ctx.fd);
		return (ft_indicate_err("Error/ cannot read line\n", -1));
	}
	while (ctx.line != NULL)
	{
		ctx.status = ft_readline(data_r, valid, &ctx.line);
		if (ctx.status == -1)
		{
			ft_clean("$f$s", ctx.fd, ctx.line);
			return (-1);
		}
		free(ctx.line);
		ctx.line = get_next_line(ctx.fd);
	}
	get_next_line(-1);
	close(ctx.fd);
	return (0);
}

int	ft_parse(t_world **data_r, char **file_name_r)
{
	t_valid	valid;

	ft_bzero(&valid, sizeof(valid));
	if (!file_name_r || !file_name_r || !data_r)
		return (-1);
	if (ft_check_extention(file_name_r) < 0)
		return (-1);
	if (ft_read_file(data_r, file_name_r, &valid) < 0)
		return (-1);
	if (ft_full_scene_validity(&valid) < 0)
		return (-1);
	return (0);
}
