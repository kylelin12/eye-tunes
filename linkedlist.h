struct SongNode {
    char name[256];
    char artist[256];
    struct SongNode *next;
}

struct node * del_entry(struct SongNode *start, char *name);
struct node * find_artist(struct SongNode *start, char *artist);
struct node * find_song(struct SongNode *start, char *name);
struct node * insert_front(struct SongNode *next, char *name, char *artist);
struct node * insert_in(struct SongNode *first, int position, char *name, char *artist);
struct node * free_list(struct SongNode *first);
int list_length(struct SongNode *start);
void print_list(struct SongNode *first);
struct node * random_song(struct SongNode *first);