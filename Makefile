# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 17:45:41 by melayoub          #+#    #+#              #
#    Updated: 2023/05/18 13:20:40 by melayoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

CC = cc

FLAGS= -Wall -Wextra -Werror

SRC_M= utils_base.c parsing.c utils_trimmer.c utils_splitter.c init.c  main.c \
linked_list.c instructions.c instructionss.c instructionsss.c \
sort_big_utils.c sort_up_to_five.c sort_max.c 

SRC_B= utils_base.c parsing.c utils_trimmer.c utils_splitter.c init.c \
linked_list.c instructions.c instructionss.c instructionsss.c \
checker.c gnl.c utils_checker.c

OBJ_M= $(SRC_M:.c=.o)
OBJ_B= $(SRC_B:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

%.o: %.c push_swap.h
	$(CC) -c $(FLAGS) $<

$(NAME): $(OBJ_M)
	$(CC) $(OBJ_M) -o ${NAME}

$(NAME_B): $(OBJ_B)
	$(CC) $(OBJ_B) -o ${NAME_B}

clean:
	@rm -f $(OBJ_M) $(OBJ_B)

fclean: clean
	@rm -f  $(NAME) $(NAME_B)

re: fclean all
