#include <stdio.h>
#include <math.h> 

int main(void){
     int sumOfSquares, squareOfSum, i, difference;
     sumOfSquares = 0; squareOfSum = 0;
     for ( i = 1; i <= 100; i++ ){
         sumOfSquares+=(i * i);
         squareOfSum+=i;
     }
     printf("Question 6: %d\n", abs((squareOfSum * squareOfSum) - sumOfSquares));
}
