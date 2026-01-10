/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:09:25 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:40:48 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src != '\0' && *src != (unsigned char)c)
		src++;
	if (*src == (unsigned char)c)
		return ((char *)src);
	return (NULL);
}
/*
int	main(void)
{
	char	src[] = "Razan Srour";
	char	char1 = 'm';
	int	num1 = 'a';
	int	num2 = 'Z';
	int	num3 = 8;

	printf("The pointer of the first occurance of %c in %s is %s\n", num1, src,
		strchr(src, num1));
	printf("The pointer of the first occurance of %c in %s is %s\n", num2, src,
		strchr(src, num2));
	printf("The pointer of the first occurance of %d in %s is %s\n", num3, src,
		strchr(src, num3));
	printf("The pointer of the first occurance of %c in %s is %s\n", char1, src,
		strchr(src, char1));
	printf("The pointer of the first occurance of %c in %s is %s\n", num1, src,
		ft_strchr(src, num1));
	printf("The pointer of the first occurance of %c in %s is %s\n", num2, src,
		ft_strchr(src, num2));
	printf("The pointer of the first occurance of %d in %s is %s\n", num3, src,
		ft_strchr(src, num3));
	printf("The pointer of the first occurance of %c in %s is %s\n", char1, src,
		ft_strchr(src, char1));
	return (0);
}*/
