# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 11:13:09 by hopham            #+#    #+#              #
#    Updated: 2020/02/19 10:12:39 by gmolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = ./libft/libft.a
LIB_FOLDER = ./libft/
FLAGS = -Wextra -Werror -Wall -g

SRCS = ./srcs/
FUNC = lem_in.c input_scan.c error.c initiate_structs.c add_rooms.c add_links.c

FILES_C = $(addprefix $(SRCS), $(FUNC))
OBJ = $(FUNC:.c=.o)

INCLUDES = -I ./libft/ft_printf/includes/ -I ./libft/libft/includes/ -I ./includes/

all: library $(NAME)

library:
		make -C $(LIB_FOLDER)

$(NAME): all
		gcc $(FLAGS) $(INCLUDES) -c $(FILES_C)
		gcc $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJ) $(LIB)

clean:
		rm -rf $(OBJ)
		make clean -C $(LIB_FOLDER)

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIB_FOLDER)

re: fclean all

.PHONY: library all fclean re 