#ifndef LIBRARY

struct song_node ** create_library();
void add_song(struct song_node **lib, char *name, char *artist);
void print_all_entries_under_letter(struct song_node **lib, char letter);
void print_all_entries_under_artist(struct song_node **lib, char *artist);
void print_all_entries(struct song_node **lib);
void print_shuffled(struct song_node **lib, int num_songs);

#endif
