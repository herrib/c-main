#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <stddef.h>
#include <stdint.h>

char **annotate(const char **minefield, const size_t rows);
void free_annotation(char **annotation);
typedef struct position position_t;
struct position {
  size_t row;
  size_t column;
  position_t *up;
  position_t *down;
  position_t *left;
  position_t *right;
  char value;
  int count;
};
void init_positions(position_t **positions, const size_t rows,
                    const char **minefield);
void setup_positions(position_t **positions, const size_t rows,
                     size_t max_columns);
void setup_board(position_t **positions, const size_t rows,
                 size_t max_columns, char **board);
void free_positions(position_t **positions, size_t rows);
#endif
