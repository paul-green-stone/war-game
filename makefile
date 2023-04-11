cc = gcc
objs = temp/main.o temp/queue.o temp/war-game.o
dirs = temp
CFLAGS = -O1

main: $(objs) 
	$(cc) $(CFLAGS) -o a.out $(objs)

temp/main.o: main.c
	$(cc) -c -g -o temp/main.o main.c

temp/queue.o: queue-ADT/queue.h queue-ADT/queue.c
	$(cc) -c -g -o temp/queue.o queue-ADT/queue.c

temp/war-game.o: war-game.h war-game.c
	$(cc) -c -g -o temp/war-game.o war-game.c

.PHONY: clean

clean:
	rm -rf temp ./*.o a.out 

$(shell mkdir -p $(dirs))