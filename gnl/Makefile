CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftgnl.a

SRC =	get_next_line.c \
		get_next_line_utils.c \

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
