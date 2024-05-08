#include "grains.h"
#include <math.h> 
#include <stdio.h>
uint64_t square(uint8_t index) {
    if (index < 1 || index > 64) {
        return 0;
    }
    return (pow(2, index-1));
}
/*uint64_t total(void) {
  uint64_t tot;
  for (int i = 1; i <= 64; i++) {
     tot += square(i);
  }
  // the sum exceeds the uint64_t. 
  // Return only the total on the 64st square
  return (uint64_t) pow(2, 64);
}*/

uint64_t total(void){
    uint64_t sum=0;
    uint64_t one=1;
    for (int i=0; i<64;i++ ){
        sum+=one<<i;
    }
    return sum;
} 