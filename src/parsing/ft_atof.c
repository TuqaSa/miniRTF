/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:09:21 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 16:40:18 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "data_ctxs.h"

static t_atofctx	ft_initctx(void)
{
	t_atofctx	newctx;

	newctx.i = 0;
	newctx.flt = 0;
	newctx.dig_ind = 0;
	newctx.sign = 1;
	return (newctx);
}

static int	ft_checksign(char **src_r, t_atofctx *ctx_r)
{
	if ((*src_r)[ctx_r->i] == '-' || (*src_r)[ctx_r->i] == '+')
	{
		if ((*src_r)[ctx_r->i] == '-')
			ctx_r->sign = -1;
		ctx_r->i++;
	}
	if ((*src_r)[ctx_r->i] == '\0')
		return (ft_indicate_err("Error\ninvalid float entry\n", -1));
	return (0);
}

float	ft_atof(char **sr_r, float *res_r)
{
	t_atofctx	ct;

	if (!sr_r || !(*sr_r))
		return (-1);
	ct = ft_initctx();
	if (ft_checksign(sr_r, &ct) < 0)
		return (-1.0f);
	while ((*sr_r)[ct.i])
	{
		if ((*sr_r)[ct.i] == '.')
		{
			ft_increament(&ct.flt, &ct.i, &ct.dig_ind);
			continue ;
		}
		if ((!ft_isdigit((*sr_r)[ct.i])
			&& (*sr_r)[ct.i] != '.') || ct.flt > 1)
			return ((float)ft_indicate_err("Error\ninvalid float\n", -1));
		if (ct.flt == 0)
			*res_r = (*res_r * 10) + (float)((*sr_r)[ct.i] - '0');
		if (ct.flt > 0)
			*res_r += (float)((*sr_r)[ct.i] - '0') / (powf(10, ct.dig_ind++));
		ct.i++;
	}
	*res_r = (*res_r) * ct.sign;
	return (0);
}
