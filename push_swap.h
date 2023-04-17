/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:40:21 by melayoub          #+#    #+#             */
/*   Updated: 2023/04/16 01:49:23 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct s_list
{
	long			value;
	int				index;
	struct s_list	*next;
}				t_list;

typedef struct	ps_list
{
	int		elements;

}                p_list;

// typedef struct s_list
// {
// 	long			value;
// 	int				index;
// 	struct s_list	*next;
// 	struct s_list	*previous;
// }				t_list;

void	ft_sa(t_list **a, int flag);
void	ft_sb(t_list **b, int flag);
void	ft_ss(t_list **a, t_list **b);
void    ft_ra(t_list **a, int flag);
void    ft_rb(t_list **b, int flag);
void    ft_rr(t_list **a, t_list **b);
void	ft_rra(t_list **a, int flag);
void	ft_rrb(t_list **b, int flag);
void	ft_rrr(t_list **a, t_list **b);
size_t	ft_strlen(char *str);
void	ft_error();
long	ft_atoi(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *str1, char *str2);
char	**ft_split(char *s, char c);
void	ft_splitter(p_list *content, int ac, char **av);
int		ft_counter(char *av);
t_list  *ft_lstnew(int c);
void	ft_new_node(t_list **head, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstblast(t_list *lst);


#endif