CC=gcc
FLAGS=-Wall -Werror -Wextra -pedantic -fsanitize=address
INCLUDE=./include
SRCS=main.c ./src/*.c
TARGET=opcodes16.elf
LINK=-lm
TARGET_LIB=./opcodes16_connector/lib/opcodes16.so
WIN-CC=x86_64-w64-mingw32-gcc
WIN-TARGET=opcodes16.exe
WIN-FLAGS=-Wall -Werror -Wextra -pedantic

all:
	$(CC) $(FLAGS) -I$(INCLUDE) $(SRCS) -o $(TARGET) $(LINKS)
	
prod:
	$(CC) $(FLAGS) -I$(INCLUDE) $(SRCS) -o $(TARGET) $(LINKS) -DNDEBUG
	
lib:
	$(CC) -shared -Wall -Werror -Wextra -pedantic -DNDEBUG -I$(INCLUDE) -o $(TARGET_LIB) -fPIC $(SRCS)

windows:
	$(WIN-CC) $(WIN-FLAGS) -I$(INCLUDE) $(SRCS) -o $(WIN-TARGET) $(LINKS) -DNDEBUG
