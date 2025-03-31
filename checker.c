/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:56:29 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/17 22:37:37 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_instructions(t_list **stack_a, t_list **stack_b, char *s)
{
	if (!ft_strcmp(s, "sa\n"))
		ft_sa(stack_a, 0);
	else if (!ft_strcmp(s, "sb\n"))
		ft_sb(stack_b, 0);
	else if (!ft_strcmp(s, "ss\n"))
		ft_ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(s, "pa\n"))
		push_x_to_y(stack_b, stack_a, 1, 0);
	else if (!ft_strcmp(s, "pb\n"))
		push_x_to_y(stack_a, stack_b, 2, 0);
	else if (!ft_strcmp(s, "ra\n"))
		ft_ra(stack_a, 0);
	else if (!ft_strcmp(s, "rb\n"))
		ft_rb(stack_b, 0);
	else if (!ft_strcmp(s, "rr\n"))
		ft_rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(s, "rra\n"))
		ft_rra(stack_a, 0);
	else if (!ft_strcmp(s, "rrb\n"))
		ft_rrb(stack_b, 0);
	else if (!ft_strcmp(s, "rrr\n"))
		ft_rrr(stack_a, stack_b, 0);
	else
		return (write(1, "Error\n", 6), exit(1));
}

void	ft_setup(t_plist *content, int ac, char **av)
{
	char	**splt;
	int		i;

	splt = ft_splitter(content, ac, av);
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
	char	*s;

	if (ac == 1)
		exit(0);
	ft_setup(&content, ac, av);
	s = get_next_line(0);
	while (s)
	{
		do_instructions(&content.stack_a, &content.stack_b, s);
		free(s);
		s = get_next_line(0);
	}
	free(s);
	if (!ft_check_node(content.stack_a) && !content.stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lst_clear(&content.stack_a);
	return (0);
}
