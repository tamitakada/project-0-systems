#ifndef	LINKED_LIST

struct cat {
    char name[100];
    int age;
    struct cat *next;
};

void print_list(struct cat *c);
struct cat * insert_front(struct cat *next, char *name, int age);
struct cat * free_list(struct cat *c);
struct cat * remove_node(struct cat *front, char *name, int age);

void populate_random_arr(char *arr, int len);

#endif
