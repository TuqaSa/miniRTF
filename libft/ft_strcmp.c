/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:25:58 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 17:25:58 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	iter;

	iter = 0;
	while (str1[iter] || str2[iter])
	{
		if ((str1[iter] - str2[iter]) != 0)
			return (str1[iter] - str2[iter]);
		iter++;
	}
	return (str1[iter] - str2[iter]);
}
