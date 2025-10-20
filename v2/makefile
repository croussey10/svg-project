CC := gcc
FLAGS := -std=c99 -Werror -Wall -Wextra

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c shapes.c
	$(CC) $(FLAGS) -c menu.c
	$(CC) $(FLAGS) -o prog main.o shapes.o menu.o