/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:07:50 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:37:41 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
#include <ctype.h>

int	ft_isalnum(char c)
{
	if (('a' <= c && 'z' >= c) || ('A' <= c && 'Z' >= c) || ('0' <= c
			&& '9' >= c))
	{
		return (8);
	}
	return (0);
}
/*
int	main(void)
{
	char	char1 = 'r';
	char	char2 = 'S';
	char	char3 = '0';
	char	char4 = '-';
	char	char5 = '*';
	char	char6 = '8';
	char	char7 = 'y';
	int	char8 = 4;
	int	char9 = 9;

	printf("%c is alnum: %d\n", char1, isalnum(char1));
	printf("%c is alnum: %d\n", char2, isalnum(char2));
	printf("%c is alnum: %d\n", char3, isalnum(char3));
	printf("%c is alnum: %d\n", char4, isalnum(char4));
	printf("%c is alnum: %d\n", char5, isalnum(char5));
	printf("%c is alnum: %d\n", char6, isalnum(char6));
	printf("%c is alnum: %d\n", char7, isalnum(char7));
	printf("%d is alnum: %d\n", char8, isalnum(char8));
	printf("%d is alnum: %d\n", char9, isalnum(char9));
	printf("================\n");
	printf("%c is alnum: %d\n", char1, ft_isalnum(char1));
	printf("%c is alnum: %d\n", char2, ft_isalnum(char2));
	printf("%c is alnum: %d\n", char3, ft_isalnum(char3));
	printf("%c is alnum: %d\n", char4, ft_isalnum(char4));
	printf("%c is alnum: %d\n", char5, ft_isalnum(char5));
	printf("%c is alnum: %d\n", char6, ft_isalnum(char6));
	printf("%c is alnum: %d\n", char7, ft_isalnum(char7));
	printf("%d is alnum: %d\n", char8, ft_isalnum(char8));
	printf("%d is alnum: %d\n", char9, ft_isalnum(char9));
}*/
