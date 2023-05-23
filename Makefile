MINILIBX_PATH	=	./minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	main.c utils_libft.c map_draw.c map_read.c  map_check.c player_move.c \

HEADER			=	./so_long.h

OBJECTS			= 	$(SOURCES_FILES:.c=.o)

NAME			=	so_long

CC				=	gcc

RM				=	rm -f

MLX				=	./libmlx.dylib

FLAGS			=	-Wall -Wextra -Werror

MLX_FLAGS		=	-lmlx -framework OpenGL -framework AppKit

%.o:%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJECTS)
				$(CC) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)

$(MINILIBX):
	make -C $(MINILIBX_PATH)

clean:
				$(RM) $(OBJECTS) $(NAME)
				make clean -C $(MINILIBX_PATH)

fclean:			clean
					rm -f $(NAME)
					rm -f $(MINILIBX)

re:				fclean all

.PHONY:			all clean fclean re