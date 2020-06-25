// URI - 1020

import java.io.IOException;
import java.util.Scanner;

public class URI1020 {
    public static void main(String[] args) {
        
        int dias=0;
        int mes=0;
        int ano=0;

        Scanner s= new Scanner (System.in);
        dias = s.nextInt();

        if (dias>=365) {
            while (dias>=365) {
                dias-=365;
                ano++;
            }
        }
        if (dias>=30) {
            while (dias>=30) {
                dias-=30;
                mes++;
            }
        }

        System.out.println (ano+ " ano(s)");
        System.out.println (mes+ " mes(es)");
        System.out.println (dias+ " dia(s)");

        s.close();
    }
}