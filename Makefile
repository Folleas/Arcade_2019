##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

GPP			=	g++

RM			=	rm -rf

NAME		=	arcade

COMPILEFLAG	=	-Wall -Wextra -g -ldl

INCLUDE		=	-Iinclude/

CPPFLAGS    =	$(COMPILEFLAG) $(INCLUDE)

SRC			=	src/Main.cpp				\
				src/Error.cpp				\
				src/Core.cpp				\
				src/IDisplay.cpp			\
				src/Menu.cpp				\
				src/Button.cpp				\
				src/Utils.cpp

OBJ			=	$(SRC:.cpp=.o)

all:
	@make --no-print-directory -C ./games
	@make --no-print-directory -C ./lib
	@make --no-print-directory core

core:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[01m\033[31mLinking ...\033[00m"
	@$(GPP) $(OBJ) -o $(NAME) $(CPPFLAGS) $(CPPFLAGS)
	@echo -e "\033[01m\033[32mStandard compilation done => ${NAME}\033[00m"

games:
	@make --no-print-directory -C ./games

graphicals:
	@make --no-print-directory -C ./lib

clean:
	@$(RM) vgcore.*
	@$(RM) src/*.o lib/*.o games/*.o
	@echo -e "\033[01m\033[31mRemoving useless files ...\033[00m"
	@make clean --no-print-directory -C ./games
	@make clean --no-print-directory -C ./lib

fclean:	clean
	@$(RM) $(NAME)
	@echo -e "\033[01m\033[31mRemoving libraries and binary : {${NAME}} ...\033[00m"
	@make fclean --no-print-directory -C ./games
	@make fclean --no-print-directory -C ./lib

re:	fclean
	@make re --no-print-directory -C ./games
	@make re --no-print-directory -C ./lib
	@make all --no-print-directory

.PHONY:	all clean fclean re
