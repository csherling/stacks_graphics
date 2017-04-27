OBJECTS= main.o draw.o display.o matrix.o stack.o parser.o
CFLAGS= -Wall
LDFLAGS= -lm
CC= gcc

all: $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(LDFLAGS)

main.o: main.c display.h draw.h ml6.h matrix.h parser.h
	$(CC) -c main.c

draw.o: draw.c draw.h display.h ml6.h matrix.h
	$(CC) $(CFLAGS) -c draw.c

dsiplay.o: display.c display.h ml6.h matrix.h
	$(CC) $(CFLAGS) -c display.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

stack.o: stack.c stack.h display.h ml6.h matrix.h
	$(CC) $(CFLAGS) -c stack.c

parser.o:  matrix.h draw.h display.h ml6.h stack.h parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

run: all
	./main script
clean:
	rm *.o *~
