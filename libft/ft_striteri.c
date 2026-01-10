/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:45:53 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:41:34 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	iter;

	iter = 0;
	if (!s || !f)
		return ;
	while (s[iter])
	{
		f(iter, (s + iter));
		iter++;
	}
	return ;
}

/*
int	main(void)
{
	char	name[] = "Razan Srour";

	ft_striteri(name, &ft_test);
	return (0);
}*/