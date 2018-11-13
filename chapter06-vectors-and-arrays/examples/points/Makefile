# http://pirate.shu.edu/~minimair/assembler/Makefile
#
all: main


main :  main.cpp
	g++ -std=c++11 -o main *.cpp

run :  main
	./main

edit:
	vim *.cpp

debug:
	gdb ./main

clean :
	@rm *.o  main
