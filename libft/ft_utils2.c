/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:43:10 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/01 10:55:22 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include "header/libft.h"

int	calculate_digits(unsigned int number)
{
	unsigned int	len;

	len = 0;
	if (number == 0)
		len = 1;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

int	ft_convert_signed_to_unsigned(unsigned int number, int fd)
{
	char	*n_base;
	int		len;

	len = calculate_digits(number);
	n_base = malloc(sizeof(char) * (len + 1));
	if (!n_base)
		return (0);
	n_base[len] = '\0';
	while (len--)
	{
		n_base[len] = number % 10 + '0';
		number /= 10;
	}
	len = write(fd, n_base, ft_strlen(n_base) * sizeof(char));
	free(n_base);
	return (len);
}
