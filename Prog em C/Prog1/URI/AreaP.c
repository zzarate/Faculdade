#include <stdio.h>

int main() {

   int r; // Aqui na pratica nao faz diferenca, mas no exercio pede pra ser double tambem
   double pi, area;
     pi = 3.14159;
     scanf ("%d", &r);
     area = pi*(r*r); /* Teoricamente, funciona o parenteces que tu colocou, mas recomendo fazer passso a passo literalmente, tipo, primeiro a multiplicacao
     e depos tu multiplica pi pelo resultado. Ou tu pode fazer o resultado multiplicado direto por 3.14159*/
     printf ("A=%.4f\n", area);

     return 0;
}