/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:55:36 by rsrour            #+#    #+#             */
/*   Updated: 2025/05/29 16:59:37 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Parameters
----------
		s1: The prefix string.
		s2: The prefix string.
Return value
------------
		The new string.
		NULL is the allocation fails.
External functions
------------------
		malloc
Description
-----------
		Allocates (with malloc(3)) and returns a new
		string, which is the result of the
		concatenation of 's1' and 's2'.
*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, len_s1 + 1);
	ft_strlcat(joined_str, s2, len_s1 + len_s2 + 1);
	return (joined_str);
}

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, len1 + 1);
	ft_strlcat(dest, s2, len1 + len2 + 1);
	return (dest);
}

int	main(void)
{
	char	name1[] = "Razan";
	char	name2[] = "_Srour";

	printf("The join of %s and %s is %s\n", name1, name2, ft_strjoin(name1,
			name2));
	return (0);
}
*/
