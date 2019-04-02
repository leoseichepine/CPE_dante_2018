##
## EPITECH PROJECT, 2018
## Day10
## File description:
## makefile
##

SRC	=	generate_map.c			\
		imperfect_maze.c		\
		perfect_maze.c			\
		my_str_isnum.c			\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

INCLUDE = 	-I./include/my.h

all :		$(NAME) copy

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(OBJ) $(INCLUDE)

copy :
	cp $(NAME) ../tournament

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all
