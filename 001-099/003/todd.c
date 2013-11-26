#include <stdio.h>
#include <math.h> 
#include <stdbool.h>

bool isPrime(int num){
     float current = 3.0;
     float currentDiv;
     float cap = sqrt(num);
     if (num % 2 == 0){
          if (num == 2){
               return true;
          }
          return false;
     }
     // only odd numbers remain
     while (1){
           if (current > cap){
                break;
           }
           currentDiv = (float)num / current;
           if (currentDiv == (int)currentDiv){
                return false;
           }
           current+=2;
     }     
     return true;
}

int main(void){
     // start at 600851475143
     // first factor hit is the highest
     long long int num = 600851475143;
     int max = 0;
     float cap = sqrt(num);
     // only odd numbers will be factors
     int current = 5;
     while (1){
           if ((float)current > cap){
                break;
           }
           // check if prime
           if (isPrime(current)){
                // check if factor
                if ((num % current) == 0){
                        // prime factor
                        max = current;
                }
           }
           current++;
     }
     printf("Question 3: %d\n", max);
     getch();
}
