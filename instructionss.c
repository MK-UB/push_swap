/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:20:53 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/12 13:31:54 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **a, int flag)
{
	t_list	*first;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = first;
	last->next->next = NULL;
	if (flag)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **b, int flag)
{
	t_list	*first;
	t_list	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	last = ft_lstlast(*b);
	*b = (*b)->next;
	last->next = first;
	last->next->next = NULL;
	if (flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b, int flag)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	if (flag)
		write(1, "rr\n", 3);
}
