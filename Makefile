CC = gcc
CFLAGS = -Wall

SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=%.o)

.PHONY: clean run

main: $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $< -c -o $@

run: main
	@./$<

clean:
	@rm -f $(OBJS) main.exe
