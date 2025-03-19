CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Werror

SRC = core/main.c core/compressor.c core/tree.c
TEST_SRC = core/test.c core/compressor.c core/tree.c

OBJ = $(patsubst core/%.c, build/%.o, $(SRC))
TEST_OBJ = $(patsubst core/%.c, build/%.o, $(TEST_SRC))

TARGET = huffman_prod
TEST_TARGET = huffman_test

all: build $(TARGET)

build:
	mkdir -p build

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

build/%.o: core/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET) $(TEST_TARGET)

test: build $(TEST_TARGET)

