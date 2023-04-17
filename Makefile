# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 17:45:41 by melayoub          #+#    #+#              #
#    Updated: 2023/04/12 01:28:39 by melayoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS= -Wall -Wextra -Werror

SRCS= main.c parsing.c utils_ps.c utils_splitter.c linked_list.c instructions.c

OBJS= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) -c $(FLAGS) $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o ${NAME}

clean:
	@rm -f $(OBJS)

fclean:clean
	@rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re