GCC = gcc -g
run: myTunez.o main.o
	$(GCC) myTunez.o main.o -o run
myTunez.o: myTunez.c myTunez.h
	$(GCC) -c myTunez.c
main.o: main.c myTunez.h
	$(GCC) -c main.c
clean:
	rm *.o
	rm *~
	rm *#
