/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:48 by gitpod            #+#    #+#             */
/*   Updated: 2025/12/07 17:27:58 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*p_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = manage_buffer(fd, line);
	if (line == NULL)
		return (NULL);
	p_line = ft_get_line(line);
	line = get_rest_line(line);
	return (p_line);
}

static char	*ft_filling_buffer(int read_size, char *line, int fd, char *temp)
{
	char	*joined;

	while (!ft_find_newline(line) && read_size != 0)
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(temp);
			free(line);
			return (NULL);
		}
		temp[read_size] = '\0';
		joined = ft_strjoin(line, temp);
		free(line);
		if (!joined)
		{
			free(temp);
			return (NULL);
		}
		line = joined;
	}
	return (line);
}

char	*manage_buffer(int fd, char *line)
{
	char	*temp;
	ssize_t	read_size;

	read_size = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	line = ft_filling_buffer(read_size, line, fd, temp);
	if (!line)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (line);
}

char	*ft_get_line(char *line)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
