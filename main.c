#include "library.h"
#include "test.h"

int main() {
    struct song_node **lib = create_library();
    
    char name_0[50] = "Clair de Lune";
    char artist_0[50] = "Claude Debussy";
    
    add_song(lib, name_0, artist_0);
    
    char name_1[50] = "Petite suite";
    char artist_1[50] = "Claude Debussy";

    add_song(lib, name_1, artist_1);

    char name_2[50] = "Piano Concerto No. 1 in E-Flat Major";
    char artist_2[50] = "Franz Liszt";

    add_song(lib, name_2, artist_2);

    char name_3[50] = "Romanian Folk Dances";
    char artist_3[50] = "Bela Bartok";

    add_song(lib, name_3, artist_3);

    print_all_entries(lib);
    
//    insert_front_tests();
}
