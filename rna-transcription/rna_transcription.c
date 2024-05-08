#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
  int size = strlen(dna);
  char *rna = calloc(sizeof(char), size+1);
  int idx = 0;
  while (dna) {
    switch (*dna) {
    case 'G':
      rna[idx++] = 'C';
      break;
    case 'C':
      rna[idx++] = 'G';
      break;
    case 'T':
      rna[idx++] = 'A';
      break;
    case 'A':
      rna[idx++] = 'U';
      break;
    default:
      return rna;
    }
    dna++;
  }
  return rna;
}