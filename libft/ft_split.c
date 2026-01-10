/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:48:38 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 17:25:14 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Parameters
----------
		s: The string to be split.
		c: The delimiter.
Return Value
------------
		The array of new strings resulting from the split.
		NULL if the allocation fails.
External Functions
------------------
		malloc, free
Description
-----------
		Allocates (with malloc(3)) and returns an array
		of strings obtained by splitting 's' using the
		character 'c' as a delimiter. The array must end
		with a NULL pointer.
*/

static void	fillarr(char **arr, size_t len_arr, char const *s, char c)
{
	size_t	position;
	size_t	len_word;

	position = 0;
	while (position < len_arr)
	{
		len_word = 0;
		while (*s == c && *s != 0)
			s++;
		while (s[len_word] != c && s[len_word] != '\0')
			len_word++;
		arr[position] = ft_substr(s, 0, len_word);
		if (!arr[position])
		{
			while (position > 0)
				free(arr[--position]);
			return ;
		}
		s += len_word;
		position++;
	}
	arr[position] = 0;
}

static size_t	ft_count_words(char const *sentence, char seperator)
{
	size_t	counter;
	bool	is_a_word;

	counter = 0;
	while (*sentence)
	{
		is_a_word = false;
		while (*sentence == seperator && *sentence)
			++sentence;
		while (*sentence != seperator && *sentence)
		{
			if (!is_a_word)
			{
				is_a_word = true;
				counter++;
			}
			++sentence;
		}
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	size_t	number_of_words;
	char	**words_vector;

	if (!s || !c)
		return (NULL);
	number_of_words = ft_count_words(s, c);
	if (number_of_words == 0)
		return (NULL);
	words_vector = malloc(sizeof(char *) * (number_of_words + 1));
	if (!words_vector)
		return (NULL);
	fillarr(words_vector, number_of_words, s, c);
	return (words_vector);
}

// int	main()
// {
// 	char const	*name = "Razan Srour";
// 	char	seperator = 'r';
// 	char	**splitted_name;

// 	printf("Starting.. %c\n", seperator);
// 	splitted_name = ft_split(name, seperator);

// 	if (splitted_name == NULL)
// 	{
// 		printf("No words were found in the input string.\n");
// 		return (0);
// 	}

// 	printf("The %s was seperated from '%c' into\n %s,\n %s\n",
// 	name ,seperator ,splitted_name[0], splitted_name[1]);

// 	int iter = 0;
// 	while(splitted_name[iter])
// 	{
// 		free(splitted_name[iter]);
// 		iter++;
// 	}
// 	free(splitted_name);
// 	return (0);
// }
