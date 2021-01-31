##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME	=	libmy.a

CC	=	gcc

RM	=	rm -f

SRC	=	$(shell find . -type f -name '*.c')

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ./../
	mkdir -p ./../../include
	cp my.h ./../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *~

re: fclean all
