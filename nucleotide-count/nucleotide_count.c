#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *count(const char *dna_strand) {
  if (!dna_strand)
    return (void *)0;
  int ACGT[4] = {0};
  char *output = calloc(sizeof(char), 50);
  for (size_t i = 0; dna_strand[i]; i++) {
    switch (dna_strand[i]) {
    case 'A':
      ACGT[0] += 1;
      break;
    case 'C':
      ACGT[1] += 1;
      break;
    case 'G':
      ACGT[2] += 1;
      break;
    case 'T':
      ACGT[3] += 1;
      break;
    default:
      strcpy(output, "");
      return output;
    }
  }

  sprintf(output, "A:%d C:%d G:%d T:%d", ACGT[0], ACGT[1], ACGT[2], ACGT[3]);
  return output;
}