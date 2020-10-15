CC = g++ --std=c++17

all:program

program: main.o Beam.o
	$(CC) main.o Beam.o -o program

main.o: main.cpp
	$(CC) -c main.cpp

Beam.o: Beam.cpp Beam.h
	$(CC) -c Beam.cpp

test:
	./program

clean:
	rm *.o program