all: main.o snake.o
	gcc main.o snake.o -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o jogo_cobra

main.o: main.c snake.h
	gcc -c main.c

snake.o: snake.c snake.h
	gcc -c snake.c

teste: snake
	./teste.sh

clean:
	rm -f snake *.o temp.txt

.PHONY: all teste clean
