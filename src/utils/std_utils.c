/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:40:36 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 16:16:38 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "minirt.h"
#include "ft_printf.h"

int	ft_indicate_err(char *err_msg, int status)
{
	ft_printf(2, err_msg);
	return (status);
}

int	ft_clean(char *fmt, ...)
{
	va_list	args;
	int		iter;

	iter = 0;
	va_start(args, fmt);
	while (fmt[iter])
	{
		if (fmt[iter] == '$')
		{
			iter++;
			if (fmt[iter] == 's')
				free(va_arg(args, char *));
			if (fmt[iter] == 'f')
				close(va_arg(args, int));
		}
		iter++;
	}
	va_end(args);
	return (1);
}
