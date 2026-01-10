/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:38:06 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:39:10 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Parameters
----------
		lst: The address of a pointer to a node.
		f: The address of the function used to iterate on the list.
Description
-----------
		Iterates the list 'lst' and applies the function 'f'
		on the content of each node.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	f(void *content)
{
	content += 1;
}

int	main(void)
{
	t_list	*root;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*curr;

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
	printf("Applying a function to the list...\n");
	ft_lstiter(root, f);
	curr = root;
	while(curr != NULL)
	{
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
	}
	return (42);
}
*/
