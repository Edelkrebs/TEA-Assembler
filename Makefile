SOURCES := $(shell find -name *.c)
OBJECTS := $(SOURCES:.c=.o)

CC = gcc

EXEC = assembler

run: all
	./$(EXEC)

all: $(OBJECTS)
	$(CC) $^ -o $(EXEC) -Isrc/include -lgcc -Werror -Wall

%.o:%.c
	$(CC) -c $^ -o $@ -Isrc/include -lgcc -Wall -Werror

clean:
	rm -rf $(OBJECTS) $(EXEC)