#include "beer_song.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char ret[] = "";

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {

  int nb_bottles = (int)start_bottles;
  int nb_verses = (int)take_down * 3;
  int idx = 0;
  int round = 0;
  char msg[MAX_LINE_LENGTH];
  bool end = false;
  for (int i = 0; i < nb_verses; i++) {
    switch (round) {
    case 0:
      if (nb_bottles > 1) {
        sprintf(msg, "%d bottles of beer on the wall, %d bottles of beer.",
                nb_bottles, nb_bottles);
        strcpy(song[idx], msg);
      } else if (nb_bottles == 1) {
        sprintf(song[idx], "%d bottle of beer on the wall, %d bottle of beer.",
                nb_bottles, nb_bottles);
      } else if (nb_bottles == 0) {
        sprintf(
            song[idx],
            "No more bottles of beer on the wall, no more bottles of beer.");
      } else {
        sprintf(song[idx], "Go to the store and buy some more, 99 bottles of "
                           "beer on the wall.");
      }
      nb_bottles--;
      round++;
      break;
    case 1:
      if (nb_bottles > 1) {
        sprintf(
            song[idx],
            "Take one down and pass it around, %d bottles of beer on the wall.",
            nb_bottles);
      } else if (nb_bottles == 1) {
        sprintf(
            song[idx],
            "Take one down and pass it around, %d bottle of beer on the wall.",
            nb_bottles);
      } else if (nb_bottles == 0) {
        sprintf(song[idx], "Take it down and pass it around, no more bottles "
                           "of beer on the wall.");
      } else {
        sprintf(song[idx], "Go to the store and buy some more, 99 bottles of "
                           "beer on the wall.");
        end = true;
      }
      round++;
      break;
    case 2:
      sprintf(song[idx], ret);
      round = 0;
      break;
    }
    if (end) {
      return;
    }
    idx++;
  }
}
