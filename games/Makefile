##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## games
##

all:
	@make --no-print-directory -C ./centipedeGame
	@make --no-print-directory -C ./nibbler

clean:
	@make clean --no-print-directory -C ./centipedeGame
	@make clean --no-print-directory -C ./nibbler

fclean: clean
	@make fclean --no-print-directory -C ./centipedeGame
	@make fclean --no-print-directory -C ./nibbler

re: fclean all

.PHONY: all clean fclean re
