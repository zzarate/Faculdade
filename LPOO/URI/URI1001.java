// URI - 1001

import java.io.IOException;
import java.util.Scanner; 

public class URI1001 {
    public static void main (String[] args){

        Scanner s = new Scanner (System.in);

        int a = s.nextInt();
        int b = s.nextInt();
        int x = a+b;

        System.out.println ("X = " +x);
        s.close();
    }
}