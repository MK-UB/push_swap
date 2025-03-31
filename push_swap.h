/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:40:21 by melayoub          #+#    #+#             */
/*   Updated: 2023/05/17 22:39:23 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	long			data;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct ps_list
{
	int				elements;
	t_list			*stack_a;
	t_list			*stack_b;
}					t_plist;

int					ft_checker(char **av, int elements);
void				ft_isequal(char **av, int elements);
void				ft_sortcheck(char **av);
void				sort_three(t_list **a);
void				sort_five(t_list **a, t_list **b);
void				sort_hundred(t_list **a, t_list **b);
void				sort_five_hundred(t_list **a, t_list **b);
void				ft_back_to_a(t_list **a, t_list **b);
void				ft_sa(t_list **a, int flag);
void				ft_sb(t_list **b, int flag);
void				ft_ss(t_list **a, t_list **b, int flag);
void				ft_ra(t_list **a, int flag);
void				ft_rb(t_list **b, int flag);
void				ft_rr(t_list **a, t_list **b, int flag);
void				ft_rra(t_list **a, int flag);
void				ft_rrb(t_list **b, int flag);
void				ft_rrr(t_list **a, t_list **b, int flag);
void				push_x_to_y(t_list **x, t_list **y, int flag, int reflag);
size_t				ft_strlen(char *str);
void				ft_error(void);
long				ft_atoi(const char *str);
char				*ft_strdup(char *src);
char				*ft_strjoin(char *str1, char *str2);
char				**ft_split(char *s, char c);
char				**ft_splitter(t_plist *content, int ac, char **av);
int					ft_counter(char *av);
t_list				*ft_lstnew(int c);
void				ft_new_node(t_list **head, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstblast(t_list *lst);
int					ft_lst_size(t_list *lst);
int					str_tab_len(char **str);
char				*ft_strtrim(char *s1, char *set);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*get_next_line(int fd);
int					str_tab_len(char **str);
void				ft_lst_clear(t_list **lst);
int					ft_strcmp(char *s1, char *s2);
int					ft_check_node(t_list *a);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#endif