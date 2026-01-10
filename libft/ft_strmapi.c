/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:59:41 by rsrour            #+#    #+#             */
/*   Updated: 2025/05/29 17:01:16 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t	iter;
	char	*buffer;

	buffer = ft_strdup(s);
	if (!buffer)
		return (NULL);
	iter = 0;
	while (buffer[iter] != '\0')
	{
		buffer[iter] = f(iter, buffer[iter]);
		iter++;
	}
	buffer[iter++] = '\0';
	return (buffer);
}
/*
static char	ft_add(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char	name[] = "LoRem iPsUm";
	char	*new_name;

	new_name = ft_strmapi(name, ft_add);
	printf("old name = %s\n", name);
	printf("new_name = %s\n", new_name);

	return (0);
}*/
