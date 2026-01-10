/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:09:23 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 17:26:40 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strdup(char *src)
{
	size_t	iter;
	size_t	length;
	char	*dst;

	if (!src)
		return (NULL);
	iter = 0;
	length = ft_strlen(src);
	dst = malloc(sizeof(char) * (length + 1));
	if (!dst)
		return (NULL);
	while (src[iter] != '\0')
	{
		dst[iter] = src[iter];
		iter++;
	}
	dst[iter] = '\0';
	return (dst);
}
