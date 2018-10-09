NAME = libftprintf.a

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I includes/

SRC_FILES = parse.c \
			printf.c \
			parse_functions.c

.PHONY = all clean fclean clean re

SRCS = $(addprefix src/, $(SRC_FILES))

OBJ = $(SRCS:.c=.o)
LIBOBJ = $(LIBSRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
		gcc -c $(CFLAGS) $< -o $@

$(NAME):  $(OBJ)
		@make -C libft/
		@ar rcs $(NAME) $(OBJ) $(LIBOBJ) libft/*.o
		@echo "Created libftprintf!!\n"

clean:
		@rm -rf $(OBJ) $(LIBOBJ)
		@echo "removed object files"

fclean: clean
		@rm -rf $(NAME)
		@echo "Removed executable file"

re: fclean all
