all: ftree 

ftree: main.o Person.o
	g++ -o ftree main.o Person.o

main.o: main.cpp Person.hpp
	g++ -c -o main.o main.cpp

Person.o: Person.cpp Person.hpp
	g++ -c -o Person.o Person.cpp

clean:
	rm -r ftree main.o Person.o
