#include "protein_translation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

proteins_t proteins(const char *const rna) {

  codon_t *codons = calloc(sizeof(codon_t), MAX_SIZE_L_CODONS);
  codons[0] = (codon_t){"AUG", Methionine};
  codons[1] = (codon_t){"UUU", Phenylalanine};
  codons[2] = (codon_t){"UUC", Phenylalanine};
  codons[3] = (codon_t){"UUA", Leucine};
  codons[4] = (codon_t){"UUG", Leucine};
  codons[5] = (codon_t){"UCU", Serine};
  codons[6] = (codon_t){"UCC", Serine};
  codons[7] = (codon_t){"UCA", Serine};
  codons[8] = (codon_t){"UCG", Serine};
  codons[9] = (codon_t){"UAU", Tyrosine};
  codons[10] = (codon_t){"UAC", Tyrosine};
  codons[11] = (codon_t){"UGU", Cysteine};
  codons[12] = (codon_t){"UGC", Cysteine};
  codons[13] = (codon_t){"UGG", Tryptophan};
  codons[14] = (codon_t){"UAA", STOP};
  codons[15] = (codon_t){"UAG", STOP};
  codons[16] = (codon_t){"UGA", STOP};
  proteins_t proteins = {
      .count = 0,
      .valid = true,
  };
  if (!rna) {
    return proteins;
  }
  char *tmp = calloc(sizeof(char), 4);
  for (size_t i = 0; rna[i]; i++) {
    tmp[i % 3] = rna[i];
    if ((i + 1) % 3 == 0) {
      bool codon_found = false;
      for (int j = 0; j < MAX_SIZE_L_CODONS; j++) {
        if (strcmp(tmp, codons[j].codon) == 0) {
          if (codons[j].protein == STOP) {
            free(codons);
            free(tmp);
            return proteins;
          }
          proteins.proteins[proteins.count] = codons[j].protein;
          proteins.count += 1;
          codon_found = true;
          break;
        }
      }
      if (!codon_found) {
        proteins.valid = false;
        free(tmp);
        free(codons);
        return proteins;
      }
    }
  }
  if (strlen(rna) % 3) {
    proteins.valid = false;
  }
  free(tmp);
  free(codons);
  return proteins;
}