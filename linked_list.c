/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:11:56 by melayoub          #+#    #+#             */
/*   Updated: 2023/04/15 22:36:17 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int c)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr != NULL)
	{
		ptr->value = c;
		ptr->next = NULL;
		ptr->index = 0;
	}
	return (ptr);
}

void	ft_new_node(t_list **head, t_list *new)
{
	if (head && new)
	{
		new->next = *head;
		*head = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == '\0')
			return (lst);
		lst = lst->next;
	}
	return (0);
}

t_list	*ft_lstblast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next->next == '\0')
			return (lst);
		lst = lst->next;
	}
	return (0);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// void	ft_indexer(char **av, int elements)
// {
// 	int i;
// 	int x;

// 	i = 0;
// 	x = 0
// 	while (i <= elements)
// 	{
// 		if (av[i] < av[j])

// 	}
// }