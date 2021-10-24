#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "library.h"
#include "linked_list.h"

void test_library();
void test_linked_list();

int main() {
    srand(time(NULL));
    
    printf("\nTESTING LINKED LIST FUNCS ==================================\n\n");
    //test_linked_list();
    
    printf("TESTING LIBRARY FUNCS ==================================\n\n");
    //test_library();
    
    printf("------------ Get Test ------------\n");
    
    char name_0[50] = "Hello";
    char artist_0[50] = "Adele";
    
    struct song_node *hello = 0;
    hello = insert(hello, name_0, artist_0);
    
    char name_1[50] = "22";
    char artist_1[50] = "Taylor";
	hello = insert(hello, name_1, artist_1);
	
	char name_2[50] = "Wildest Dreams";
	hello = insert(hello, name_2, artist_1);
	
    printf("looking for hello, adele: %p \n", get(hello, name_0, artist_0));
    printf("found hello, adele: \t  %p \n", hello);
    
    printf("looking for 22, taylor: %p \n", get(hello, name_1, artist_1));
    printf("found 22, taylor: \t%p \n", hello->next);
    
    printf("looking for wildest dreams, taylor: %p \n", get(hello, name_2, artist_1));
    printf("found wildest dreams, taylor: \t    %p \n", hello->next->next);
    
    
    printf("\n------------ Get First Test ------------\n");
	
    printf("looking for adele %p \n", get_first(hello, artist_0));
    printf("found adele: \t  %p \n", hello);
 
    printf("looking for taylor: %p \n", get_first(hello, artist_1));
    printf("found taylor: \t    %p \n\n", hello->next);
    
    char name_3[50] = "Baby";
    char artist_2[50] = "Justin";
   	hello = insert(hello, name_3, artist_2);
   	
   	char name_4[50] = "Boyfriend";
   	hello = insert(hello, name_4, artist_2);
   	
   	printf("looking for justin: %p \n", get_first(hello, artist_2));
   	hello = hello->next;
   	hello = hello->next;
   	hello = hello->next;
   	printf("found justin: \t    %p \n", hello->next);
    
}

void test_library() {
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
    
    printf("\n------------ Testing print_shuffled in library ------------\n\nShuffle print 5 songs:\n");
    print_shuffled(lib, 5);
    
    printf("\nShuffle print 10 songs:\n");
    print_shuffled(lib, 10);

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

void test_linked_list() {
    printf("------------ Testing insert_front ------------\n");
    
    char name_0[50] = "Cello Suite No. 1 in G Major";
    char artist_0[50] = "Johann Sebastian Bach";
    
    struct song_node * song = 0;

    printf("Inserting front 'Cello Suite No. 1 in G Major' by Johann Sebastian Bach...\n");
    song = insert_front(song, name_0, artist_0);
    
    char name_1[50] = "Requiem in D Minor";
    char artist_1[50] = "Wolfgang Amadeus Mozart";
    
    printf("Inserting front 'Requiem in D Minor' by Wolfgang Amadeus Mozart...\n");
    song = insert_front(song, name_1, artist_1);
    
    char name_2[50] = "24 Preludes, Op. 28";
    char artist_2[50] = "Frederic Chopin";
    
    printf("Inserting front '24 Preludes, Op. 28' by Frederic Chopin...\n");
    song = insert_front(song, name_2, artist_2);
    
    printf("\nprint_list:\n");
    print_list(song);
    
    printf("\n------------ Testing insert ------------\n");
    
    char name_3[50] = "Nocturne No. 2 in E-Flat Major";
    
    printf("Inserting 'Nocturne No. 2 in E-Flat Major' by Frederic Chopin...\n");
    song = insert(song, name_3, artist_2);
    
    char name_4[50] = "Symphony No. 3 in F Major";
    char artist_3[50] = "Johannes Brahms";
    
    printf("Inserting 'Symphony No. 3 in F Major' by Johannes Brahms...\n");
    song = insert(song, name_4, artist_3);
    
    printf("\nprint_list:\n");
    print_list(song);
    
    printf("\n------------ Testing get ------------\nGet 'Requiem in D Minor' by Wolfgang Amadeus Mozart: ");
    
    struct song_node *song_0 = get(song, name_1, artist_1);
    if (song_0) printf("Song {Name: %s, Artist: %s}\n", song_0->name, song_0->artist);
    else printf("Not found\n");
    
    printf("Get 'Symphony No. 3 in F Major' by Johannes Brahms: ");
    struct song_node *song_1 = get(song, name_4, artist_3);
    if (song_1) printf("Song {Name: %s, Artist: %s}\n", song_1->name, song_1->artist);
    else printf("Not found\n");
    
    printf("Get 'Fake Song' by I Don't Exist: ");
    
    char fake_name[50] = "Fake Song";
    char fake_artist[50] = "I Don't Exist";
    
    struct song_node *song_2 = get(song, fake_name, fake_artist);
    if (song_2) printf("Song {Name: %s, Artist: %s}\n", song_2->name, song_2->artist);
    else printf("Not found\n");
    
    printf("\n------------ Testing get_first ------------\nGet first by Johann Sebastian Bach: ");
    
    struct song_node *song_3 = get_first(song, artist_0);
    if (song_3) printf("Song {Name: %s, Artist: %s}\n", song_3->name, song_3->artist);
    else printf("Not found\n");
    
    printf("Get first by Frederic Chopin: ");
    struct song_node *song_4 = get_first(song, artist_2);
    if (song_4) printf("Song {Name: %s, Artist: %s}\n", song_4->name, song_4->artist);
    else printf("Not found\n");
    
    printf("Get first by I Don't Exist: ");
    struct song_node *song_5 = get_first(song, fake_artist);
    if (song_5) printf("Song {Name: %s, Artist: %s}\n", song_5->name, song_5->artist);
    else printf("Not found\n");
}
