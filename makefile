all: main.o linked_list.o library.o
	gcc -o main main.o linked_list.o library.o
main.o: main.c linked_list.h library.h
	gcc -c main.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
library.o: library.c linked_list.h
	gcc -c library.c
run: main
	./main