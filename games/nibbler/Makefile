##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	src/Character.cpp							\
			src/GameCore.cpp							\
			src/Map.cpp									\
			src/Score.cpp								\
			../../src/Button.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME 	=	lib_arcade_nibbler.so

CC		=	g++

FLAGS	= 	-shared -fPIC -Iinclude/ -lSDL2main -lSDL2 -lSDL2_ttf -ldl

all: $(NAME)

$(NAME):	$(OBJ)
	@echo -e "\e[33mLibrary compilation done  => $(NAME)\033[00m"
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) && mv $(NAME) ../

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
