/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:47:44 by melayoub          #+#    #+#             */
/*   Updated: 2023/04/16 02:54:07 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	void ft_indexer(t_list *content)
	{
		t_list *temp;
		t_list *temper;
		temp = content;
		while (temp)
		{
			temper = content;
			while (temper)
			{
				if (temper->value > temp->value)
					temper->index++;
				temper = temper->next;
			}
			temp = temp->next;
		}
	}

int	main(int ac, char **av)
{
	p_list content;
	t_list *stack_a;
	// t_list *stack_b;
	int i;

	i = ac - 1;
	printf("ele: %d\n", content.elements);
	stack_a = NULL;
	ft_splitter(&content, ac, av);
	while(i > 0)
	{
		ft_new_node(&stack_a, ft_lstnew(ft_atoi(av[i])));
		i--;
	}
	ft_indexer(stack_a);

	t_list *h = stack_a;
	while (h)
	{
		printf("value = %ld || index = %d\n", h->value, h->index);
		h = h->next;
	}
	puts("------------------------");
	ft_rra(&stack_a, 1);
	h = stack_a;
	while (h)
	{
		printf("value = %ld || index = %d\n", h->value, h->index);
		h = h->next;
	}
	puts("------------------------");
	// ft_ra(&head);
	// while (head)
	// {
	// 	printf("value = %ld || index = %d\n", head->value, head->index);
	// 	head = head->next;
	// }
	// printf("after sa: %s\n", av[1]);
	// iter = head;
	// while (iter)
	// {
	// 	printf("the value %ld and the index %d\n", iter->value, iter->index);
	// 		iter = iter->next;
	// }
	// ft_indexer(av, content.elements);
	// while(content.elements)
	// printf("av1: %s", av[1]);
	return (0);	

}
