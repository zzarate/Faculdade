#include <stdio.h>

int opt,a=0,g=0,d=0;

int main (){
	do{
		scanf ("%d", &opt);
		if(opt==1)
			a++;
		if(opt==2)
			g++;
		if(opt==3)
			d++;
	} while (opt != 4);
	printf("MUITO OBRIGADO\n");
	printf("Alcool: %d\n",a );
	printf("Gasolina: %d\n",g );
	printf("Diesel: %d\n",d );
	return 0;
}