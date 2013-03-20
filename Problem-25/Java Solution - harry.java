package projectEuler;  
  
public class Fibonacci {  
    public static long fib(long n) {  
                         if (n < 2) {  
                            return n;  
                        }  
                         else {  
                   return fib(n-1)+fib(n-2);  
                         }  
            }  
    public static void main(String[] args) {  
        long x=0;  
                for (long i=0; i<=Long.MAX_VALUE; i++)  
                  {  
                      
                      if(Long.toString(fib(i)).length()==10){  
                          System.out.println(fib(i));  
                         break;  
                      }  
                  }  
            }  
              
         } 
