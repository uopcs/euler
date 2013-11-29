#include <stdio.h>
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
     // 10001st prime number
     int primeCount = 0;
     int count = 2;
     while (1){
           // check if number is prime
           if (isPrime(count)){
                 primeCount++;
           }
           if (primeCount == 10001){
                break;
           }
           count++;
     }
     printf("Question 7: %d\n", count);
     getch();
}
