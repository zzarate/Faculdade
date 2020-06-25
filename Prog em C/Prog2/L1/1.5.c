/*receba um número inteiro positivo n e devolva a soma de seus
dígitos*/ 
#include <stdio.h>

int soma(int n){
	int aux=0;

	if (n<10){
		return n;
	}
	else {
		aux= n%10;
		return aux + soma(n/10);
	}
}

int main (){
	int n, result;

	scanf ("%d", &n);
	result= soma(n);
	printf("%d \n", result );

	return 0;
}	