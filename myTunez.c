//#define MC 0
#include "myTunez.h"

void print_nodes(struct song_node * head) {
  //This is the not as cool version of print list that I'm just going to leave in although it serves no purpose
  if (head == 0) {
    printf("Your list is empty. :(\n");
  }
  struct song_node *curr = head;
  while (curr != 0) {
    printf("%s - %s\n", curr->artist, curr->title);
    curr=curr->next;
  }
}

void display_one(struct song_node *head) {
  printf("Song: %s - %s\n", head->artist, head->title);
}

struct song_node * insert_front(char * t, char * a, struct song_node * head) {
  printf("Adding %s - %s\n", a, t);
  struct song_node * new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new->title, t);
  strcpy(new->artist, a);
  return insert_front_node(new, head);
}

struct song_node * insert_front_node(struct song_node * song, struct song_node *head) {
  song->next = head;
  return song;
}

struct song_node * insert_place(char * t, char * a, struct song_node * head, int place) {
  printf("Adding %s - %s in zero index place: %d:\n", a, t, place);
  struct song_node * new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new->title, t);
  strcpy(new->artist, a);
  return insert_place_node(new, head, place);
}

struct song_node * insert_place_node(struct song_node *new, struct song_node *head, int place) {
  struct song_node *curr = head;
  if (place == 0) {
    return insert_front_node(new, head);
  }
  for (int i = 0; i < place-1; i++) {
    //printf("%d\n", curr);
    //curr=curr->next;
    if (curr->next == 0) {
      printf("%s\n", "Out of bounds");
      return 0;
    }
    curr=curr->next;
  }
  new->next = curr->next;
  curr->next = new;
  return head;
}

struct song_node * find_artist(char * a, struct song_node * head) {
  printf("Finding node for artist %s:\n", a);
  struct song_node * curr = head;
  while (curr != 0) {
    if (strcmp(a, curr->artist) == 0) {
      return curr;
    }
    curr=curr->next;
  }
  printf("Song not found\n");
  return head;
}

struct song_node * find_song(char * t, struct song_node * head) {
  //This will probably be silent because it's more of a helper function than a useful thing
  //printf("Finding node for song %s:\n", t);
  struct song_node * curr = head;
  while (curr != 0) {
    if (strcmp(t, curr->title) == 0) {
      return curr;
    }
    curr=curr->next;
  }
  printf("Song not found\n");
  return head;
}

void print_artist(char * artist, struct song_node *playlist) {
  //When delete code I usually comment it out before cleaning it up in the end
  //I had 22 lines of commented code before I cleaned it up
  //My code is a mess
  //I need a hobby
  //This line of code would be a profanity if I were less professional
  //Please don't ask about artist_list and alcurr
  //Just don't
  printf("Priting all nodes for artist %s:\n", artist);
  struct song_node *artist_list = (struct song_node *) malloc(sizeof(struct song_node ));
  struct song_node *alcurr = (struct song_node *) malloc(sizeof(struct song_node));
  alcurr = artist_list;
  struct song_node *curr = playlist;
  int i = 0;
  while (curr != 0) {
    if (strcmp(curr->artist, artist) == 0 ) {
      printf("%s - %s   ", curr->artist, curr->title);
      i++;
    }
    curr=curr->next;
  }
  if (i==0) {
    printf("No songs found. :(\n");
  }
  else {
    printf("\n");
  }
}

void print_letter(char letter, struct song_node *playlist) {
  struct song_node *artist_list = (struct song_node *) malloc(sizeof(struct song_node ));
  struct song_node *alcurr = (struct song_node *) malloc(sizeof(struct song_node));
  alcurr = artist_list;
  struct song_node *curr = playlist;
  printf("Printing all songs that start with the letter %c:\n", letter);
  int i = 0;
  while (curr != 0) {
    if (curr->artist[0]==letter) {
      printf("%s - %s   ", curr->artist, curr->title);
      i++;
    }
    curr=curr->next;
  }
  if (i == 0) {
    printf("No songs found. :(\n");
  }
  else {
    printf("\n");
  }
}

