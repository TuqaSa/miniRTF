/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ids.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:38:58 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 16:03:02 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_fill_a(t_valid *valid_r, int cap_decl)
{
	valid_r->a[0] = cap_decl;
	valid_r->a[1] += 1;
	if ((valid_r->a[1] > 1) && (valid_r->a[0] == 1))
		return (ft_indicate_err(
				"Error\nAmbient light cannot be declared more than once\n",
				-1));
	return (0);
}

int	ft_fill_c(t_valid *valid_r, int cap_decl)
{
	valid_r->c[0] = cap_decl;
	valid_r->c[1] += 1;
	if ((valid_r->c[1] > 1) && (valid_r->c[0] == 1))
		return (ft_indicate_err(
				"Error\nCamera cannot be declared more than once\n",
				-1));
	return (0);
}

int	ft_fill_l(t_valid *valid_r, int cap_decl)
{
	if (cap_decl == 0 && valid_r->l[0] == 1)
		return (ft_indicate_err(
				"Error\nLight cannot be declared more than once\n",
				-1));
	valid_r->l[0] = cap_decl;
	valid_r->l[1] += 1;
	if ((valid_r->l[1] > 1) && (valid_r->l[0] == 1))
		return (ft_indicate_err(
				"Error\nLight cannot be declared more than once\n",
				-1));
	return (0);
}

int	ft_fill_sp(t_valid *valid_r, int cap_decl)
{
	valid_r->sp[0] = cap_decl;
	valid_r->sp[1] += 1;
	if ((valid_r->sp[1] > 1) && (valid_r->sp[0] == 1))
		return (ft_indicate_err(
				"Error\nLight cannot be declared more than once\n",
				-1));
	return (0);
}

int	ft_fill_pl(t_valid *valid_r, int cap_decl)
{
	valid_r->pl[0] = cap_decl;
	valid_r->pl[1] += 1;
	if ((valid_r->pl[1] > 1) && (valid_r->pl[0] == 1))
		return (ft_indicate_err(
				"Error\nLight cannot be declared more than once\n",
				-1));
	return (0);
}
