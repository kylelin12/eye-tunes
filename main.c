#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./songnode/songnode.h"
#include "./songlibrary/eyetunes.h"

int main() {
    srand(time(NULL)); // Seeds the RNG

    // Insert Front
    printf("Inserting Front\n");
    struct SongNode *test = songnode_infront(NULL, "REALLY REALLY", "WINNER");
    songnode_print(test);

    test = songnode_infront(test, "clouds", "Flowtec");
    test = songnode_infront(test, "Flamingos", "Mujo");
    songnode_print(test);

    // Free the nodelist
    printf("\nFreeing the nodelist......\n");
    test = songnode_free(test);
    songnode_print(test);

    // Insert In Order
    struct SongNode *test2 = songnode_inorder(NULL, "REALLY REALLY", "WINNER");
    test2 = songnode_inorder(test2, "Stam Slap", "BluntOne");
    test2 = songnode_inorder(test2, "Palette", "IU");
    test2 = songnode_inorder(test2, "Father King", "Emancipator");
    songnode_print(test2);

    // Get
    printf("\nGetting in progress.......\n");
    printf("Getting by song... Emancipator - \"Father King\"\n");
    struct SongNode *find = songnode_get_song(test2, "Father King", "Emancipator");
    printf("Got: %s by %s\n", find->name, find->artist);

    printf("\nGetting by artist... IU - \"Palette\"\n");
    find = songnode_get_artist(test2, "IU");
    printf("Got: %s by %s\n", find->name, find->artist);

    printf("\nGetting by 404... Potato - \"Mine\"\n");
    find = songnode_get_artist(test2, "Potato");
    // printf("Got: %s by %s\n", find->name, find->artist);
    // Returns a seg fault as intended, commented out.

    printf("\nGetting by random...\n");
    int count;
    for (count = 0; count < 5; count++) {
        printf("\tLocated: #%d\n", count);
        find = songnode_get_ran(test2);
        printf("\tGot: %s by %s\n", find->name, find->artist);
    }

    // Removing nodes
    printf("\nRemoving Nodes\n");
    printf("Removing \"Palette\", \"Father King\", and \"WeeWoo\"");
    songnode_print(test2);
    test2 = songnode_delsong(test2, "Palette", "IU");
    test2 = songnode_delsong(test2, "Father Kind", "Emancipator");
    test2 = songnode_delsong(test2, "WeeWoo", "foo"); // doesn't exist
    songnode_print(test2);
    printf("\n\n\n\n\nSong Library time!\n");
    
    // Adding songs
    printf("\nAdding... songs\n");
    songlibrary_print(); // Prints everything
    songlibrary_add("Transparent", "DJ Okawari");
    songlibrary_add("North Latitude", "Michita");
    songlibrary_add("Frosty Fest", "Michita");
    songlibrary_add("Sangrilune", "Birocratic");
    songlibrary_add("Ontario", "Bonobo");
    songlibrary_print();

    // Getting songs
    printf("\nGetting... songs\n");
    printf("Trying to get... Michita - \"Frosty Fest\"\n");
    test2 = songlibrary_sname("Frosty Fest", "Michita");
    printf("Gotten: \"%s\" by %s\n", test2->name, test2->artist);

    printf("Trying to get... a song by Bonobo\n");
    test2 = songlibrary_sartist("Bonobo");
    printf("Gotten: \"%s\" by %s\n", test2->name, test2->artist);

    // Testing printing by letter
    printf("\nPrinting by letter...\n");
    songlibrary_print_letter('b');
    songlibrary_print_letter('m');

    // Testing printing by artist
    printf("\nPrinting by artist...\n");
    songlibrary_print_artist("Michita");
    songlibrary_print_artist("DJ Okawari");

    // Shuffling!
    printf("\nNow shuffling...\n");
    printf("Here are your shuffles: \n");
    songlibrary_shuffle(10);
    printf("\nEverything up to this point is a-okay!\n");

    return NULL;
}