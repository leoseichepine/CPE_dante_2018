##
## EPITECH PROJECT, 2018
## makefile csfml
## File description:
## makefile csfml
##

SRC			=	src/main.c\
				src/maze/load_maze.c\
				src/maze/error_handling.c\
				src/utils/error_handling.c\
				src/utils/general_1.c\
				src/list/list.c\
				src/algo/find_path.c\
				src/utils/my_strlen.c

NAME		=	solver

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Iinclude

INCLUDE		=	-I./include/solver.h

LIBFLAGS	=	-Llib/my -lmy

all			:	$(NAME) clean

debug		:
				gcc -o  $(NAME) $(SRC) $(CFLAGS) -g

$(NAME)		:	$(OBJ)
				gcc -g -o $(NAME) $(OBJ) $(INCLUDE) $(CFLAGS)

clean		:
				rm -f $(OBJ)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
