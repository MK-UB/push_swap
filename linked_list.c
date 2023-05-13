/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:11:56 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/13 16:58:34 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int c)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr != NULL)
	{
		ptr->data = c;
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

int	ft_lst_size(t_list *lst)
{
	int		count;
	t_list	*tmp;

	if (!lst)
		return (-1);
	count = 0;
	tmp = lst;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
