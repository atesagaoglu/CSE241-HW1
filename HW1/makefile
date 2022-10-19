all: clean compile link test
norun: clean compile link

clean:
	@clear
	@echo "deleting previous files"
	rm -f main main.o tetromino.o run
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

clean-run:
	@clear
	@echo "deleting previous files"
	rm -f main main.o tetromino.o
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

compile:
	@echo "Compiling files"
	g++ -c -std=c++11 main.cpp tetromino.cpp
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

link:
	@echo "linking"
	g++ -o run main.o tetromino.o
	@echo "~~~~~~~~~~~~~~~~~~~~~~~\n"

test:
	@echo "running"
	./run