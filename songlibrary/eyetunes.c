#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../songnode/songnode.h"
#include "eyetunes.h"

// Returns the alpha-numeric value for the first 
// letter of the artist's name
int alpha_num(char *artist) {
    // If the first letter of the artist is capitalized
    if ((artist[0] >= 'A') && (artist[0] <= 'Z'))
        return artist[0] - 'A';
    else // Otherwise, it's lowercase
        return artist[0] - 'a';
}

// Adds a song to the library
void songlibrary_add(char *name, char *artist) {
    struct SongNode *a = table[alpha_num(artist)]; // Creates a pointer to the corresponding letter
    table[alpha_num(artist)] = songnode_inorder(a, name, artist); // Inserts song in order
}

// Returns a pointer to the song with the name and artist
struct SongNode *songlibrary_sname(char *name, char *artist) {
    struct SongNode *a = table[alpha_num(artist)]; // Creates a pointer to the corresponding letter
    return songnode_get_song(a, name, artist);
}

// Returns a pointer to the first song from artist
struct SongNode *songlibrary_sartist(char *artist) {
    struct SongNode *a = table[alpha_num(artist)]; // Creates a pointer to the corresponding letter
    return songnode_get_artist(a, artist);
}

// Prints out all songs with an artist starting with the ltter
void songlibrary_print_letter(char letter) {
    printf("With the letter: %c", letter);
    // letter - 'a' is an index between 0 and 25.
    // letter itself is not between 0 and 25.
    songnode_print(table[letter - 'a']); 
}

// Prints out all songs made by a certain artist
void songlibrary_print_artist(char *artist) {
    printf("Artist, %s, has made:", artist);
    struct SongNode *a = table[alpha_num(artist)];
    a = songnode_get_artist(a, artist);
    songnode_print(a);
}

// Prints out all songs in the library
void songlibrary_print() {
    int count = 0;
    printf("Printing library...\n");
    while (count < 26) {
        // If the table[count] is not empty, print everything in it
        if (table[count]) {
            printf("Current letter: %c", 'a' + count);
            songnode_print(table[count]);
        }
        count++;
    }
    printf("Library printing complete...\n");
}

// Prints out n number of randomly selected songs
void songlibrary_shuffle(int n) {
    int ran_num;
    struct SongNode *a;
    while (n) {
        ran_num = rand() % 26; // Random number between 0-25 -> a-z
        if (table[ran_num]) {
            n--;
            a = songnode_get_ran(table[ran_num]);
            printf("\n\tRandom Song: %s - \"%s\"", a->artist, a->name);
        }
    }
}

// Deletes a song from the library
void songlibrary_delete(char *name, char *artist) {
    struct SongNode *a = table[alpha_num(artist)]; // Creates a pointer to the corresponding letter
    table[alpha_num(artist)] = songnode_delsong(a, name, artist); // Deletes the song from the letter-node
}

// Wipes the library
void songlibrary_wipe() {
    int count = 26;
    while (count) {
        songnode_free(table[count - 1]); // Frees starting from z -> a
        count--; 
    }
}