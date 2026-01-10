/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:47:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:40:05 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Description
-----------
		The memset() function fills the first n bytes of the memory are
		pointed to by s with the constant byte c.
Return Value
------------
		The memset() function returns a pointer to the memory area s.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memeset(): %s\n", str);

	// Fill 8 characters starting from str[13] with '.'
	//ft_memset(str + 13, '.', 8*sizeof(char));
	ft_memset(str + 13, '.', 8*sizeof(char));

	printf("After memset(): %s", str);
	return (0);
}*/
