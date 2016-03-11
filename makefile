go: main.o thomas.o crash.o layer.o bounds.o
	gcc -o go main.o thomas.o crash.o layer.o bounds.o -lm
main.o: main.c fun.h
	gcc -c main.c
thomas.o: thomas.c fun.h
	gcc -c thomas.c
crash.o: crash.c fun.h
	gcc -c crash.c
layer.o: layer.c fun.h
	gcc -c layer.c
bounds.o: bounds.c fun.h
	gcc -c bounds.c
clean:
	rm go main.o thomas.o
