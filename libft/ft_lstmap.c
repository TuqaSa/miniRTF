/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:41:53 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:39:23 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Parameters
----------
		lst: The address of a pointer to a node.
		f: The address of the function used to terate on the list.
		del: The address of the function used to
	deleted the content of a node if needed.
Return value
------------
		The new list.
		NULL if the allocation fails.
External functions
------------------
		malloc, free
Description
-----------
		Iterates the list ’lst’ and applies the function
	f’ on the content of each node.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (!(new_node))
		{
			while (new_list)
			{
				new_node = new_list->next;
				(*del)(new_list->content);
				free(new_list);
				new_list = new_node;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
void	*f(void *content)
{
	return (content += 1);
}

void	del(void *content)
{
	printf("%s\n", (char *)content);
	content = NULL;
}

int	main(void)
{
	t_list	*root;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*curr;
	t_list	*new_list;
	t_list	*currt;

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
	}
	printf("Mapping the original list to a new list...\n");
	new_list = ft_lstmap(root, f, del);
	currt = new_list;
	while(currt != NULL)
	{
		printf("%s\n", (char *)currt->content);
		currt = currt->next;
	}
	return (42);
}
*/
