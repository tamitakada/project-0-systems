#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

void print_list(struct cat *c) {
    printf("[  ");
    while (c) {
        printf("Cat {Name: %s, Age: %d} ", c->name, c->age);
        c = (c->next);
    }
    printf("]\n");
}

struct cat * insert_front(struct cat *next, char *name, int age) {
    struct cat *new_cat = malloc(sizeof(struct cat));
    strcpy(new_cat->name, name);
    new_cat->age = age;
    new_cat->next = next;
    return new_cat;
}

struct cat * free_list(struct cat *c) {
    struct cat *next;
    while (c) {
        next = c->next;
        free(c);
        c = next;
    }
    return c;
}

struct cat * remove_node(struct cat *front, char *name, int age) {
    struct cat *before = 0;
    struct cat *current = front;
    while (current) {
        if (strcmp(current->name, name) == 0 && (current->age) == age) {
            if (before) before->next = current->next;
            else front = current->next;
            free(current);
        }
        before = current;
        current = (current->next);
    }
    return front;
}

void populate_random_arr(char *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
	arr[i] = (rand() % 24) + 65;
    }

    arr[len - 1] = '\0';
}
