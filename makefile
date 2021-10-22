all: main.o test.o linked_list.o
	gcc -o main main.o test.o linked_list.o
main.o: main.c test.h
	gcc -c main.c
test.o: test.c linked_list.h
	gcc -c test.c
linked_list.o: linked_list.c
	gcc -c linked_list.c
run: main
	./main