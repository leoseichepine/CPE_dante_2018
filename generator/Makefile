##
## EPITECH PROJECT, 2018
## Day10
## File description:
## makefile
##

SRC	=	imperfect_maze.c	\
		perfect_maze.c		\
		my_strcmp.c			\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

INCLUDE = 	-I./include/my.h

all :		$(NAME)

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(OBJ) $(INCLUDE)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all
