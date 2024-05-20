#include "spiral_matrix.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

spiral_matrix_t *spiral_matrix_create(int size) {

    spiral_matrix_t *output = calloc(sizeof (spiral_matrix_t), 1);
    output->size= size;
    if (size == 0) {
        return output;
    }
    output->matrix = calloc(sizeof (int *), size);
    for (int i = 0; i < size ; i++) {
        output->matrix[i] = calloc(sizeof (int), size);
    }
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            output->matrix[i][j] = k++;
        }
    }
    
    
bool ** bitmap = calloc(sizeof (bool *), size + 1);
    for (int i = 0; i < size + 1; i++) {
        bitmap[i] = calloc(sizeof (bool), size+1);
    }
for (int i = 0; i < size+1; i++) {
        for (int j = 0; j < size+1; j++) {
            bitmap[i][j] = true;
            if (j == size) {
                bitmap[i][j] = false;
            }
            if (i == size) {
                bitmap[i][j] = false;
            }
        }
    }
    int row, col;
    row = col  = 0;
    char dir = 'E';

    for (int i = 1; i <= size * size;) {
        
        switch (dir) {
            case 'E':
                if (bitmap[row][col]) {
                    output->matrix[row][col] = i;
                    bitmap[row][col] = false;
                    i++;
                    col++;
                } else {
                    col--;
                    row++;
                    dir='S';
                }
                break;
            case 'S':
                if (bitmap[row][col]) {
                    output->matrix[row][col] = i;
                    bitmap[row][col] = false;
                    i++;
                    row++;
                } else {
                    col--;
                    row--;
                    dir='W';
                }
                break;
            case 'W':
                if ((col >= 0) && (bitmap[row][col])) {
                    output->matrix[row][col] = i;
                    bitmap[row][col] = false;
                    i++;
                    col--;
                } else {
                    row--;
                    col++;
                    dir='N';
                }
                break;
            case 'N':
                if (bitmap[row][col]){
                    output->matrix[row][col] = i;
                    bitmap[row][col] = false;
                    i++;
                    row--;
                } else {
                    row++;
                    col++;
                    dir='E';
                }
                break;
        }
    }
    for (int i = 0; i < size + 1; i++) {
        free(bitmap[i]);
    }
    free(bitmap);
    return output;
}

void spiral_matrix_destroy(spiral_matrix_t *actual) {

 for (int i=0; i < actual->size; i++) free(actual->matrix[i]);

    free(actual->matrix);
    free(actual);
}
