/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:34:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/05/16 01:46:37 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		iter;
	size_t		length;

	if (!src)
		return (0);
	iter = 0;
	length = ft_strlen(src);
	if (size == 0)
		return (length);
	while (iter < length && iter < (size - 1))
	{
		dst[iter] = src[iter];
		iter++;
	}
	dst[iter] = '\0';
	return (length);
}

/*
int	main(void)
{
	const char	*src = "Srour";
	char		dest[6];
	size_t		len_dest = ft_strlcpy(dest, src, 6);
	size_t		iter = 0;

	if (len_dest >= sizeof(src))
		printf("Error: destination buffer too small, sizeof(src) = %ld\n",
			sizeof(src));
	else
	{
		printf("dest = %s\n", dest);
		printf("len_dest = %ld\n", len_dest);
		if (dest[5] == '\0')
			printf("True\n");
		while(dest[iter] != '\0')
		{
			printf("dest[%ld] = %c\n", iter, dest[iter]);
			iter++;
		}
		printf("dest[%ld] = %c\n", iter, dest[iter]);
	}

	return (0);
}*/
