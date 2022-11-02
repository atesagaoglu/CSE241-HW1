all: clean compile link test
norun: clean compile link

clean:
	@clear
	@echo "deleting previous files"
	rm -f main main.o tetromino.o tetris.o run
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

clean-run:
	@clear
	@echo "deleting previous files"
	rm -f main main.o tetromino.o tetris.o
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

compile:
	@echo "Compiling files"
	g++ -c -std=c++11 main.cpp tetromino.cpp tetris.cpp
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

compileg:
	@echo "Compiling files"
	g++ -c -std=c++11 main.cpp tetromino.cpp tetris.cpp
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"	

link:
	@echo "linking"
	g++ -o run main.o tetromino.o tetris.o
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

test:
	@echo "running"
	./run