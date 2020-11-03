
OBJS = main.o game.o character.o player.o jsonparser.o
CFLAGS = -std=c++17 -Wall -Werror
CC = g++
OUT = a.out


build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

main.o: main.cpp game.h player.h character.h
	$(CC) $(CFLAGS) -c main.cpp

game.o: game.cpp game.h character.h player.h
	$(CC) $(CFLAGS) -c game.cpp

character.o: character.cpp character.h jsonparser.h
	$(CC) $(CFLAGS) -c character.cpp

player.o: player.cpp player.h jsonparser.h character.h
	$(CC) $(CFLAGS) -c player.cpp

jsonparser.o: jsonparser.cpp jsonparser.h
	$(CC) $(CFLAGS) -c jsonparser.cpp


clean:
	rm -rf $(OBJS) a.out ./DOCS