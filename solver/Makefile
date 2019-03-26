##
## EPITECH PROJECT, 2018
## Day10
## File description:
## makefile
##

SRC	=

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

INCLUDE = 	-I./include/my.h

all :		$(NAME)

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(OBJ) $(INCLUDE)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all
