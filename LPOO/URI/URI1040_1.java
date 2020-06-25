// URI 1040

/* As notas precisam ser convertidas
* usando BigDecimal, para obter a 
* precisão de apenas uma casa após
* a virgula. Para isso, a entrada deve
* ser em formato de string, e após
*/

import java.io.IOException;
import java.util.Scanner;
import java.math.BigDecimal;

public class URI1040_1 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner (System.in);
        BigDecimal dec = new BigDecimal ();
        String n1 = s.nextLine();
        String n2 = s.nextLine();
        String n3 = s.nextLine();
        String n4 = s.nextLine();

        String media = ((n1*2)+(n2*3)+(n3*4)+n4)/10;
        System.out.println ("Media: "+dec.add(media));
        if (media>=7){
            System.out.println ("Aluno aprovado.");
        } else {
            if (media<5){
            System.out.println ("Aluno reprovado.");
            } else if (media>=5 && media<7) {
                System.out.println ("Aluno em exame.");
                String exame = s.nextLine();
                System.out.println ("Nota do exame: "+exame);
                media= (media+exame)/2;
                if (media>=5){
                    System.out.println ("Aluno aprovado.");
                } else {
                    System.out.println ("Aluno reprovado.");
                }
                System.out.println ("Media final: "+dec.add(media));
            }
        }

        s.close();
    }
}