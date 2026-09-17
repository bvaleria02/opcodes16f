CC=gcc
FLAGS=-Wall -Werror -Wextra -pedantic -fsanitize=address
INCLUDE=./include
SRCS=main.c ./src/*.c
TARGET=main.elf
LINK=-lm

all:
	$(CC) $(FLAGS) -I$(INCLUDE) $(SRCS) -o $(TARGET) $(LINKS)
	./$(TARGET)
	
prod:
	$(CC) $(FLAGS) -I$(INCLUDE) $(SRCS) -o $(TARGET) $(LINKS) -DNDEBUG
	./$(TARGET)
