##
## EPITECH PROJECT, 2018
## makefile csfml
## File description:
## makefile csfml
##

SRC		=	src/main.c\
			src/setup.c\
			src/utils/general_1.c\
			src/utils/print.c

NAME		=	generator

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Iinclude

INCLUDE		=	-I./include/

LIBFLAGS	=	-Llib/my -lmy

all:			$(NAME) clean

debug:
			gcc -o  $(NAME) $(SRC) $(CFLAGS) -g

$(NAME):		$(OBJ)
			gcc -g -o $(NAME) $(OBJ) $(INCLUDE) $(CFLAGS)

copy:
			cp $(NAME) ../tournament

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
