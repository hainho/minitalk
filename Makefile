CC=gcc
CFLAGS=-g -O
SVOBJS=server.o ft_atoi.o ft_itoa.o ft_strlen.o
CLOBJS=client.o ft_atoi.o ft_itoa.o ft_strlen.o

server.o: ft_minitalk.h server.c
client.o: ft_minitalk.h client.c

server: $(SVOBJS)
	$(CC) $(CFLAGS) -o server $(SVOBJS)

client: $(CLOBJS)
	$(CC) $(CFLAGS) -o client $(CLOBJS)

clean:
	rm -f *.o server client
