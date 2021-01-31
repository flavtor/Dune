##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME	=	game_jam

CC	=	gcc

RM	=	rm -f

SOURCE	=	./src/

CSFML   =       -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CREATE	=	./src/create/

DISPLAY	=	./src/display/

MANAGE	=	./src/manage/

SPRITES	=	./src/sprites/

WINDOW	=	./src/window/

SRC	=	main.c			\
		destroy.c 		\
		display_window.c	\
		launch_menu.c		\
		hub.c			\
		create_player.c		\
		move.c			\
		create_dialog.c		\
		grotte.c		\
		game_over.c		\
		scene_f.c		\
		finale.c		\
		move_monsters.c		\
		create_monster.c	\
		move_sprite.c		\
		verif_max_size.c	\
		scene_r.c		\
		final_fight.c

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
