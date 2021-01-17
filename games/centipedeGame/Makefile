##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	src/Start.cpp
#src/Colision.cpp						\
			src/Display.cpp							\
			src/Ennemies.cpp						\
			src/Event.cpp							\
			src/GetMap.cpp							\
			src/LoadSprites.cpp						\
			src/Start.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME 	=	lib_arcade_centipede.so

CC		=	g++

FLAGS	= 	-shared -fPIC -Iinclude/ -lSDL2main -lSDL2 -lSDL2_ttf

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
