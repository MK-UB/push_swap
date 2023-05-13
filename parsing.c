/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:36:23 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/13 15:53:52 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isequal(char **av, int elements)
{
	int	x;
	int	j;

	j = 0;
	while (j <= elements - 2)
	{
		x = j + 1;
		while (x <= elements -1)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[x]))
				ft_error();
				x++;
		}
		j++;
	}
}

int	ft_checker(char **av, int elements)
{
	int	j;
	int	i;

	j = 0;
	while (j < elements)
	{
		if (ft_atoi(av[j]) > 2147483647 || ft_atoi(av[j]) < -2147483648)
			ft_error();
		i = 0;
		while (av[j][i])
		{
			if ((av[j][i] == '-' || av[j][i] == '+') && (i != 0 && av[j][i - 1]))
				ft_error();
			if ((av[j][i] >= '0' && av[j][i] <= '9')
			|| av[j][i] == '-' || av[j][i] == '+' || av[j][i] == ' '
			|| (av[j][i] == ' ' && (av[j][i + 1] == '-' || av[j][i + 1] == '+')
			&& (av[j][i + 2] >= '0' && av[j][i + 1] <= '9')))
				i++;
			else
				return (0);
		}
		j++;
	}
	return (1);
}

void	ft_sortcheck(char **av)
{
	int	j;

	j = 0;
	if (av[j + 1] && ft_atoi(av[j]) < ft_atoi(av[j + 1]))
	{
		while (ft_atoi(av[j]) < ft_atoi(av[j + 1]))
		{
			j++;
			if (av[j + 1] == '\0')
				exit(0);
		}
	}
}
