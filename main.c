/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:47:44 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/17 22:24:06 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexer(t_list *content)
{
	t_list	*temp;
	t_list	*temper;

	temp = content;
	while (temp)
	{
		temper = content;
		while (temper)
		{
			if (temper->data > temp->data)
				temper->index++;
			temper = temper->next;
		}
		temp = temp->next;
	}
}

void	ft_setup(t_plist *content, int ac, char **av)
{
	char	**splt;
	int		i;

	content->stack_a = NULL;
	content->stack_b = NULL;
	splt = ft_splitter(content, ac, av);
	ft_sortcheck(splt);
	i = str_tab_len(splt) - 1;
	while (i >= 0)
		ft_new_node(&content->stack_a, ft_lstnew(ft_atoi(splt[i--])));
	i = 0;
	while (splt[i])
		free(splt[i++]);
	free(splt);
}

int	main(int ac, char **av)
{
	t_plist	content;

	if (ac == 1)
		exit(0);
	ft_setup(&content, ac, av);
	content.elements = ft_lst_size(content.stack_a);
	ft_indexer(content.stack_a);
	if (content.elements >= 2 && content.elements <= 3)
		sort_three(&content.stack_a);
	else if (content.elements >= 4 && content.elements <= 5)
		sort_five(&content.stack_a, &content.stack_b);
	else if (content.elements >= 6 && content.elements <= 100)
		sort_hundred(&content.stack_a, &content.stack_b);
	else if (content.elements > 100)
		sort_five_hundred(&content.stack_a, &content.stack_b);
	while (content.stack_a)
	{
		free(content.stack_a);
		content.stack_a = content.stack_a->next;
	}
	return (0);
}
