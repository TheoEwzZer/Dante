##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	generator

CC		=	gcc -g3
RM		=	rm -rf

SRC		=	$(shell find -type f -name "*.c")

OBJ		=	$(SRC:.c=.o)

LIB		=	-I../include

WARN1 = 	-W -Wall -Wextra -pedantic -Wformat-nonliteral -Wformat-signedness \
			-Wfloat-equal -Wundef -Wwrite-strings -Wcast-align \
			-Wstrict-overflow=5 -Wdeclaration-after-statement

WARN2 = 	-Wconversion -Wunsuffixed-float-constants -Wmissing-prototypes \
			-Wcast-qual -Wswitch-default -Wswitch-enum -Wunreachable-code \
			-Wmissing-declarations -Wsequence-point

WARN3 = 	-Wunused-macros -Warith-conversion -Wmissing-include-dirs \
			-Wunused-parameter -Wuninitialized -Wduplicated-branches \
			-Wmissing-include-dirs -Wparentheses

WARN4 = 	-Wduplicated-cond -Wshadow -Wformat-truncation=2 \
			-Wformat-overflow -Wformat-security -Wformat=2 -Wnull-dereference \
			-Wold-style-definition

$(NAME):
		@$(CC) -o $(NAME) $(SRC) $(WARN1) $(WARN2) $(WARN3) $(WARN4) $(LIB)
		@make -s clean

all:	$(NAME)

clean:
		@$(RM) $(OBJ)

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
