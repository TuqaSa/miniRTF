/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:06:39 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:42:09 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strnstr(const char *s, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (need[0] == '\0')
	{
		return ((char *)s);
	}
	while (s[i] != '\0' && i < len)
	{
		while (s[i + j] == need[j] && i + j < len)
		{
			if (need[j + 1] == '\0')
			{
				return ((char *)&s[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
