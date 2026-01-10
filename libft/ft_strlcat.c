/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:13:10 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 17:25:44 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	iter;

	destlen = ft_strlen(dst);
	if (size <= destlen)
		return (size + ft_strlen(src));
	iter = 0;
	while (src[iter] != '\0' && destlen + iter < size - 1)
	{
		dst[destlen + iter] = src[iter];
		iter++;
	}
	dst[destlen + iter] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[iter]));
}

// int	main(void)
// {
// 	const char	*src = "Razan";
// 	char	*dest;// = ft_strdup("NAME: ");
// 	// char	*dest1;
// 	char	*src2 = "  ";
// 	char	*src3 = "Srour";
// 	dest = malloc(sizeof(char *) * 11);
// 	if (!dest)
// 		return (1);
// 	// size_t	cat_size = 6;

// 	printf("concatinating %s with %s\n", dest, src);
// 	printf("=============================\n");
// 	printf("%s", strcat(dest, src));
// 	printf("\n dest:%s\n", dest);
// 	printf("=============================\n");
// 	printf("%s", strcat(dest, src2));
// 	printf("\n dest:%s\n", dest);
// 	printf("=============================\n");
// 	printf("%s", strcat(dest, src3));
// 	printf("\n dest:%s\n", dest);
// 	// printf("%ld", strlcat(dest1, , cat_size));
// 	// printf("\n dest1:%s\n", dest);
// 	free(dest);
// 	// free(dest1);
// 	return (0);
// }
