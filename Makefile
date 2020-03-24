##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		src/main.c	\
				

NAME	=		my_defender

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
