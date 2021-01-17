##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## lib
##

all:
	@make --no-print-directory -C ./sdl
	@make --no-print-directory -C ./sfml

clean:
	@make clean --no-print-directory -C ./sdl
	@make clean --no-print-directory -C ./sfml

fclean: clean
	@make fclean --no-print-directory -C ./sdl
	@make fclean --no-print-directory -C ./sfml

re: fclean all

.PHONY: all clean fclean re
