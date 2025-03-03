CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = ft_printf.c \
		ft_putchar.c \
		ft_puth.c \
		ft_putnbr.c \
		ft_putnbru.c \
		ft_putp.c \
		ft_putstr.c \
		ft_strlen.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ) 

re: clean all

.PHONY: all clean fclean re
