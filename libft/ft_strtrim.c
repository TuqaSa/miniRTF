/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:00:08 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 17:24:20 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

static int	ft_calc_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen((char *)s1) - 1;
	while (end > 0)
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	return (end);
}

static int	ft_calc_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (start < (int)ft_strlen((char *)s1))
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!set)
		return (NULL);
	if (!s1)
	{
		res = malloc(1 * sizeof(char));
		res[0] = '\0';
		return (res);
	}
	end = ft_calc_end(s1, set);
	start = ft_calc_start(s1, set);
	if (start > end)
	{
		res = malloc(1 * sizeof(char));
		res[0] = '\0';
		return (res);
	}
	res = malloc((end - start + 1 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, (char *)&s1[start], end - start + 1 + 1);
	return (res);
}
