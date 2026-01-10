/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:04:28 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:40:27 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

int	ft_putnbr_fd(int n, int fd, int len)
{
	int	sign;

	sign = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		len += 1;
		if (n == -2147483648)
		{
			sign = 1;
			n++;
		}
		n = -n;
	}
	if (n > 9)
	{
		len += 1;
		len = ft_putnbr_fd(n / 10, fd, len);
	}
	ft_putchar_fd(n % 10 + '0' + sign, fd);
	return (len);
}

// int    main(void)
// {
//     int    n;

//     n = 5767545;
//     int len_number = ft_putnbr_fd(n, 1, 0);
//     printf("\nlength of %d = %d\n", n, len_number);
//     return (0);
// }
