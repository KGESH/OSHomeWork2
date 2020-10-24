CC = g++
TARGET = main
SOURCES = main.cpp matrix.cpp
CFLAGS = -W -Wall
OBJS = main.o matrix.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(TARGET) $(OBJS) -lpthread
	rm *.o

matrix.o : matrix.cpp
	$(CC) -c matrix.cpp -lpthread

main.o : main.cpp matrix.h
	$(CC) -c main.cpp -lpthread

clean:
	rm *.o