# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 10:35:01 by dabi-rac          #+#    #+#              #
#    Updated: 2023/03/11 10:35:03 by dabi-rac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = maps.c map_read.c main.c libft_utils.c \

OBJ = $(SRC.c=.o)

LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/


FLAG = -Wall -Werror -Wextra
CC = gcc

all : 
		make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SRC) $(LIBRARY) -o $(NAME) -lz -g

clean: 
	make clean -C $(MINILIBX)
	rm -f $(OBJ)
	
fclean:	clean
	rm -f $(NAME)

re:	fclean all clean

.PHONY: all clean fclean re
