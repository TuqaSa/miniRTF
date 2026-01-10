/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:17:13 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:40:00 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*buffer1;
	char		*buffer2;

	if (!(dest || src))
		return (NULL);
	i = n;
	buffer1 = (char *)src;
	buffer2 = (char *)dest;
	if (buffer2 > buffer1)
	{
		while (i-- > 0)
			*(buffer2 + i) = *(buffer1 + i);
	}
	else if (buffer1 > buffer2)
	{
		i = 0;
		while (i < n)
		{
			*(buffer2 + i) = *(buffer1 + i);
			i++;
		}
	}
	return (buffer2);
}
/*
int	main(void)
{
	const char	*src = "Razan Srour";
	char		dest1[7];
//	char		dest2[12];

//	memmove(dest1, src, 5);
//	memmove(dest2, src, 12);
	ft_memmove(dest1, src, 7);

	return (0);
}*/
