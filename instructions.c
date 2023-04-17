/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:48:02 by melayoub          #+#    #+#             */
/*   Updated: 2023/04/16 02:25:26 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #define ft_sa(stack) ft_s(stack, 'a')
// #define ft_sb(stack) ft_b(stack, 'b')

void ft_sa(t_list **a, int flag)
{
    t_list *first;
    t_list *second;

    // Check if there are at least two elements in the stack
    if (*a == NULL || (*a)->next == NULL)
        return;
    // Sw*ap the first two elements in the st*ack
    first = *a;
    second = (*a)->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    if (flag)
        printf("sa\n");
}

void ft_sb(t_list **b, int flag)
{
    t_list *first;
    t_list *second;

    // Check if there are at least two elements in the stack
    if (*b == NULL || (*b)->next == NULL)
        return;
    // Sw*bp the first two elements in the st*bck
    first = *b;
    second = (*b)->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    if (flag)
        printf("sb\n");
}

void ft_ss(t_list **a, t_list **b)
{
    ft_sa(a, 0);
    ft_sb(b, 0);
    write(1, "ss\n", 3);
}




void    ft_ra(t_list **a, int flag)
{
    t_list *first;
    t_list *last;



    // Check if there are at least two elements in the stack
    if (*a == NULL || (*a)->next == NULL)
        return;
    // swap first and last element in the stack
    first = *a;
    last = ft_lstlast(*a);
    *a = (*a)->next;
    last->next = first;
    last->next->next = NULL;
    if (flag)
        write(1, "ra\n", 3);
}

void    ft_rb(t_list **b, int flag)
{
    t_list *first;
    t_list *last;

    // Check if there are at least two elements in the stack
    if (*b == NULL || (*b)->next == NULL)
        return;
    // swap first and last element in the stack
    first = *b;
    last = ft_lstlast(*b);
    *b = (*b)->next;
    last->next = first;
    last->next->next = NULL;
    if (flag)
        write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	write(1, "rr\n", 3);
}

void	ft_rra(t_list **a, int flag)
{
    t_list *first;
    t_list *before_last;

    if (*a == NULL || (*a)->next == NULL)
        return;
    first = *a;
    before_last = ft_lstblast(*a);
    *a = before_last->next;
    (*a)->next = first;
    before_last->next = NULL;
    if (flag)
        write(1, "rra\n", 4);
}

void	ft_rrb(t_list **b, int flag)
{
    t_list *first;
    t_list *before_last;

    if (*b == NULL || (*b)->next == NULL)
        return;
    first = *b;
    before_last = ft_lstblast(*b);
    *b = before_last->next;
    (*b)->next = first;
    before_last->next = NULL;
    if (flag)
        write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	write(1, "rrr\n", 4);
}