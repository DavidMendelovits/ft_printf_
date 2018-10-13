NAME = libftprintf.a

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I includes/ -I libft/

SRC_FILES = parse.c \
			printf.c \
			parse_functions.c \
			string.c \
			wide_char.c \
			dispatch.c \
			decimal.c \
			conversions.c 

.PHONY = all clean fclean clean re

SRCS = $(addprefix src/, $(SRC_FILES))

OBJ = $(SRCS:.c=.o)

TEST = a.out

all: $(NAME)

$(OBJ): %.o: %.c
		gcc -c $(CFLAGS) $< -o $@

$(NAME):  $(OBJ)
		@make -C libft/
		@ar rcs $(NAME) $(OBJ) libft/*.o
		@echo "Created libftprintf!!\n"

clean:
		@rm -rf $(OBJ)
		@echo "removed object files"

fclean: clean
		@rm -rf $(NAME)
		@echo "Removed executable file"

#test: $(OBJ) 
#	@make -C libft/
# @gcc -g main.c $(OBJ) libft/*.o $(CFLAGS) -o $(TEST)

re: fclean all
