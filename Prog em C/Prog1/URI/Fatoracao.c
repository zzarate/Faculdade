#include <stdio.h>

int i,num, aux, totp, tot;

int main (){
	printf("Digite o numero que deseja fatorar: \n");
		scanf ("%d", &num);
		num=aux;
		for(i=0; i<num; i++){
			totp=aux*--aux;
			tot=totp*--aux;
		}
		printf("%d! = %d\n",num, tot );
			return 0;
}