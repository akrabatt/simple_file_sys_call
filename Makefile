C = gcc
CFLAGS = -Wall -std=c99 -g

TARGET = main

OBJS = main.o fun.o global.o

$(TARGET): $(OBJS)
	$(C) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c
	$(C) $(CFLAGS) -c main.c

fun.o: fun.c
	$(C) $(CFLAGS) -c fun.c

global.o: global.c
	$(C) $(CFLAGS) -c global.c


clean:
	rm -f $(OBJS) $(TARGET)
