CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = program

SRC = get_next_line_utils.c \
	  get_next_line.c \
	  main.c

HEADER = get_next_line.h

RM = rm -r

OBJ = $(SRC:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)
	echo "Program Compiled Succesfully"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	echo "OBJ files deleted"

fclean: clean
	$(RM) $(NAME)
	echo "Program deleted"

re: all

.PHONY: all clean fclean re
