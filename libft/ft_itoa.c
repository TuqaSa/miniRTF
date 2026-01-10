/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:03:06 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:38:47 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

static size_t	numlen(int n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
	{
		length++;
	}
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	size_t	len_number;
	long	number;

	number = n;
	len_number = numlen(number);
	buffer = malloc(sizeof(char) * (len_number + 1));
	if (!buffer)
		return (NULL);
	if (number < 0)
	{
		buffer[0] = '-';
		number = -number;
	}
	buffer[len_number--] = '\0';
	if (number == 0)
		buffer[0] = '0';
	while (number)
	{
		buffer[len_number--] = number % 10 + '0';
		number /= 10;
	}
	return (buffer);
}
/*
int	main(void)
{
	int	number = -45767016;

	printf("The string rep of %d is %s\n", number, ft_itoa(number));

	return (0);
}*/
