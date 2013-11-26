int main(void){
     // get initial set
     int current = 2;
     int lastOne = 1;
     int lastTwo = 1;
     int total = 2; // 2
     while (1){
           lastTwo = lastOne;
           lastOne = current;
           current = lastOne + lastTwo;
           if (current > 4000000){
                break;
           }
           if (current % 2 == 1){
                continue; // odd number
           }
           total+=current; // if less than 4000000
     }
     printf("Question 2: %d\n", total);
     getch();
}
