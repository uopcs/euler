#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getLength(char string[]){
    int count = 0;
    while (string[count] != '\0'){ // keep going till escape char is hit
          count++;
    }
    return count;
}

bool isPalindrome(char string[]){
     int startPointer = 0;
     int endPointer = getLength(string) - 1;
     while (1){
           if (endPointer <= startPointer){
                // all character comparisons successful
                return true;
           }
           if (string[startPointer] != string[endPointer]){
                // not palindromic
                return false;
           }
           startPointer++;
           endPointer--;
     }
}

int void(main){
     // largest palindromic number from the product of two 3 digit numbers
     int i, j, product, strLen;
     int max = 0;
     char numStr[7]; // 6 characters + escape character
     for ( i = 999; i > 99; i-- ){
         for ( j = 999; j > 99; j-- ){
             product = i * j;
             // check if product is palindrome
             // convert product into string
             itoa(product, numStr, 10); // integer to string conversion
             if (isPalindrome(numStr)){
                  if (product > max){
                       max = product;
                  }
             } 
         }
     }
     printf("Question 4: %d\n", max);
     getch();
} 
