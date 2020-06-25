//URI 1060

import java.io.IOException;
import java.util.Scanner;

public class URI1060 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        double n;
        int i=0;
        int j=0;

        while (i<6){
            n= s.nextDouble();
            if (n>0){
                j++;
            }
            i++;
        }
        s.close();
        

        System.out.println (j+ " valores positivos");

    }
}