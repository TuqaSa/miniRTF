/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:03:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:39:51 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
/*
int	main(void)
{
	char	*str1 = "Razan";
	char	*str2 = "Razan";
	char	*str3 = "razan";
	char	*str4 = "RAzan";
	char	*str5 = "rAzan";
	char	*str6 = "ra6an";
	int	n_bytes = 4;

	printf("The memcmp between %s and %s for the first %d bytes is %d\n", str1,
		str2, n_bytes, memcmp(str1, str2, n_bytes));
	printf("The memcmp between %s and %s for the first %d bytes is %d\n", str1,
		str3, n_bytes, memcmp(str1, str3, n_bytes));
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str1, str4, n_bytes, memcmp(str1, str4, n_bytes));
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str1, str5, n_bytes, memcmp(str1, str5, n_bytes));
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str1, str6, n_bytes, memcmp(str1, str6, n_bytes));
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str3, str6, n_bytes, memcmp(str3, str6, n_bytes));
	printf("=========================\n");
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str1, str2, n_bytes, ft_memcmp(str1, str2, n_bytes));
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str1, str3, n_bytes, ft_memcmp(str1, str3, n_bytes));
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str1, str4, n_bytes, ft_memcmp(str1, str4, n_bytes));
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str1, str5, n_bytes, ft_memcmp(str1, str5, n_bytes));
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str1, str6, n_bytes, ft_memcmp(str1, str6, n_bytes));
		printf("The memcmp between %s and %s for the first %d bytes is %d\n",
			str3, str6, n_bytes, ft_memcmp(str3, str6, n_bytes));

	return (0);
}*/
