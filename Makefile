CC=gcc
FLAGS=-Wall -Werror -Wextra -pedantic -fsanitize=address
INCLUDE=./include
SRCS=main.c ./src/*.c
TARGET=main.elf
LINK=-lm
TARGET_LIB=./opcodes16_connector/lib/opcodes16.so

all:
	$(CC) $(FLAGS) -I$(INCLUDE) $(SRCS) -o $(TARGET) $(LINKS)
	./$(TARGET)
	
prod:
	$(CC) $(FLAGS) -I$(INCLUDE) $(SRCS) -o $(TARGET) $(LINKS) -DNDEBUG
	./$(TARGET)
	
lib:
	$(CC) -shared -Wall -Werror -Wextra -pedantic -DNDEBUG -I$(INCLUDE) -o $(TARGET_LIB) -fPIC $(SRCS)
