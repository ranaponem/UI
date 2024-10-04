PROG=snake
FILES=src/main.c src/input.c
FLAGS=-Wall -Wextra -pedantic -lSDL2 -lSDL2_image

build:
	gcc -o $(PROG) $(FILES) $(FLAGS)

run:
	./$(PROG)
