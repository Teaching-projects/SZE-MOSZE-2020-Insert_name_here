
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


make_.sh_files_executable:
	chmod +x ./*.sh

run_test_01.sh:
	./test_01.sh

diff_test:
	diff output.txt expected_output.txt

install_valgrind_and_cppcheck:
	sudo apt-get install valgrind
	sudo apt-get install cppcheck

check_leaks:
	valgrind $(VLGRNDFLAGS) ./$(OUT) $(JSONFILES)

check_warnings:
	./test_check_warnings.sh

style_and_performance:
	./test_style_and_performance.sh

gtest:
	cd unit_tests && cmake CMakeLists.txt
	cd unit_tests && make
	cd unit_tests && ./runTests

documentation:
	sudo apt-get install doxygen
	sudo apt-get install graphviz
	doxygen doxconf

clean:
	rm -rf $(OBJS) a.out ./DOCS