int total = 0; // current total

// loop through fibbonacci
        
int n2 = 1;
int n1 = 1;
int current = 2;
        
while (current < 4000000){
    //System.out.println(current);
    if (current % 2 == 0 && current < 4000000){
        // current is even
        total += current;
    }
    // increment
    n2 = n1;
    n1 = current;
    current = n1 + n2;

}
return total;
