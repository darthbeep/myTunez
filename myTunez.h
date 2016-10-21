//#ifndef SONG
typedef struct song_node{
  char title[256];
  char artist[256];
  struct song_node *next;
} song_node;

//#define SONG 0
//#endif

struct song_node * insert_front_node(struct song_node * song, struct song_node *head);
struct song_node * insert_front(char *, char *, struct song_node *head);
struct song_node * insert_place(char *, char *, struct song_node *head, int);
struct song_node * insert_place_node(struct song_node *new, struct song_node *head, int);
void print_nodes(struct song_node *head);
struct song_node * find_artist(char *, struct song_node * head);
struct song_node * find_song(char *, struct song_node * head);
struct song_node * random_node(struct song_node * head);
void shuffle(struct song_node *playlist);
void display_one(struct song_node *head);
struct song_node * delete(struct song_node * playlist, struct song_node *rem);
struct song_node * delete_all(struct song_node * playlist);
void print_artist(char *, struct song_node *playlist);
void print_letter(char, struct song_node *playlist);
int has_letter(char, struct song_node *playlist);
void better_print_list(struct song_node *playlist);
/*
//#include "myTunez.c"
#ifndef M
#include "main.c"
//#define MC 3
#endif

#ifndef MC
#include "myTunez.c"
//#define M 3
#endif
*/
