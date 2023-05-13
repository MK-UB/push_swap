/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:48:56 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/12 13:44:10 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos(t_list *stack, int index)
{
	int	pos;

	pos = 1;
	while (stack && stack->index != index)
	{
		pos += 1;
		stack = stack->next;
	}
	return (pos);
}

int	halfer(t_list *stack)
{
	int	half;

	half = 0;
	if (stack)
		half = ft_lst_size(stack) / 2;
	return (half);
}

void	top_half(t_list **b, t_list **a, int index_max)
{
	while (1)
	{
		if ((*b)->index == index_max)
		{
			push_x_to_y(b, a, 1, 1);
			break ;
		}
		ft_rb(b, 1);
	}
}

void	bottom_half(t_list **b, t_list **a, int index_max)
{
	while (1)
	{
		if ((*b)->index == index_max)
		{
			push_x_to_y(b, a, 1, 1);
			break ;
		}
		ft_rrb(b, 1);
	}
}

void	ft_back_to_a(t_list **a, t_list **b)
{
	int	index_max;

	index_max = ft_lst_size(*b) - 1;
	if (pos(*b, index_max) <= halfer(*b))
		top_half(b, a, index_max);
	else if (pos(*b, index_max) > halfer(*b))
		bottom_half(b, a, index_max);
}
