/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:48:02 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/12 16:13:47 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **a, int flag)
{
	t_list	*first;
	t_list	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (flag)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list **b, int flag)
{
	t_list	*first;
	t_list	*second;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (flag)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **a, t_list **b, int flag)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	if (flag)
		write(1, "ss\n", 3);
}
