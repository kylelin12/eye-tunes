#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linkedlist.h"

struct SongNode * del_entry(struct SongNode *start, char *name) {
    struct SongNode *current;
    struct SongNode *previous;

    previous = NULL;

    for (current = start; current; current = current->next) {
        if (current->name == name) {
            if (previous == NULL)
                start = current->next;
            else
                previous->next = current->next;
        }
    }
    return start;
}

struct SongNode * find_artist(struct SongNode *start, char *artist) {
    while (start) {
        if (start->artist == artist)
            return start;
        start = start->next;
    }
    return NULL;
}

struct SongNode * find_song(struct SongNode *start, char *name) {
    while (start) {
        if (start->name == name)
            return start;
        start = start->next;
    }
    return NULL;
}

struct SongNode * insert_front(struct SongNode *next, char *name, char *artist) {
    struct SongNode *newSongNode = (struct SongNode *)malloc(sizeof(struct SongNode));
    newSongNode->name = name;
    newSongNode->artist = artist;
    newSongNode->next = next;
    return newSongNode;
}

struct SongNode * insert_in(struct SongNode *first, int position, char *name, char *artist) {
    struct SongNode *current;
    struct SongNode *previous;
    struct SongNode *place;

    current = first;
    previous = NULL;
    int i = 0;

    for (i = 0; i < position; i++) {
        current = current->next;
    }
    previous = current;
    current = current->next;
    place = insert_front(current, name, artist);
    previous->next = place;
    return first;
}

struct SongNode * free_list(struct SongNode *first) {
    struct node *temp;
    while (first) {
        temp = first;
        first = first->next;
        free(temp);
    }
    return first;
}

void print_list(struct SongNode *first) {
    struct SongNode *current = first;
    while (first) {
        printf("%s - %s\n", current->name, current->artist);
        current = current->next;
    }
}

int list_length(struct SongNode *start) {
    int i = 0;
    struct SongNode *current = start;
    while (current) {
        i++;
        current = current->next;
    }
    return i;
}

struct SongNode * random_song(struct SongNode *first) {
    srand(time(NULL));

    struct SongNode *current = first;
    
    int length = list_length(current);
    int ran_num = rand() * length;
    int i;

    for (i = 0; i < ran_num; i++) {
        first = first->next;
    }

    return first;
}