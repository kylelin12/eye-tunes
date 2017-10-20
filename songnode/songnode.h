struct SongNode {
    char name[256];
    char artist[256];
    struct SongNode *next;
};

struct SongNode *songnode_new(struct SongNode *, char *, char *);
int sn_length(struct SongNode *);

// Prints the SongNode
void songnode_print(struct SongNode *);

// Insert Functions
struct SongNode *songnode_infront(struct SongNode *, char *, char *); // Inserts front
struct SongNode *songnode_inorder(struct SongNode *, char *, char *); // Inserts inorder

// Grab songs
struct SongNode *songnode_get_song(struct SongNode *, char *, char *); // Grabs a song by songname
struct SongNode *songnode_get_artist(struct SongNode *, char *); // Grabs a song by artist
struct SongNode *songnode_get_ran(struct SongNode *); // Grabs a random song

// Deletion stuff
struct SongNode *songnode_delsong(struct SongNode *, char *, char *); // Deletes a song
struct SongNode *songnode_free(struct SongNode *); // Frees the SongNode
