/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:10:12 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:38:24 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

//#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore bzero(): %s\n", str);

	//Fill 8 characters from str[13] with '\0'
	ft_bzero(str + 20, 8*sizeof(char));

	printf("After bzero(): %s\n", str);
	return (0);
}*/
