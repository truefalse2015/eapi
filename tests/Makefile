CC = gcc
CFLAGS = -Wall -Wextra -I./include

FILES = test-FS.c test-print.c test-random.c

BINS = $(patsubst %.c,%,$(FILES))

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

run: $(BINS)
	./test-FS && ./test-print && ./test-random