/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:41:10 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:39:15 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Parameters
----------
		lst: The beginning of the list.
Return
------
		Last node of the list.
Description
-----------
		Returns the last node of the list.
*/
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}
/*
int	main(void)
{
	t_list  *root = ft_lstnew("Razan");
	t_list  *elem1 = ft_lstnew("Srour");
	t_list  *elem2 = ft_lstnew("The");

	ft_lstadd_back(&root, elem1);
	ft_lstadd_back(&root, elem2);

	printf("NUmber of nodes in the list is %d\n",
	ft_lstsize(root));
	t_list *last_element = ft_lstlast(root);
	printf("The last node in the list is %s\n",
	(char *)last_element->content);
	return (42);
}*/
