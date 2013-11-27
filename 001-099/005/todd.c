#include <stdio.h>

int main(void){
     int count, i;
     count = 1;
     while (1){
           for ( i = 1; i < 20; i++){
               if (count % i != 0){
                    break;
               }
               if (i == 19){ // hasn't exited for loop
                     printf("Question 5: %d\n", count);
                     getch();
                     return;
               }
           }
           count++;
     }
}
