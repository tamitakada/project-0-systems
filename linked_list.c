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
	while(s) {
		if(s->name == name && s->artist == artist) return s;
		s = s->next;
	}
    return 0;
}

struct song_node *get_first(struct song_node *s, char *artist) {
	while(s) {
		if(s->artist == artist) return s;
		s = s->next;
	}
    return 0;
}

struct song_node * insert(struct song_node *s, char *name, char *artist) {
    struct song_node *new_node;
    strcpy(new_node->artist, artist);
    strcpy(new_node->name, name);
    
    struct song_node *previous = 0;
    
    int index = 0;
    
    while (s) {
        int cmp = songcmp(s, new_node);
        if (!cmp) {
            new_node->next = s->next;
            s->next = new_node;
            return s;
        } else if (cmp > 0) {
            previous->next = new_node;
            new_node->next = s;
            if (index == 0) return new_node;
            else return s;
        }
        
        previous = s;
        s = s->next;
        index++;
    }
    
    return s;
}

int songcmp(struct song_node *first, struct song_node *second) {
    int artist_cmp = strcmp(first->artist, second->artist);
    if (artist_cmp) return artist_cmp;
    else {
        int song_cmp = strcmp(first->name, second->name);
        return song_cmp;
    }
}

struct song_node * get_random(struct song_node *s) {
    int size = 0;
    struct song_node *temp = s;
    while (temp) {
        size++;
        temp = temp->next;
    }
    
    int random = (rand() % size);
    int current = 0;
    while (current < random) {
    	current++;
    	s = s->next;
    }
    
    return s;
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
