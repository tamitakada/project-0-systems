#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

void populate_random_arr(char *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
    	arr[i] = (rand() % 24) + 65;
    }

    arr[len - 1] = '\0';
}

void insert_front_tests() {
    struct song_node *start = 0;
    int len_chain = (rand() % 20) + 1;
    
    int i;
    for (i = 0; i < len_chain; i++) {
        int name_len = (rand() % 20) + 1;
        char name[name_len];
        populate_random_arr(name, name_len);
        
        int artist_len = (rand() % 20) + 1;
        char artist[artist_len];
        populate_random_arr(artist, artist_len);
        
        start = insert_front(start, name, artist);
    }

    printf("Insert Front Random Test:\n");
    print_list(start);
}

    
    
