PROG=ui_test
FILES=src/test.c src/cui.c
FLAGS=-Wall -Wextra -pedantic -lSDL2 #-lSDL2_image

build:
	gcc -o $(PROG) $(FILES) $(FLAGS)

run:
	./$(PROG)
