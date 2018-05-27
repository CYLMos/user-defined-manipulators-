all: main.o Form.o
	g++ -o Form main.o Form.o
main.o: main.cpp
	g++ -c main.cpp
Form.o:
	g++ -c Form.cpp
clean:
	rm -f *.o Form
