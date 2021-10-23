#include "library.h"
#include "test.h"
#include <stdio.h>
#include "linked_list.h"

int main() {
    printf("------------ Testing create_library ------------\n");
    struct song_node **lib = create_library();
    
    printf("------------ Testing print_all_entries in library ------------\n");
    print_all_entries(lib);
    
    printf("------------ Testing add_song ------------\n");
    char name_0[50] = "Clair de Lune";
    char artist_0[50] = "Claude Debussy";

    printf("Inserting 'Clair de Lune' by Claude Debussy...\n");
    add_song(lib, name_0, artist_0);

    char name_1[50] = "Petite suite";
    char artist_1[50] = "Claude Debussy"; // Try adding same artist, diff song

    printf("Inserting 'Petite suite' by Claude Debussy...\n");
    add_song(lib, name_1, artist_1);

    char name_2[50] = "Piano Concerto No. 1 in E-Flat Major";
    char artist_2[50] = "Franz Liszt";

    printf("Inserting 'Piano Concerto No. 1 in E-Flat Major' by Franz Liszt...\n");
    add_song(lib, name_2, artist_2);

    char name_3[50] = "Romanian Folk Dances";
    char artist_3[50] = "Bela Bartok";

    printf("Inserting 'Romanian Folk Dances' by Bela Bartok...\n");
    add_song(lib, name_3, artist_3);

    char name_4[50] = "19 Hungarian Rhapsodies"; // Try adding song with non-alpha first letter
    char artist_4[50] = "Franz Liszt";

    printf("Inserting '19 Hungarian Rhapsodies' by Franz Liszt...\n");
    add_song(lib, name_4, artist_4);
    
    char name_5[50] = "The Carnival of the Animals";
    char artist_5[50] = "Camille Saint-Saëns"; // Try adding another artist to letter 'c'

    printf("Inserting 'The Carnival of the Animals' by Camille Saint-Saëns...\n");
    add_song(lib, name_5, artist_5);
    
    printf("Inserting duplicate 'The Carnival of the Animals' by Camille Saint-Saëns...\n\n");
    add_song(lib, name_5, artist_5); // Try adding duplicate song

    printf("print_all_entries in library:\n");
    print_all_entries(lib);
    
    printf("------------ Testing print_all_entries_under_letter in library ------------\n\nLetter 'c': ");
    print_all_entries_under_letter(lib, 'c');
    
    printf("\nLetter 'f': ");
    print_all_entries_under_letter(lib, 'f');
    
    printf("\nLetter '*' (other): ");
    print_all_entries_under_letter(lib, '*');
    
    printf("\n------------ Testing print_all_entries_under_artist in library ------------\n\nArtist 'Claude Debussy': ");
    print_all_entries_under_artist(lib, artist_0);
    
    printf("\nArtist 'Bela Bartok': ");
    print_all_entries_under_artist(lib, artist_3);
    
    printf("\nArtist 'I Don't Exist': ");
    char fake_artist[50] = "I Don't Exist";
    print_all_entries_under_artist(lib, fake_artist);
    
    printf("\n------------ Testing find_song in library ------------\n\nFind 'Romanian Folk Dances' by Bela Bartok: ");
    
    struct song_node *song_0 = find_song(lib, name_3, artist_3);
    if (song_0) {
        printf("Song {Name: %s, Artist: %s}\n", song_0->name, song_0->artist);
    } else printf("Not Found\n");
    
    printf("\nFind '19 Hungarian Rhapsodies' by Franz Liszt: ");
    struct song_node *song_1 = find_song(lib, name_4, artist_4);
    if (song_1) {
        printf("Song {Name: %s, Artist: %s}\n", song_1->name, song_1->artist);
    } else printf("Not Found\n");
    
    printf("\nFind 'Fake Song' by I Don't Exist: ");
    char fake_name[50] = "Fake Song";
    struct song_node *song_2 = find_song(lib, fake_name, fake_artist);
    if (song_2) {
        printf("Song {Name: %s, Artist: %s}\n", song_2->name, song_2->artist);
    } else printf("Not Found\n");

    printf("\n------------ Testing delete_song in library ------------\n\nDeleting 'Petite suite' by Claude Debussy...");
    delete_song(lib, name_1, artist_0);
    
    printf("\nCurrent entries under 'Claude Debussy': ");
    print_all_entries_under_artist(lib, artist_0);
    
    printf("\nDeleting ONE of TWO copies of 'The Carnival of the Animals' by Camille Saint-Saëns...");
    delete_song(lib, name_5, artist_5);
    
    printf("\nCurrent entries under 'Camille Saint-Saëns': ");
    print_all_entries_under_artist(lib, artist_5);
    
    printf("\n------------ Testing clear_library in library ------------\n\nClearing library...\n");
    clear_library(lib);
    
    printf("print_all_entries in library:\n");
    print_all_entries(lib);
}
