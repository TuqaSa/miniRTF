/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:07:27 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:39:55 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		index;
	const char	*buffer1;
	char		*buffer2;

	index = 0;
	buffer1 = (char *)src;
	buffer2 = dest;
	while (index < n && (src || dest))
	{
		buffer2[index] = buffer1[index];
		index++;
	}
	return (buffer2);
}
/*
int	main(void)
{
	char	*src = "Razan Srour";
//	char	dest1[6];
//	char	dest2[5];
//	char	dest3[0];
	char	dest4[12];

//	ft_memcpy(dest1, src, 6);
//	ft_memcpy(dest2, src, 3);
//	ft_memcpy(dest3, src, 0);
	memcpy(dest4, src, ft_strlen(src));

//	printf("The memory copy from %s to dest1[6] and n = 6 is %s.\n", src,
		dest1);
//	printf("The memory copy from %s to dest2[5] and n = 3 is %s.\n", src,
		dest2);
//	printf("The memory copy from %s to dest3[0] and n = 0 is %s.\n", src,
		dest3);
	printf("The memory copy from %s to dest4[12] and n = 11 is %s.\n", src,
		dest4);

	return (0);
}*/
