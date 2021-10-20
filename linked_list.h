#ifndef	LINKED_LIST

struct song_node {
    char name[100];
    char artist[100];
    struct song_node *next;
};

void print_list(struct song_node *s);
struct song_node * insert_front(struct song_node *s, char *name, char *artis\
t);
struct song_node * free_list(struct song_node *s);
struct song_node * remove_node(struct song_node *front, char *name, char *artist);

void populate_random_arr(char *arr, int len);

#endif
