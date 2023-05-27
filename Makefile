##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	main

$(NAME):
		@make -s re -C solver
		@make -s re -C generator
		@make -s clean

all:	$(NAME)

clean:
		@make -s clean -C solver
		@make -s clean -C generator

fclean:	clean
		@make -s fclean -C solver
		@make -s fclean -C generator

re:    fclean all
