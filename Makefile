# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenece <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/26 13:22:37 by adenece           #+#    #+#              #
#    Updated: 2016/06/02 16:23:55 by adenece          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=fdf

FLAGS	=	-Wall -Werror -Wextra

INCLUDES	= -I ./libft

HEADERS	=	fdf.h libft/libft.h

MLX		= -L/usr/local/lib/ -I/usr/local/include -lmlx -framework	\
			OpenGL -framework AppKit

SRC	= free.c main.c rotate.c rotate_map.c get_stuff.c trace_lines.c \
	  place_points.c

OBJ	= $(SRC:.c=.o)

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(SRC) $(INCLUDES) $(MLX) -L./libft -lft

libft/libft.a: $(OBJ_LIBFT)
	ar rc libft/libft.a $(OBJ_LIBFT)

%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@make fclean -C ./libft

re: fclean clean all

#.PHONY.: all $(NAME) clean fclean re
