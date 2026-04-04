
CC = gcc
CFLAGS = -std=c99 -Wall -pedantic -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_POSIX_C_SOURCE=200809L -g -Imath -I.  -pthread
LDFLAGS = -pthread -lrt -lm

SOURCES = $(wildcard *.c math/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -f $(OBJECTS) main