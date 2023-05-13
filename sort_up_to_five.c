/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:40:46 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/12 18:34:00 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	if ((*a)->next->next == NULL)
	{
		ft_sa(a, 1);
		return ;
	}
	if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->next->next->data)
		ft_sa(a, 1);
	if ((*a)->data > (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		ft_sa(a, 1);
		ft_rra(a, 1);
	}
	if ((*a)->data > (*a)->next->data
		&& (*a)->next->data < (*a)->next->next->data)
		ft_ra(a, 1);
	if ((*a)->next->next->data < (*a)->next->data
		&& (*a)->next->next->data > (*a)->data)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	if ((*a)->data < (*a)->next->data && (*a)->data > (*a)->next->next->data)
		ft_rra(a, 1);
}

static void	lowest_index_pusher(t_list **a, t_list **b)
{
	while ((*a)->next)
	{
		if ((*a)->index == 0)
		{
			push_x_to_y(a, b, 2, 1);
			return ;
		}
		ft_ra(a, 1);
	}
}

static void	second_lowest_index_pusher(t_list **a, t_list **b)
{
	while ((*a)->next)
	{
		if ((*a)->index == 1)
		{
			push_x_to_y(a, b, 2, 1);
			return ;
		}
		ft_ra(a, 1);
	}
}

void	sort_five(t_list **a, t_list **b)
{
	if ((*a)->next->next->next->next == NULL)
		lowest_index_pusher(a, b);
	else
	{
		lowest_index_pusher(a, b);
		second_lowest_index_pusher(a, b);
	}
	sort_three(a);
	push_x_to_y(b, a, 1, 1);
	if (*b != NULL)
		push_x_to_y(b, a, 1, 1);
}
