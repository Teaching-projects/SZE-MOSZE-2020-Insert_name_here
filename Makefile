
OBJS = main.o game.o character.o player.o jsonparser.o
CFLAGS = -std=c++17 -Wall -Werror
CC = g++
OUT = a.out
VLGRNDFLAGS:= --leak-check=full --error-exitcode=1 --log-file=memory_leaks.txt
JSONFILES:=  units/unit1.json units/unit2.json

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


diff_test:
	diff output.txt expected_output.txt

check_leaks:
	valgrind $(VLGRNDFLAGS) ./$(OUT) $(JSONFILES)

gtest:
	cd unit_tests && cmake CMakeLists.txt
	cd unit_tests && make
	cd unit_tests && ./runTests

documentation:
	doxygen doxconf

clean:
	rm -rf $(OBJS) a.out ./DOCS