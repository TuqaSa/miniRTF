/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:04 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/08 00:21:37 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "data_ctxs.h"

char	*ft_validate_idlen(char **liner, int *ct_r)
{
	t_vallinectx	ctx;

	ft_memset(&ctx, 0, sizeof(t_vallinectx));
	if (ft_initvlline(&ctx) < 0)
		return (NULL);
	while (ctx.i < ft_strlen(*liner) && ft_isspace((*liner)[ctx.i]))
		ctx.i++;
	*ct_r = ctx.i;
	while (ctx.i < ft_strlen(*liner) && (*liner)[ctx.i])
	{
		if ((ctx.j == 1 || ctx.j == 2)
			&& ((*liner)[ctx.i] == ' ' || (*liner)[ctx.i] == '\t'))
			break ;
		if (ctx.j == 2)
		{
			free(ctx.id);
			ft_indicate_err("Error\ninvalide identifier\n", -1);
			return (NULL);
		}
		ctx.id[ctx.j++] = (*liner)[ctx.i++];
	}
	ctx.id[ctx.j] = '\0';
	return (ctx.id);
}

int	ft_fill_id(t_valid *valid_r, char **id_r)
{
	if (!ft_strcmp(*id_r, "A"))
		return (ft_fill_a(valid_r, 1));
	else if (!ft_strcmp(*id_r, "C"))
		return (ft_fill_c(valid_r, 1));
	else if (!ft_strcmp(*id_r, "L"))
		return (ft_fill_l(valid_r, 1));
	else if (!ft_strcmp(*id_r, "l"))
		return (ft_fill_l(valid_r, 0));
	else if (!ft_strcmp(*id_r, "sp"))
		return (ft_fill_sp(valid_r, 0));
	else if (!ft_strcmp(*id_r, "pl"))
		return (ft_fill_pl(valid_r, 0));
	else if (!ft_strcmp(*id_r, "cy"))
		return (ft_fill_cy(valid_r, 0));
	else if (!ft_strcmp(*id_r, "cn"))
		return (ft_fill_cn(valid_r, 0));
	else if (!ft_strcmp(*id_r, "hy"))
		return (ft_fill_hy(valid_r, 0));
	return (ft_indicate_err("Error\ninvalid id\n", -1));
}

int	ft_fill_cy(t_valid *valid_r, int cap_decl)
{
	valid_r->cy[0] = cap_decl;
	valid_r->cy[1] += 1;
	if ((valid_r->cy[1] > 1) && (valid_r->cy[0] == 1))
		return (ft_indicate_err("Error\nLight cannot be declared \
more than once\n", -1));
	return (0);
}

int	ft_fill_cn(t_valid *valid_r, int cap_decl)
{
	valid_r->cn[0] = cap_decl;
	valid_r->cn[1] += 1;
	if ((valid_r->cn[1] > 1) && (valid_r->cn[0] == 1))
		return (ft_indicate_err(
				"Error\nLight cannot be declared more than once\n", -1));
	return (0);
}

int	ft_fill_hy(t_valid *valid_r, int cap_decl)
{
	valid_r->hy[0] = cap_decl;
	valid_r->hy[1] += 1;
	if ((valid_r->hy[1] > 1) && (valid_r->hy[0] == 1))
		return (ft_indicate_err(
				"Error\nLight cannot be declared more than once\n", -1));
	return (0);
}
