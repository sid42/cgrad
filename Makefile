CFLAGS=-Iinclude -mavx2 -O2

all: matmul

matmul:
	gcc $(CFLAGS) -o $@ $^ *.c