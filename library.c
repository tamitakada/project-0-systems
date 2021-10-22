#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include <ctype.h>

struct song_node ** create_library() {
    struct song_node **lib = malloc(27 * sizeof(struct song_node));
    
    int i;
    for (i = 0; i < 27; i++)
        lib[i] = 0;
    
    return lib;
}

void add_song(struct song_node **lib, char *name, char *artist) {
    int index = 26;
    if (isalpha(name[0])) index = tolower(artist[0]) - 97;
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
    print_list(song);
}

void print_all_entries(struct song_node **lib) {
    int i;
    for (i = 0; i < 27; i++) {
        printf("%c\n", i + 97);
        print_list(lib[i]);
        printf("\n");
    }
}

void print_shuffled(struct song_node **lib, int num_songs) {
    int i;
    for (i = 0; i < num_songs; i++) {
        struct song_node *song = get_random(lib[0]);
        printf("Song #%d: Artist | %s, Name | %s\n", i + 1, song->artist, song->name);
    }
}
