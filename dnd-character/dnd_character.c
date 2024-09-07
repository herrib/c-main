#include "dnd_character.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ability(void) {
  srand(time(NULL));
  return rand() % 15 + 3;
}

int modifier(int score) { return (int)floor(((float)score - 10) / 2); }
dnd_character_t make_dnd_character(void) {

  dnd_character_t output = (dnd_character_t){
      .strength = ability(),
      .dexterity = ability(),
      .constitution = ability(),
      .intelligence = ability(),
      .wisdom = ability(),
      .charisma = ability(),
  };
  output.hitpoints = 10 + modifier(output.constitution);
  return output;
}
