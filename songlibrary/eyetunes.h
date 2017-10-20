struct SongNode *table[26];

// Returns the corresponding number for a given character
int alpha_num(char *);

// Adds a song to the library
void songlibrary_add(char *, char *);

// Search
struct SongNode *songlibrary_sname(char *, char *); // Searches by songname
struct SongNode *songlibrary_sartist(char *); // Searches by artist

// Print
void songlibrary_print_letter(char); // Prints songs by first letter of the artist
void songlibrary_print_artist(char *); // Prints songs by an artist
void songlibrary_print(); // Prints the entire library

// Returns the given int number of randomly selected songs
void songlibrary_shuffle(int);

// Deletions
void songlibrary_delete(char *, char *); // Removes a song from the song library
void songlibrary_wipe(); // Removes all the songs from the song library