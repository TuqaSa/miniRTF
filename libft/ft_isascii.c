/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:10:59 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:38:39 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

//#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char    char1 = 'r';
		char    char2 = 'S';
		char    char3 = '0';
		char    char4 = '-';
		char    char5 = '*';
		char    char6 = '8';
		char    char7 = 'y';
		int     char8 = 4;
		char     char9 = ' ';
	char	char10 = '^';
	char	char11 = 0;
	int	char12 = 0;


	printf("%c is ascii: %d\n", char1, isascii(char1));
		printf("%c is ascii: %d\n", char2, isascii(char2));
		printf("%c is ascii: %d\n", char3, isascii(char3));
		printf("%c is ascii: %d\n", char4, isascii(char4));
		printf("%c is ascii: %d\n", char5, isascii(char5));
		printf("%c is ascii: %d\n", char6, isascii(char6));
		printf("%c is ascii: %d\n", char7, isascii(char7));
		printf("%d is ascii: %d\n", char8, isascii(char8));
		printf("%d is ascii: %d\n", char9, isascii(char9));
	printf("%d is ascii: %d\n", char10, isascii(char10));
	printf("%d is ascii: %d\n", char11, isascii(char11));
	printf("%d is ascii: %d\n", char12, isascii(char12));
		printf("================\n");
		printf("%c is ascii: %d\n", char1, ft_isascii(char1));
		printf("%c is ascii: %d\n", char2, ft_isascii(char2));
		printf("%c is ascii: %d\n", char3, ft_isascii(char3));
		printf("%c is ascii: %d\n", char4, ft_isascii(char4));
		printf("%c is ascii: %d\n", char5, ft_isascii(char5));
		printf("%c is ascii: %d\n", char6, ft_isascii(char6));
		printf("%c is ascii: %d\n", char7, ft_isascii(char7));
		printf("%d is ascii: %d\n", char8, ft_isascii(char8));
		printf("%d is ascii: %d\n", char9, ft_isascii(char9));
	printf("%d is ascii: %d\n", char10, ft_isascii(char10));
	printf("%d is ascii: %d\n", char11, ft_isascii(char11));
	printf("%d is ascii: %d\n", char12, ft_isascii(char12));

}*/
