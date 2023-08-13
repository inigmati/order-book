CC = g++
CFLAGS = -g -Wall -Werror -Wno-error

ll: ll.o
	$(CC) $(CFLAGS) -o ll ll.o

ll.o: ll.cpp
	$(CC) $(CFLAGS) -c ll.cpp

clean:
	rm ll
	rm ll.o
