CC		= g++
#CFLAGS	+=	-DDEBUG
#CFLAGS	+=	-DTUAN
LINK	= -lpthread

main: main.o
	$(CC) -o $@ $^ $(LINK)
main.o: main.cpp
	$(CC) $(CFLAGS) -c $^
clean:
	rm -f ./*.o main
