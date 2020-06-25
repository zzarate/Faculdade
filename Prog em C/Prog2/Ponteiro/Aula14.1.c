//Ponteiro para função

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tabela (double (*f) (double), double a, double b, double incr){
	int i, num_intervalo;
	double x;
	num_intervalo= ceil ((b-a)/incr);

	for (i=0; i<= num_intervalo; i++){
		x=a+i*incr;
		printf("%11.6f %11.6f\n",x, (*f)(x) );
	}
}

int main (){
	double inicio, fim, incremento;
	printf("Informe um intervalo [a, b]: \n");
	scanf ("%lf %lf", &inicio, &fim);
	printf("Informe um incremento: \n");
	scanf ("%lf", &incremento);

	tabela(cos, inicio, fim, incremento);
	tabela(sin, inicio, fim, incremento);
	tabela(tan, inicio, fim, incremento);

	return 0;
}