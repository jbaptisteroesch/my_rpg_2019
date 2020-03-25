##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		src/main.c	\
				src/usage.c	\
				src/create_window.c	\
				src/create_button.c	\
				src/create_element.c	\
				src/leave_state_if_error.c	\
				src/main_menu/main_menu.c	\
				src/in_game/pause_menu/pause_menu.c	\
				src/settings_menu/settings_menu.c	\
				src/in_game/in_game/in_game.c	\
				

NAME	=		my_rpg

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-I./include	\
				-Wall

OFLAGS	=		-O2

LDFLAGS	= 	-lcsfml-graphics \
			-lcsfml-system \
			-lcsfml-window \
			-lcsfml-audio \
			-lm \

$(NAME):	$(OBJ)
		@$(MAKE)	-s -C	lib/my
		@clang -o $(NAME) $(OBJ) $(LDFLAGS) $(OFLAGS) -Llib/ -lmy

all:	$(NAME)

.PHONY:	clean

clean:
		@rm -f $(OBJ)
		@$(MAKE) -s -C lib/my clean

fclean:	clean
		@echo "###############################"
		@echo "#Removing lib and vgcore files#"
		@echo "##############################"
		@rm -f $(NAME)
		@$(MAKE) -s -C lib/my fclean
		@rm -f vgcore*

re: fclean all
