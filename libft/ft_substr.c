/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:47:17 by rsrour            #+#    #+#             */
/*   Updated: 2025/06/11 08:53:48 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Parameters
----------
		s: The string from which to create the substring.
		start: The start index of the substring in the string 's'.
		len: The maximum length of the substring.
Return Value
------------
		The substring.
		NULL if the allocation fails.
External functions
------------------
		malloc
Description
-----------
		Allocates (with malloc(3)) and returns a substring
		from the string 's'.
		The substring begins at index 'start' and is of
		maximum size 'len'.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	src_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	if (start + len > src_len)
		len = src_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
/*
int	main(void)
{
	// char		*name = "hola";
	// unsigned int	start = 2;
	// size_t		size_substr = 2;

	// printf("The substring of %s starting from %d of length %ld\n",
	// name, start, size_substr);
	printf("is: %s\n", ft_substr("hola", 4294967295, 18446744073709551615));
	return (0);
}*/
