int main(void){
    int total = 0;
    int i;
    for ( i = 0; i < 1000; ++i ){
        if (i % 5 == 0 || i % 3 == 0){
              total+=i;
        }
    }
    printf("Question 1: %d\n", total);
    getch();
}
