##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

## ========================================================================== ##
PATH_SOURCE			=	src/
SOURCE				=	usage.c						\
						create_window.c				\
						create_button.c				\
						create_element.c			\
						leave_state_if_error.c		\
						main.c						\
						create_music.c				\
						animation_scene.c

## ========================================================================== ##
PATH_MAIN_MENU		=	src/main_menu/
MAIN_MENU			=	main_menu.c					\
						events_main_menu.c			\
						draw_main_menu.c			\
						ui_main_menu.c				\
						bouttons_main_menu.c		\
						destroy_main_menu.c

## ========================================================================== ##
PATH_SETTINGS_MENU	=	src/settings_menu/
SETTINGS_MENU		=	settings_menu.c				\
						draw_settings_menu.c		\
						init_button_settings_menu.c	\
						init_ui_settings_menu.c		\
						events_settings_menu.c		\
						destroy_settings_menu.c		\
						mouse_position_button_music.c

## ========================================================================== ##
PATH_PREGAME		=	src/in_game/pregame/
PREGAME				=	pregame.c					\
						draw_pregame.c				\
						events_pregame.c			\
						ui_pregame.c				\
						buttons_pregame.c			\
						destroy_pregame.c

## ========================================================================== ##
PATH_GAME			=	src/in_game/in_game/
GAME				=	in_game.c					\
						draw_in_game.c				\
						create_character.c			\
						create_utils_in_game.c		\
						init_in_game_scene.c		\
						init_common_to_scenes.c

## ========================================================================== ##
PATH_INIT_UI_GAME	=	src/in_game/in_game/init_ui_in_game/
INIT_UI_GAME		=	init_outside_ui.c			\
						init_ui_tavern.c			\
						init_ui_seller.c			\
						init_ui_cave.c				\
						init_ui_dungeon.c			\
						init_inventory.c

## ========================================================================== ##
PATH_INIT_PNJ	=	src/in_game/in_game/init_pnj/
INIT_PNJ		=	init_outside_pnj.c			\
					init_tavern_pnj.c			\
					init_seller_pnj.c			\
					init_cave_pnj.c				\
					init_dungeon_pnj.c

## ========================================================================== ##
PATH_DRAW_IN_GAME	=	src/in_game/in_game/draw_in_game/
DRAW_IN_GAME		=	draw_outside.c				\
						draw_tavern.c				\
						draw_seller.c				\
						draw_cave.c					\
						draw_dungeon.c				\
						draw_inventory.c

## ========================================================================== ##
PATH_GAME_EVENT		=	src/in_game/in_game/event/
GAME_EVENT			=	game_event.c					\
						event_keyboard.c				\
						event_move.c					\
						event_rect.c					\
						outside_events.c				\
						tavern_events.c					\
						seller_events.c					\
						cave_events.c					\
						dungeon_events.c				\
						inventory_events.c				\
						choose_equipment.c

## ========================================================================== ##
PATH_PAUSE			=	src/in_game/pause_menu/
PAUSE				=	pause_menu.c				\
						draw_pause_menu.c			\
						events_pause_menu.c			\
						ui_pause_menu.c				\
						buttons_pause_menu.c		\
						destroy_pause_menu.c

## ========================================================================== ##
PATH_HITBOX			=	src/in_game/hitbox/
HITBOX				=	game_hitbox.c				\
						hitbox_effect.c				\
						hitbox_skin.c

## ========================================================================== ##
PATH_FRAMBUFFER			=	src/framebuffer/
FRAMEBUFFER				=	rpg_framebuffer.c

INC_PATH=include

SRC	=	$(addprefix $(PATH_SOURCE), $(SOURCE))						\
		$(addprefix $(PATH_MAIN_MENU), $(MAIN_MENU))				\
		$(addprefix $(PATH_SETTINGS_MENU), $(SETTINGS_MENU))		\
		$(addprefix $(PATH_GAME), $(GAME))							\
		$(addprefix $(PATH_INIT_UI_GAME), $(INIT_UI_GAME))			\
		$(addprefix $(PATH_INIT_PNJ), $(INIT_PNJ))					\
		$(addprefix $(PATH_DRAW_IN_GAME), $(DRAW_IN_GAME))			\
		$(addprefix $(PATH_GAME_EVENT), $(GAME_EVENT))				\
		$(addprefix $(PATH_PAUSE), $(PAUSE))						\
		$(addprefix $(PATH_HITBOX), $(HITBOX))						\
		$(addprefix $(PATH_FRAMBUFFER), $(FRAMEBUFFER))				\
		$(addprefix $(PATH_PREGAME), $(PREGAME))

NAME	=		my_rpg

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-Wall -Werror -I. -I$(INC_PATH)

LIBS	=		-L ./lib/my -lmy -L ./lib/basics -lbasics

OFLAGS	=		-O2

LDFLAGS	= 	-lcsfml-graphics \
			-lcsfml-system \
			-lcsfml-window \
			-lcsfml-audio \
			-lm

$(NAME):	$(OBJ)
		@$(MAKE)	-s -C	lib/my
		@$(MAKE)	-s -C	lib/basics
		@clang -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBS) $(CFLAGS) $(OGLAGS)
		@echo -e "\n\033[01;38;5;10mCompiling : Done\033[0;0m"

all:	$(NAME)

.PHONY:	clean

clean:
		@rm -f $(OBJ)
		@$(MAKE)	-s	-C	lib/my fclean
		@$(MAKE)	-s	-C	lib/basics fclean

fclean:	clean
		@echo "###############################"
		@echo "#Removing lib and vgcore files#"
		@echo "###############################"
		@rm -f $(NAME)
		@rm -f vgcore*

re: fclean all

debug:
	@$(MAKE)	-s	-C	lib/my
	@$(MAKE)	-s	-C	lib/basics
	@gcc -o $(NAME) $(SRC) $(LDFLAGS)  $(LIBS) $(CFLAGS) $(DEBUG) -g
	@echo "Valgrind compilation: Done"