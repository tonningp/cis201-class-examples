# http://pirate.shu.edu/~minimair/assembler/Makefile
#
all: main


main :  *.cpp
	g++ -o main *.cpp

run :  main
	./main

edit:
	vim *.cpp

debug:
	gdb ./main

clean :
	@rm *.o  main
