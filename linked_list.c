
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

void print_list(struct song_node *s) {
    printf("[  ");
    while (s) {
        printf("Song {Name: %s, Artist: %s} ", s->name, s->artist);
        s = (s->next);
    }
    printf("]\n");
}

struct song_node * get(struct song_node *s, char *name, char *artist) {
	struct song_node *temp = s;
	while(temp != NULL) {
		if(temp->name == name && temp->artist == artist) return temp;
	}
}

struct song_node * insert_front(struct song_node *next, char *name, char *artist) {
    struct song_node *new_song = malloc(sizeof(struct song_node));
    strcpy(new_song->name, name);
    strcpy(new_song->artist, artist);
    new_song->next = next;
    return new_song;
}

struct song_node * free_list(struct song_node *s) {
    struct song_node *next;
    while (s) {
        next = s->next;
        free(s);
        s = next;
    }
    return s;
}

struct song_node * remove_node(struct song_node *front, char *name, char *artist) {
    struct song_node *before = 0;
    struct song_node *current = front;
    while (current) {
      if (strcmp(current->name, name) == 0 && strcmp(current->artist, artist) == 0) {
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
