#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include <ctype.h>
#include <string.h>

struct song_node ** create_library() {
    struct song_node **lib = malloc(27 * sizeof(struct song_node));
    
    int i;
    for (i = 0; i < 27; i++)
        lib[i] = 0;
    
    return lib;
}

void add_song(struct song_node **lib, char *name, char *artist) {
    int index = 26;
    if (isalpha(artist[0])) index = tolower(artist[0]) - 97;
    lib[index] = insert(lib[index], name, artist);
}

void print_all_entries_under_letter(struct song_node **lib, char letter) {
    int index = 26;
    if (isalpha(letter)) index = tolower(letter) - 97;
    print_list(lib[index]);
}

void print_all_entries_under_artist(struct song_node **lib, char *artist) {
    int index = 26;
    if (isalpha(artist[0])) index = tolower(artist[0]) - 97;
    
    struct song_node *song = get_first(lib[index], artist);
    printf("[  ");
    while (song && strcmp(song->artist, artist) == 0) {
        printf("Song {Name: %s, Artist: %s} ", song->name, song->artist);
        song = (song->next);
    }
    printf("]\n");
}

void print_all_entries(struct song_node **lib) {
    int i;
    for (i = 0; i < 27; i++) {
        if (i == 26) printf("other\n");
        else printf("%c\n", i + 97);
        print_list(lib[i]);
        printf("\n");
    }
}

void print_shuffled(struct song_node **lib, int num_songs) {
    int non_empty_letters[27];
    int count = 0;
    
    int i;
    for (i = 0; i < 27; i++) {
        if (lib[i]) {
            non_empty_letters[count] = i;
            count++;
        }
    }
    
    if (count == 0) printf("Empty library\n");
    else {
        int j;
        for (j = 0; j < num_songs; j++) {
            int random = rand() % count;
            struct song_node *song = get_random(lib[non_empty_letters[random]]);
            printf("Song #%d: Artist | %s, Name | %s\n", j + 1, song->artist, song->name);
        }
    }
}

struct song_node * find_song(struct song_node **lib, char *name, char *artist) {
    int index = 26;
    if (isalpha(artist[0])) index = tolower(artist[0]) - 97;
    return get(lib[index], name, artist);
}

struct song_node * find_artist(struct song_node **lib, char *artist) {
    int index = 26;
    if (isalpha(artist[0])) index = tolower(artist[0]) - 97;
    return get_first(lib[index], artist);
}

void delete_song(struct song_node **lib, char *name, char *artist) {
    int index = 26;
    if (isalpha(artist[0])) index = tolower(artist[0]) - 97;
    lib[index] = remove_node(lib[index], name, artist);
}

void clear_library(struct song_node **lib) {
    int i;
    for (i = 0; i < 27; i++) {
        if (lib[i]) lib[i] = free_list(lib[i]);
    }
}
