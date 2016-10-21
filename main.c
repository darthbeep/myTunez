#include <stdio.h>
#include <stdlib.h>

//#define M 0
#include "myTunez.h"


int main(int argc, char const *argv[]) {
  srand(time(0));
  struct song_node *playlist = (struct song_node *) malloc(sizeof(struct song_node));
  playlist = insert_front("Dream Chasers", "Future World Music", 0);
  playlist = insert_front("Gaurdians At The Gate", "Audiomachine", playlist);
  playlist = insert_front("Sirens of Hyperion", "Audiomachine", playlist);
  playlist = insert_front("Don't Lose Hope", "StormSound", playlist); //The title is me right now
  playlist = insert_front("Black Widow", "Matias Puumala", playlist);
  playlist = insert_front("Colors Of Love", "Thomas Bergersen", playlist);
  playlist = insert_front("The Last Hero", "Peter Crowley", playlist);
  playlist = insert_front("United We Stand, Divided We Fall", "Two Steps From Hell", playlist);
  playlist = insert_front("Atlantis", "Thomas Bergersen", playlist);
  playlist = insert_front("Bumblebee", "Steve Jablonsky", playlist);
  playlist = insert_front("Marauder", "Epic North", playlist);
  playlist = insert_front("Escaping the Kraken", "Peter Crowley", playlist);
  playlist = insert_front("Our Destiny", "Thomas Bergersen", playlist);
  playlist = insert_front("Being Alive", "Audiomachine", playlist);
  playlist = insert_front("Sariel", "Two Steps From Hell", playlist);
  playlist = insert_front("A Hero Will Rise", "Epic North", playlist);
  printf("\n");
  better_print_list(playlist);
  printf("\n");
  print_artist("Thomas Bergersen", playlist);
  printf("\n");
  print_letter('P', playlist);
  printf("\n");
  playlist = delete(playlist, find_song("Sariel", playlist));
  playlist = delete(playlist, find_song("Escaping the Kraken", playlist));
  playlist = delete(playlist, find_song("The Last Hero", playlist));
  printf("\n");
  better_print_list(playlist);
  printf("\n");
  shuffle(playlist);
  printf("\n");
  playlist = delete_all(playlist->next);
  better_print_list(playlist);

  return 0;
}
