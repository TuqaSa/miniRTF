/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:23:30 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/01 11:01:49 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include "header/libft.h"

char	*ft_hexa_converter(unsigned long number, char *hex_str)
{
	int	remainder;
	int	i;

	i = 0;
	while (number > 0)
	{
		remainder = number % 16;
		if (remainder < 10)
			hex_str[i] = remainder + '0';
		else
			hex_str[i] = remainder - 10 + 'a';
		number /= 16;
		i++;
	}
	hex_str[i] = '\0';
	return (hex_str);
}

int	ft_convert_decimel_to_hexa_p(unsigned long number, int fd)
{
	char	hex[16];
	int		len;
	int		i;

	if (number == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	if (number > 0)
		ft_hexa_converter(number, hex);
	len = ft_strlen(hex);
	i = len;
	while (i > 0)
		ft_putchar_fd(hex[--i], fd);
	return (len);
}

void	ft_reverse_string(char *str)
{
	char	temp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
}

char	*str_toupper(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		data[i] = ft_toupper(data[i]);
		i++;
	}
	return (data);
}

int	ft_convert_decimel_to_hexa_x(unsigned int number, char *str, int fd)
{
	int	i;
	int	remainder;

	i = 0;
	if (number == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	while (number > 0)
	{
		remainder = number % 16;
		if (remainder < 10)
			str[i++] = remainder + '0';
		else
			str[i++] = remainder - 10 + 'a';
		number /= 16;
	}
	str[i] = '\0';
	ft_reverse_string(str);
	return (i);
}
