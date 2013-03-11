/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package euler1;

/**
 *
 * @author Todd Perry
 */
public class Euler1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int total = 0;
        for (int i = 0; i < 1000; i++) {
            if (i % 3 == 0 || i % 5 == 0){
                total += i;
            }
        }
        System.out.println(total);
    }
}
