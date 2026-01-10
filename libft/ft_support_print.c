/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:39:29 by gitpod            #+#    #+#             */
/*   Updated: 2025/12/07 17:24:04 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include "header/libft.h"

int	print_signed_numbers(int number, int num_char, int fd)
{
	num_char += ft_putnbr_fd(number, fd, 0) + 1;
	return (num_char - 1);
}

int	print_str(char *str, int num_char, int fd)
{
	if (str == NULL)
	{
		num_char += 5;
		ft_putstr_fd("(null)", fd);
	}
	else
	{
		while (*str)
		{
			ft_putchar_fd(*str++, fd);
			num_char += 1;
		}
		num_char -= 1;
	}
	return (num_char);
}

int	print_ptr(unsigned long ptr_add, int num_char, int fd)
{
	if (ptr_add == 0)
	{
		num_char += 4;
		ft_putstr_fd("(nil)", fd);
	}
	else
	{
		ft_putchar_fd('0', fd);
		ft_putchar_fd('x', fd);
		num_char += ft_convert_decimel_to_hexa_p(ptr_add, fd);
		num_char += 2;
		num_char -= 1;
	}
	return (num_char);
}

int	print_hexa(unsigned int x_value, int num_char, char type, int fd)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (str == NULL)
		return (0);
	ft_bzero(str, 12);
	if (type == 'X')
	{
		num_char += ft_convert_decimel_to_hexa_x(x_value, str, fd);
		ft_putstr_fd(str_toupper(str), fd);
	}
	else
	{
		num_char += ft_convert_decimel_to_hexa_x(x_value, str, fd);
		ft_putstr_fd(str, fd);
	}
	free(str);
	return (num_char - 1);
}

int	print_unsigned(unsigned int u_value, int num_char, int fd)
{
	num_char += ft_convert_signed_to_unsigned(u_value, fd);
	return (num_char - 1);
}
