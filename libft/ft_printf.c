/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:23:17 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/01 11:18:11 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include "header/libft.h"

int	print_types(va_list args, char spec, int num_char, int fd)
{
	if (spec == 'i' || spec == 'd')
		num_char = print_signed_numbers(va_arg(args, int), num_char, fd);
	else if (spec == '%')
		ft_putchar_fd('%', fd);
	else if (spec == 'c')
		ft_putchar_fd(va_arg(args, int), fd);
	else if (spec == 's')
		num_char = print_str(va_arg(args, char *), num_char, fd);
	else if (spec == 'p')
		num_char = print_ptr(va_arg(args, unsigned long), num_char, fd);
	else if (spec == 'x' || spec == 'X')
		num_char = print_hexa(va_arg(args, unsigned int), num_char, spec, fd);
	else if (spec == 'u')
		num_char = print_unsigned(va_arg(args, unsigned int), num_char, fd);
	return (num_char);
}

int	ft_printf(int fd, const char *fmt, ...)
{
	int		i;
	int		num_char;
	va_list	args;

	i = 0;
	va_start(args, fmt);
	num_char = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			num_char -= 1;
			num_char = print_types(args, fmt[i], num_char, fd);
		}
		else
			ft_putchar_fd(fmt[i], fd);
		i++;
		va_end(args);
	}
	return (i + num_char);
}
