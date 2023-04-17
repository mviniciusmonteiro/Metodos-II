clean: compile
	./main
	rm -f  *.o

compile: object
	g++ -o main *.o

object:
	g++ -c main.cpp implementacoes/*.cpp
