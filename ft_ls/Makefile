CC		=	gcc
CFLAGS	=	-I Includes -Wall -Wextra -Werror
SRC		=	Sources/main.c			\
			Sources/param.c			\
			Sources/dirinfos.c		\
			Sources/display.c		\
			Sources/display_long.c	\
			Sources/list.c			\
			Sources/cmp.c			\
			Sources/sort_arg.c		\
			Sources/ft_ls.c			\
			Sources/error.c
OBJ		=	$(SRC:.c=.o)
LIBS	=	Libs/libft
NAME	=	ft_ls

$(NAME): $(OBJ)
	@echo "\033[32m[OK]\033[0m	libft compiled."
	@make -C $(LIBS)
	@$(CC) -L$(LIBS) -lft -o $@ $^
	@echo "\033[32m[OK]\033[0m	ft_ls created."

all: $(NAME)
		
%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[32m[OK]\033[0m	object files deleted."
	@rm -rf $(OBJ)
	@make clean -C $(LIBS)

fclean: clean
	@echo "\033[32m[OK]\033[0m	ft_ls deleted."
	@rm -rf $(NAME)
	@make fclean -C $(LIBS)

re: fclean all
