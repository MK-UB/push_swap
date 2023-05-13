/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:48:34 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/12 13:46:01 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hundred(t_list **a, t_list **b)
{
	int	i;
	int	j;

	i = 0;
	j = 13;
	while (*a)
	{
		if ((*a)->index < i)
		{
			push_x_to_y(a, b, 2, 1);
			i++;
		}
		else if ((*a)->index < (j + i))
		{
			push_x_to_y(a, b, 2, 1);
			ft_rb(b, 1);
			i++;
		}
		else
			ft_ra(a, 1);
	}
	while (*b)
		ft_back_to_a(a, b);
}

void	sort_five_hundred(t_list **a, t_list **b)
{
	int	i;
	int	j;

	i = 0;
	j = 45;
	while (*a)
	{
		if ((*a)->index < i)
		{
			push_x_to_y(a, b, 2, 1);
			i++;
		}
		else if ((*a)->index < (j + i))
		{
			push_x_to_y(a, b, 2, 1);
			ft_rb(b, 1);
			i++;
		}
		else
			ft_ra(a, 1);
	}
	while (*b)
		ft_back_to_a(a, b);
}
