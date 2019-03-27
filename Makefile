##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## dante
##

all	:
		make -C generator/

clean	:
		make clean -C generator/

fclean	:
		make fclean -C generator/

re	:
		make re -C generator/
