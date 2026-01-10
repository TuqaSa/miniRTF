/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:29:28 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:38:56 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

/*
Parameters: lst: The address of a pointer to the first link of a list.
			new: The address of a pointer to the node to be added to the list.

Description: Adds the node `new` at the end of the list
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list  *org_list = NULL;
	t_list  *new_list;

	org_list = ft_lstnew("Razan");
	new_list = ft_lstnew("Srour");
	ft_lstadd_front(&org_list, new_list);

	t_list *curr = org_list;
	while (curr != NULL)
	{
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
	}
	return (42);

}*/
