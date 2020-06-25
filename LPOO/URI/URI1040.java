// URI 1040

import java.io.IOException;
import java.util.Scanner;

public class URI1040 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner (System.in);
        float n1 = s.nextFloat();
        float n2 = s.nextFloat();
        float n3 = s.nextFloat();
        float n4 = s.nextFloat();

        float media = ((n1*2)+(n2*3)+(n3*4)+n4)/10;
        System.out.printf ("Media: %.1f\n", media);
        if (media>=7){
            System.out.println ("Aluno aprovado.");
        } else {
            if (media<5){
            System.out.println ("Aluno reprovado.");
            } else if (media>=5 && media<7) {
                System.out.println ("Aluno em exame.");
                float exame = s.nextFloat();
                System.out.printf ("Nota do exame: %.1f\n", exame);
                media= (media+exame)/2;
                if (media>=5){
                    System.out.println ("Aluno aprovado.");
                } else {
                    System.out.println ("Aluno reprovado.");
                }
                System.out.printf ("Media final: %.1f\n", media);
            }
        }

        s.close();
    }
}