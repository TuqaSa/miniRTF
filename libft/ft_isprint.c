/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:21:33 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:38:04 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (16384);
	return (0);
}
/*
int	main(void)
{
	char	char1 = 'r';
	char	char2 = 'S';
	char	char3 = '0';
	char	char4 = ' ';
	char	char5 = '-';
	int	char6 = 6;
	int	char7 = 9;
	char	char8 = '\t';

	printf("%c isprint: %d\n", char1, isprint(char1));
	printf("%c isprint: %d\n", char2, isprint(char2));
		printf("%c isprint: %d\n", char3, isprint(char3));
	printf("%c isprint: %d\n", char4, isprint(char4));
	printf("%c isprint: %d\n", char5, isprint(char5));
	printf("%d isprint: %d\n", char6, isprint(char6));
	printf("%d isprint: %d\n", char7, isprint(char7));
	printf("%c isprint: %d\n", char8, isprint(char8));
	printf("====================\n");
		printf("%c isprint: %d\n", char1, ft_isprint(char1));
		printf("%c isprint: %d\n", char2, ft_isprint(char2));
		printf("%c isprint: %d\n", char3, ft_isprint(char3));
		printf("%c isprint: %d\n", char4, ft_isprint(char4));
		printf("%c isprint: %d\n", char5, ft_isprint(char5));
		printf("%d isprint: %d\n", char6, ft_isprint(char6));
		printf("%d isprint: %d\n", char7, ft_isprint(char7));
		printf("%c isprint: %d\n", char8, ft_isprint(char8));
}*/
