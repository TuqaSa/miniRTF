/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:30:56 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:39:01 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Parameters
----------
		lst: The address of a pointer to a node.
		del: The address of the function used to delete the
			content of the node.
External functions
------------------
		free
Description
-----------
		Deletes and frees the given node and every successor of
		that node, using the function 'del' and free(3).
		Finally, the pointer to the list must be set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*curr;

	if (!lst || !*lst || !del)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
/*
void	del(void *content)
{
	printf("%s\n", (char *)content);
	content = NULL;
}
*/
/*int     main()
{
	t_list  *root = ft_lstnew("Razan");
	t_list  *elem1 = ft_lstnew("Srour");
	t_list  *elem2 = ft_lstnew("The");
	ft_lstadd_back(&root, elem1);
	ft_lstadd_back(&root, elem2);
	t_list  *curr = root;
	while(curr != NULL)
	{
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
		printf("Here\n");
	}
	printf("deleting a node from the list....\n");
	ft_lstclear(&root, del);
	if (root == NULL)
		printf("List is clear\n");
	return (42);
}*/
