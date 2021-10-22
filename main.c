#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "linked_list.h"

struct song_node ** create_library() {
    struct song_node **lib = malloc(27 * sizeof(struct song_node));
    
    int i;
    for (i = 0; i < 27; i++) {
        lib[i] = 0;
    }
    
    return lib;
}

int main() {
    struct song_node **lib = create_library();
    
    insert_front_tests();
}
