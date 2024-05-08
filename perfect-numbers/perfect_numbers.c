#include "perfect_numbers.h"

kind classify_number(int number) {

if (number <=0) {
    return ERROR;
}

int total = 0;

    for (int i= 1; i <= number/2; i ++) {
        if (number % i == 0) {
            total += i;
        }
    }
    if (total > number) {
        return ABUNDANT_NUMBER;
    } else if (total < number) {
        return DEFICIENT_NUMBER;
    } else {
        return PERFECT_NUMBER;
    }
}