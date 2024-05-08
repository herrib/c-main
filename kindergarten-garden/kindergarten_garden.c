#include "kindergarten_garden.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

plants_t plants(const char *diagram, const char *student) {

  plants_t t; // the return
  plant_t plants[4]; // used as buffer to set up the return
  size_t idx_plants = 0;
  char *sequence = calloc(sizeof(char), 3); // sequence of 2 chars corresponding to the flowers
  char **diagrams = malloc(sizeof(char *) * 2);
  diagrams[0] = calloc(sizeof(char), (strlen(diagram) / 2) + 1);
  diagrams[1] = calloc(sizeof(char), (strlen(diagram) / 2) + 1);
  
  /*diagram is broken down in two strings */
  size_t idx = 0;
  for (size_t i = 0; diagram[idx] != '\n'; i++, idx++) {
    diagrams[0][i] = diagram[idx];
  }
  idx++;
  for (size_t i = 0; idx < strlen(diagram); i++, idx++) {
    diagrams[1][i] = diagram[idx];
  }

/* determine the rank of the student*/
  size_t rank = get_rank_student(student);

/* extract the sequence corresponding to the student
 * find the code (plant_t) and populate the buffer  */
  get_sequence(diagrams[0], rank, sequence);
  for (int i = 0; sequence[i]; i++) {
    plants[idx_plants++] = get_code_plant(sequence[i]);
  }
  get_sequence(diagrams[1], rank, sequence);
  for (int i = 0; sequence[i]; i++) {
    plants[idx_plants++] = get_code_plant(sequence[i]);
  }
/*finally, populate the arry of the returned structure*/
  for (int i = 0; i < 4; i++) {
    t.plants[i] = plants[i];
  }

  /*free the allocated  memory */
  for (int i = 0; i < 2; i++) {
    free(diagrams[i]);
  }
  free(diagrams);
  free(sequence);

  return t;
}

size_t get_rank_student(const char *student) {
  char *students[] = {"Alice",  "Bob",    "Charlie", "David",
                      "Eve",    "Fred",   "Ginny",   "Harriet",
                      "Ileana", "Joseph", "Kincaid", "Larry"};
  size_t rank = 0;
  for (rank = 0; rank < 12; rank++) {
    if (strcmp(students[rank], student) == 0) {
      return rank;
    }
  }
  return -1;
}

plant_t get_code_plant(char c) {
  char plant[] = {'C', 'G', 'R', 'V'};
  for (plant_t i = CLOVER; i <= VIOLETS; i++) {
    if (plant[i] == c)
      return i;
  }
  return UNKNOWN;
}

void get_sequence(char *diagrams, size_t rank, char *sequence) {
  size_t count = 0;
  size_t idx = 0;
  for (size_t i = 0; i < strlen(diagrams); i++) {
    if ((i % 2 == 0) && (i > 1)) {
      count++;
    }
    if (count == rank) {
      sequence[idx++] = diagrams[i];
    }
  }
}