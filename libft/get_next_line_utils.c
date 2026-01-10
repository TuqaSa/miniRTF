/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:07 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/11 20:51:55 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

/* char	*ft_strjoin(char *s1, char *s2) */
/* { */
/* 	size_t	i; */
/* 	size_t	j; */
/* 	char	*str; */

/* 	i = -1; */
/* 	j = 0; */
/* 	if (!s1) */
/* 	{ */
/* 		s1 = (char *)malloc(sizeof(char) * 1); */
/* 		if (!s1 || !s2) */
/* 			return (free(s1), NULL); */
/* 		s1[0] = '\0'; */
/* 	} */
/* 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)); */
/* 	if (str == NULL) */
/* 		return (NULL); */
/* 	while (s1[++i] != '\0') */
/* 		str[i] = s1[i]; */
/* 	while (s2[j] != '\0') */
/* 		str[i++] = s2[j++]; */
/* 	str[i] = '\0'; */
/* 	free(s1); */
/* 	return (str); */
/* } */

char	*ft_find_newline(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char) '\n')
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}

char	*get_rest_line(char *line)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	i++;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}
