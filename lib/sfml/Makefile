##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	src/Display.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME 	=	lib_arcade_sfml.so

CC		=	g++

FLAGS	= 	-shared -fPIC -Iinclude/ -lsfml-graphics -lsfml-window -lsfml-system

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
