CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -lm
TARGET = factors

all: $(TARGET)

$(TARGET): factors.c
	$(CC) $(CFLAGS) -o $(TARGET) factors.c

clean:
	rm -f $(TARGET)

