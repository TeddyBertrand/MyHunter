##
## EPITECH PROJECT, 2024
## B-MUL-100-MPL-1-1-myhunter-teddy.bertrand
## File description:
## Makefile
##

NAME = my_hunter

SRC = $(shell find -name "*.c")

FLAGS = -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

WFLAGS = -W -Werror -Wextra -Wall

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS) $(WFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
