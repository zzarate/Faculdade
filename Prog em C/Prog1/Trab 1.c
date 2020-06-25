#include <stdio.h>
#include <string.h>
#include <math.h>
int main (void) {
    int test;
    int k, i, j;
    int n[8];      /* chave*/
    int d, o, h;   /* bases numericas*/
    int linha;
    int dec;
    int d, d1, d2;
    int aux = 0, aux1 = 0, aux2 = 0;
    int num;
    char bin;
    unsigned int oc;
    unsigned int hex;

    scanf("%d", &test); //quantidade de teste
    for(k = 1 ; k <= test ; k++) {
        printf("Teste %d:\n", k);

        for(i = 0 ; i <= 7 ; i++) {
            scanf(" %d", &n[i]);
        }   

        scanf("%d %d %d", &d, &o, &h);
        scanf("%d", &linha);

        for(j = 1 ; j <= linha ; j++) {
            if(j % h == 0) {
                scanf("%x", &hex);
                do{
                  d = hex % 2;
                  hex = hex / 2;
                  aux = (aux + d)*10;
                }while(hex > 0);

                num = aux;
            } 
            else if(j % o == 0) {
                scanf("%o", &oc);
                do{
                  d1 = oc % 2;
                  oc = oc / 2;
                  aux1 = (aux1 + d1)*10;
                }while(oc > 0);

                num = aux1;
            } 
            else if(j % d == 0) {
                scanf("%d", &dec);
                do{
                  d2 = dec % 2;
                  dec = dec / 2;
                  aux2 = (aux2 + d2)*10;
                }while(dec > 0);

                num = aux2;
            } 
            else {
                for(i = 0 ; i < 8 ; i++){
                scanf("%d", &bin[i]);
            }
            for(i = 0,j=7; j >= 0; j--, i++){
            final[i] = num[n[j]];

                
            }

        }
    }
    return 0;
}
