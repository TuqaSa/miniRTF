/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:19:14 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:38:34 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

//#include <ctype.h>

int	ft_isalpha(int c)
{
	if (('a' <= c && 'z' >= c) || ('A' <= c && 'Z' >= c))
	{
		return (1024);
	}
	return (0);
}
/*
int	main(void)
{
	char	char1 = 'c';
	char	char2 = 'V';
	char	char3 = '8';
	int	char4 = 5;
	int	char5 = 154;
	char	char6 = '-';
	char	char7 = '%';

	printf("%c is alpha: %d\n", char1, ft_isalpha(char1));
	printf("%c is alpha: %d\n", char2, ft_isalpha(char2));
	printf("%c is alpha: %d\n", char3, ft_isalpha(char3));
	printf("%d is alpha: %d\n", char4, ft_isalpha(char4));
	printf("%d is alpha: %d\n", char5, ft_isalpha(char5));
	printf("%c is alpha: %d\n", char6, ft_isalpha(char6));
	printf("%c is alpha: %d\n", char7, ft_isalpha(char7));

	return (0);
}*/
