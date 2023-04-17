/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:36:23 by melayoub          #+#    #+#             */
/*   Updated: 2023/04/02 21:44:15 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_counter(char *av)
{
	int	i;
	int	elements;

	elements = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] == ' ' && av[i + 1] != ' ' && av[i + 1] != '\0')
			i++;
		if (av[i] != ' ' && av[i + 1] == ' ')
			elements++;
		i++;
	}
	return (elements);
}

void	ft_isequal(char **av, int elements)
{
	int	x;
	int	j;

	//av = &av[1];
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
		if (!ft_atoi(av[j]))
			ft_error();
		i = 0;
		while (av[j][i])
		{
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
	if (ft_atoi(av[j]) < ft_atoi(av[j + 1]))
	{
		while (ft_atoi(av[j]) < ft_atoi(av[j + 1]))
		{
			j++;
			if (av[j + 1] == '\0')
			{
				write(1, "already sorted\n", 16);
				exit(0);
			}
		}
	}
}

void	ft_splitter(p_list *content, int ac, char **av)
{
	int			x;
	char		*str;

	str = ft_strdup(" ");
	x = 1;
	while (x != ac)
	{
		str = ft_strjoin(str, av[x]);
		str = ft_strjoin(str, " ");
		x++;
	}
	content->elements = ft_counter(str);
	if (content->elements < 2)
		ft_error();
	av = ft_split(str, ' ');
	if (!ft_checker(av, content->elements))
		ft_error();
	ft_isequal(av, content->elements);
	ft_sortcheck(av);
	}
