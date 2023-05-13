/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionsss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:22:10 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/13 15:22:33 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **a, int flag)
{
	t_list	*first;
	t_list	*before_last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	before_last = ft_lstblast(*a);
	*a = before_last->next;
	(*a)->next = first;
	before_last->next = NULL;
	if (flag)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **b, int flag)
{
	t_list	*first;
	t_list	*before_last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	before_last = ft_lstblast(*b);
	*b = before_last->next;
	(*b)->next = first;
	before_last->next = NULL;
	if (flag)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b, int flag)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (flag)
		write(1, "rrr\n", 4);
}

void	push_x_to_y(t_list **x, t_list **y, int flag, int reflag)
{
	t_list	*tmp;

	if (*x == NULL)
		return ;
	tmp = *x;
	*x = (*x)->next;
	tmp->next = *y;
	*y = tmp;
	if (flag == 1 && reflag == 1)
		write(1, "pa\n", 3);
	else if (flag == 2 && reflag == 1)
		write(1, "pb\n", 3);
}
