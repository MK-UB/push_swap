/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:21:49 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/16 19:31:46 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	max_handler(char **str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (ft_strlen(str[a]) > ft_strlen("+2147483647"))
		{
			write (1, "Error\n", 7);
			exit (0);
		}
		else if (ft_atoi(str[a]) > INT_MAX || ft_atoi(str[a]) < INT_MIN)
		{
			write (1, "Error\n", 7);
			exit (0);
		}
		a++;
	}
}

char	**ft_splitter(t_plist *content, int ac, char **av)
{
	int			x;
	char		*str;
	char		**splt;
	char		*ss;

	str = NULL;
	x = 1;
	while (x != ac)
	{
		ss = ft_strtrim(av[x], " ");
		str = ft_strjoin(str, ss);
		free(ss);
		if (!*str)
			ft_error();
		str = ft_strjoin(str, " ");
		x++;
	}
	content->elements = ft_counter(str);
	splt = ft_split(str, ' ');
	free (str);
	max_handler(splt);
	if (!ft_checker(splt, content->elements))
		ft_error();
	ft_isequal(splt, content->elements);
	return (splt);
}
