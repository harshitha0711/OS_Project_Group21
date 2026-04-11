CC = gcc
CFLAGS = -Wall
all: scheduler
scheduler: main.c mlfq.c lottery.c edf.c metrics.c visualize.c
	$(CC) $(CFLAGS) main.c mlfq.c lottery.c edf.c metrics.c visualize.c -o scheduler
run: scheduler
	./scheduler
clean:
	rm -f scheduler
