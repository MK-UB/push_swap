/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:35:55 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/17 22:37:45 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_clear(t_list **lst)
{
	t_list	*next_lst;
	t_list	*current_lst;

	if (!lst)
		return ;
	next_lst = *lst;
	while (next_lst)
	{
		current_lst = next_lst;
		next_lst = next_lst->next;
		free(current_lst);
	}
	*lst = NULL;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_check_node(t_list *a)
{
	t_list	*head;

	head = a;
	while (head && head->next)
	{
		if (head->data > head->next->data)
			return (1);
		head = head->next;
	}
	return (0);
}