int has_letter(char letter, struct song_node *playlist) {
  int i = 0;
  struct song_node * curr = playlist;
  while (curr != 0) {
    if (curr->artist[0] == letter) {
      i++;
    }
    curr = curr->next;
  }
  return i;
}

void better_print_list(struct song_node *playlist) {
  //printf("%d, %d\n", 'A', 'Z');
  int j = 0;
  for (int i = 65; i <= 90; i++) {
    if (has_letter(i, playlist)) {
      print_letter(i, playlist);
      j++;
    }
  }
  if (j == 0) {
    printf("Your list is empty. :(\n");
  }
}

int playlist_length(struct song_node *playlist) {
  //This function is entirely useless
  //It serves no purpose
  //The code requiring it is long gone
  //No one cares for it
  //No one will ever love it
  //No one would notice if it were gone
  //It doesn't have friends
  //Or family
  //Or teachers
  //It is alone
  //Entirely alone
  //And yet I feel more dead inside than it
  //Ok actually I added a function that uses you but my point still stands
  struct song_node * curr = playlist;
  int i = 0;
  while (curr != 0) {
    curr=curr->next;
    i++;
  }
  return i;
}

struct song_node * delete(struct song_node *playlist, struct song_node *rem) {
  printf("Deleting %s - %s\n", rem->artist, rem->title);
  //The if statement below hardcoded fix to the bug that I have spent far too long trying to figure out
  //I'm actually listening to Being Alive by Audiomachine right now
  //I don't know why I feel the need to include that
  //I'm just really tired and angry right now because code is stupid and that song is the only thing keeping me sane
  //Now if you're reading this you probably have a lot of questions
  //My answer is I'm really tired and I finally got this function right
  //I've always wanted to be a professional programmer, but with how angry this code is making me, I have no idea if I'd be good at that
  //Someone please help me
  //Please
  if (strcmp(rem->artist, playlist->artist) == 0 && strcmp(rem->title, playlist->title)==0) {
    playlist = playlist->next;
    return playlist;
  }
  struct song_node *curr = playlist;
  struct song_node *follow = playlist;
  while (curr != 0) {
    if (strcmp(rem->artist, curr->artist) == 0 && strcmp(rem->title, curr->title) == 0) {
      //printf("  Shound be deleted: %s - %s\n", follow->next->artist, follow->next->title);
      follow->next = follow->next->next;
    }
    if (follow != curr) {
      follow=follow->next;
    }
    curr=curr->next;
  }
  return playlist;
}

struct song_node * random_node(struct song_node *playlist) {
  struct song_node *curr = playlist;
  struct song_node *wait = playlist;
  int pl = playlist_length(playlist);
  double len =  (double)1/(double)playlist_length(playlist) * 2;
  struct song_node *hold = playlist;
  while (1) {
    double r = (double)rand() / 2147483647;
    //printf("%g, %g\n", r, len);
    if (r < (len)) {
      hold = curr;
      return hold;
    }
    curr=curr->next;
    if (curr==0) {
      curr=wait;
    }
  }
  return hold;
}

void shuffle(struct song_node *playlist) {
  printf("Your shuffled playlist:\n");
  for (int i = 0; i < 3; i++) {
    display_one(random_node(playlist));
  }
}

struct song_node * delete_all( struct song_node * playlist ) {
  //Kind of stolen from DW
  struct song_node *curr = playlist;
  while (playlist != 0) {
    playlist  = playlist->next;
    printf("Freeing %s - %s\n", curr->artist, curr->title );
    free(curr);
    curr = playlist;
  }
  return playlist;
}

//Wow
//I did it
//It took 246 lines of code
//But I did it
//I got it all
//I win
//I want a cookie or something
//Now I'm rambling
//But that's ok
//I'm so tired
//But I did it
//I wrote the function
//I can die happy now
