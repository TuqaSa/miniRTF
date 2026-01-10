/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:35:06 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:39:05 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Parameters
----------
		lst: The node to free.
		del: The ddress of the function used to delete the content
Return
------
		None
Enternal Functions
------------------
		free
Description
-----------
		Takes as a parameter a node and frees the memory of the
		node's content using the function 'del' given as a parameter
		and free the node. The memory of 'next' must not be freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	del(void *content)
{
	printf("%s\n", (char*)content);
	content = NULL;
}

int	main(void)
{
	t_list					*root;
	t_list					*elem1;
	t_list					*elem2;
	t_list					*curr;
	deleting the last		node;
	after deleting the last	node;

	root = ft_lstnew("Razan");
	elem1 = ft_lstnew("Srour");
	elem2 = ft_lstnew("The");
	ft_lstadd_back(&root, elem1);
	ft_lstadd_back(&root, elem2);
	curr = root;
	while(curr != NULL)
	{
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
		printf("Here\n");
	}
	printf("The size of the list befor
	node = %d\n", ft_lstsize(root));
	printf("deleting a node from the list....\n");
	ft_lstdelone(elem2, del);
	printf("The size of the list
	node = %d\n", ft_lstsize(root));
	return (42);
}
*/