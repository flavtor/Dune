##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME	=	Dune

CC	=	gcc

RM	=	rm -f

SOURCE	=	./src/

CSFML   =       -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CREATE	=	./src/create/

DISPLAY	=	./src/display/

MANAGE	=	./src/manage/

SPRITES	=	./src/sprites/

WINDOW	=	./src/window/

SRC	=	src/main.c				\
		src/destroy.c 			\
		src/display_window.c		\
		src/launch_menu.c		\
		src/hub.c			\
		src/create_player.c		\
		src/move.c			\
		src/create_dialog.c		\
		src/grotte.c			\
		src/game_over.c			\
		src/scene_f.c			\
		src/finale.c			\
		src/move_monsters.c		\
		src/create_monster.c		\
		src/move_sprite.c		\
		src/verif_max_size.c		\
		src/scene_r.c			\
		src/final_fight.c		\
		src/winner.c

OBJ	=	$(SRC:.c=.o)

LDFlAGS	=	-L ./lib/ -lmy

CPPFLAGS	=	-I ./include/

CFLAGS	=	-Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFlAGS) $(CSFML) -g3
	$(RM) -f *.gcda *.gcno


clean:
	make clean -C lib/my
	$(RM) $(NAME)
	$(RM) $(OBJ) *~ \#*\#

fclean: clean
	make fclean -C lib/my
	$(RM) -fr lib/libmy.a

re: fclean all

.PHONY:	all fclean re
