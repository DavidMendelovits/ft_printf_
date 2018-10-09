NAME = libftprintf.a

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I includes/

SRC_FILES = string.c \
			convert_length.c \
			init_struct.c \
			parse.c \
			flags.c \
			more_flags.c \
			printf.c \
			specifiers.c \
			decimal.c \
			ft_putnbr_base.c \
			hex.c \
			decimal2.c \
			unsigned.c 

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
