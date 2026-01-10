/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:07:36 by rsrour            #+#    #+#             */
/*   Updated: 2025/05/19 21:20:42 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	index;

	index = (int)ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (unsigned char)c)
			return ((char *)s + index);
		index--;
	}
	return (NULL);
}
