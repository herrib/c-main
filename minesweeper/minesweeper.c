#include "minesweeper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **annotate(const char **minefield, const size_t rows) {

  if (rows == 0) {
    return NULL;
  }
  size_t max_columns = strlen(minefield[0]);
  char **board = calloc(sizeof(char *), (rows + 1));
  position_t **positions = calloc(sizeof(position_t *), (rows + 1));
  
  for (size_t row = 0; row < rows; row++) {
    board[row] = calloc(sizeof(char), max_columns + 1);
    positions[row] = calloc(sizeof(position_t), max_columns  + 1);
  }
  for (size_t i = 0; i < rows; i++) {
    memcpy(board[i], minefield[i], strlen(minefield[i]) + 1);
  }

  init_positions(positions, rows, minefield);
  setup_positions(positions, rows, max_columns);
  setup_board(positions, rows, max_columns, board);
  free_positions(positions, rows + 1);
  return board;
}

void free_annotation(char **annotation) {
  if (annotation) {
    for (int i = 0; annotation[i]; i++) {
      free(annotation[i]);
    }
    free(annotation);
  }
}

void init_positions(position_t **positions, const size_t rows,
                    const char **minefield) {
  for (size_t row = 0; row < rows; row++) {
    for (size_t column = 0; column < strlen(minefield[row]); column++) {
      position_t t = (position_t){
          .row = row,
          .column = column,
          .value = minefield[row][column],
      };
      if (column > 0) {
        t.left = &positions[row][column - 1];
      }
      if (column + 1 < strlen(minefield[row])) {
        t.right = &positions[row][column + 1];
      }
      if (row > 0) {
        t.up = &positions[row - 1][column];
      }
      if (row + 1 < rows) {
        t.down = &positions[row + 1][column];
      }
      positions[row][column] = t;
    }
  }
}
void setup_positions(position_t **positions, const size_t rows,
                     size_t max_columns) {
  for (size_t row = 0; row < rows; row++) {
    for (size_t column = 0; column < max_columns; column++) {
      position_t *t = &positions[row][column];
      if (t->left) {
        if (t->left->value == '*') {
          t->count++;
        }
      }
      if (t->right) {
        if (t->right->value == '*') {
          t->count++;
        }
      }
      if (t->up) {
        if (t->up->value == '*') {
          t->count++;
        }
        if ((t->up->left) && (t->up->left->value == '*')) {
          t->count++;
        }
        if ((t->up->right) && (t->up->right->value == '*')) {
          t->count++;
        }
      }
      if (t->down) {
        if (t->down->value == '*') {
          t->count++;
        }
        if ((t->down->left) && (t->down->left->value == '*')) {
          t->count++;
        }
        if ((t->down->right) && (t->down->right->value == '*')) {
          t->count++;
        }
      }
    }
  }
}
void setup_board(position_t **positions, const size_t rows, size_t max_columns,
                 char **board) {
  for (size_t row = 0; row < rows; row++) {
    for (size_t column = 0; column < max_columns; column++) {
      if (positions[row][column].value != '*') {
        if (positions[row][column].count == 0) {
          board[row][column] = ' ';
        } else {
          board[row][column] = (char)positions[row][column].count + '0';
        }
      }
    }
  }
}

void free_positions(position_t **positions, size_t rows) {
  for (size_t i = 0; i < rows; i++) {
    free(positions[i]);
  }
  free(positions);
}