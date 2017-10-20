#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "songnode.h"

// Creates SongNodes
struct SongNode *songnode_new(struct SongNode *next, char *name, char *artist) {
    struct SongNode *songnode = (struct SongNode *)malloc(sizeof(struct SongNode));
    strcpy(songnode->name, name);
    strcpy(songnode->artist, artist);
    songnode->next = next;
    return songnode;
}

// Returns the length of the SongNode
// Useful for generating random songs
int sn_length(struct SongNode *node) {
    int length = 0;
    while (node) {
        length++;
        node = node->next;
    }
    return length;
}

// Prints the SongNode
void songnode_print(struct SongNode *nodelist) {
    printf("\nSONGS:\n");
    // While nodelist is not NULL
    while (nodelist) {
        printf("\t%s - \"%s\"\n", nodelist->artist, nodelist->name); // Prints in Artist - "Song" format
        nodelist = nodelist->next; // Moves the pointer to the next node in the list
    }
    printf("END SONGS\n");
}

// Inserts a new SongNode to the beginning of the SongNode (list)
// Returns a pointer to the new SongNode
struct SongNode *songnode_infront(struct SongNode *prev, char *name, char *artist) {
    return songnode_new(prev, name, artist);
}

// Inserts a new SongNode in alphabetical order
// By artist name -> by song name
struct SongNode *songnode_inorder(struct SongNode *nodelist, char *name, char *artist) {
    struct SongNode *beginning = nodelist; // Pointer at the beginning of the give list
    // If nodelist is not NULL or if the artist comes before or is equal to the first artist in the list
    // and the song name comes before then add the song to the front of the nodelist
    if (!nodelist || (strcmp(artist, nodelist->artist) < 0) || 
    (strcmp(artist, nodelist->artist) == 0 && strcmp(name, nodelist->name) <= 0)) {
        return songnode_infront(nodelist, name, artist); // Returns a pointer to the new 'front'
    }
    // While the next node is not NULL and the artist is after the next song's artist
    while (nodelist->next && strcmp(artist, nodelist->next->artist) > 0)
        nodelist = nodelist->next;
    // While the next node is not NULL and the song name is after the next song's name
    while (nodelist->next && strcmp(name, nodelist->next->name) > 0)
        nodelist = nodelist->next;
    // Set the pointer for the next node equal to a new node
    nodelist->next = songnode_new(nodelist->next, name, artist);
    return beginning; // Returns a pointer to the beginning of the nodelist
}

// Find and return a pointer to the requested song
struct SongNode *songnode_get_song(struct SongNode *nodelist, char *name, char *artist) {
    while (nodelist) {
        if (strcmp(name, nodelist->name) == 0 && strcmp(artist, nodelist->artist) == 0)
            return nodelist;
        nodelist = nodelist->next;
    }
    return NULL;
}

// Find and return a pointer to the requested artist
struct SongNode *songnode_get_artist(struct SongNode *nodelist, char *artist) {
    while (nodelist) {
        if (strcmp(artist, nodelist->artist) == 0)
            return nodelist;
        nodelist = nodelist->next;
    }
    return NULL;
}

// Find and return a pointer to a random song
struct SongNode *songnode_get_ran(struct SongNode *nodelist) {
    int nl_length = sn_length(nodelist);
    int ran_num = rand() % nl_length;
    while (ran_num > 0) {
        nodelist = nodelist->next;
        ran_num--;
    }
    return nodelist;
}

// Removes the specified song from the songlist
struct SongNode *songnode_delsong(struct SongNode *nodelist, char *name, char *artist) {
    struct SongNode *temp;
    // If the specified song is the first node
    if (strcmp(name, nodelist->name) == 0 && strcmp(artist, nodelist->artist) == 0) {
        temp = nodelist->next;
        free(nodelist);
        return temp;
    }
    struct SongNode *beginning = nodelist; // Pointer to the beginning of the nodelist
    while (nodelist->next) {
        if (strcmp(name, nodelist->name) == 0 && strcmp(artist, nodelist->artist) == 0) {
            temp = nodelist->next->next;
            free(nodelist->next);
            nodelist->next = temp;
            return beginning;
        }
        nodelist = nodelist->next;
    }
    return beginning;
}

// Frees the entire nodelist starting at the given pointer
struct SongNode *songnode_free(struct SongNode *nodelist) {
    while (nodelist) {
        struct SongNode *temp = nodelist;
        nodelist = nodelist->next;
        free(temp);
    }
    return nodelist;
}