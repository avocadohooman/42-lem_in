# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 11:13:09 by hopham            #+#    #+#              #
#    Updated: 2020/06/25 11:19:28 by HoangPham        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = ./libft/libft.a
LIB_FOLDER = ./libft/
FLAGS =  -g

SRCS = ./srcs/
ALGO_FUNC = algorithm/*.c
GET_INPUT_FUNC = get_input/*.c
FUNC = $(ALGO_FUNC) $(GET_INPUT_FUNC) lem_in.c error.c

FILES_C = $(addprefix $(SRCS), $(FUNC))
OBJ = *.o

INCLUDES = -I ./libft/ft_printf/includes/ -I ./libft/libft/includes/ -I ./includes/

all: library $(NAME)

library:
		make -C $(LIB_FOLDER)

$(NAME): all
		gcc  $(FLAGS) $(INCLUDES) -c $(FILES_C)
		gcc $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJ) $(LIB)

clean:
		rm -rf $(OBJ)
		make clean -C $(LIB_FOLDER)

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIB_FOLDER)

re: fclean all

.PHONY: library all fclean re 