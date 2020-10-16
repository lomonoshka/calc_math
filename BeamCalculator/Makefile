CC = g++ --std=c++17

all:program

program: main.o Beam.o Actions.o Supports.o
	$(CC) main.o Beam.o Actions.o Supports.o -o program

main.o: main.cpp
	$(CC) -c main.cpp

Beam.o: Beam.cpp Beam.h
	$(CC) -c Beam.cpp

Actions.o: Actions.cpp Actions.h
	$(CC) -c Actions.cpp

Supports.o: Supports.cpp Supports.h
	$(CC) -c Supports.cpp

test:
	./program

clean:
	rm *.o program