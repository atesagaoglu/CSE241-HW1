all: clean compile link run
d1: clean1 compile1 link1 test1
d2: clean2 compile2 link2 test2

clean:
	@clear
	@echo "deleting previous files"
	rm -f main main.o tetromino.o tetris.o run
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

clean1:
	@clear
	@echo "deleting previous files"
	rm -f main driver1.o tetromino.o tetris.o run1
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

clean2:
	@clear
	@echo "deleting previous files"
	rm -f main driver2.o tetromino.o tetris.o run2
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

compile:
	@echo "Compiling files"
	g++ -c -std=c++11 main.cpp tetromino.cpp tetris.cpp
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"


compile1:
	@echo "Compiling files"
	g++ -c -std=c++11 driver1.cpp tetromino.cpp tetris.cpp
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

compile2:
	@echo "Compiling files"
	g++ -c -std=c++11 driver2.cpp tetromino.cpp tetris.cpp
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

link:
	@echo "linking"
	g++ -o run main.o tetromino.o tetris.o
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

link1:
	@echo "linking"
	g++ -o run1 driver1.o tetromino.o tetris.o
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

link2:
	@echo "linking"
	g++ -o run2 driver2.o tetromino.o tetris.o
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

test:
	@echo "running"
	./run

test1:
	@echo "running"
	./run1

test2:	
	@echo "running"
	./run2

cleanall:
	rm -f main driver1.o tetromino.o tetris.o run1
	rm -f main driver2.o tetromino.o tetris.o run2