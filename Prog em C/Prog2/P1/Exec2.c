/*João Víctor Zárate*/
/*Alg Prog 2*/
/* P1 - Exercio 2*/

#include <stdio.h>
#include <stdlib.h>

int calculaG (int n);

int calculaF (int n){
	int f;

	if (n == 1){
		f= 2;
	}
	else{
		if (n == 2 ){
			f= 1;
		}

		else{
			f= 2* calculaF (n-1) + calculaG (n-2);
		}
	}
	return f;
}
int calculaG (int n){
	int g;

	if (n == 1){
		g= 1;
	}
	else{
		if (n ==2 ){
			g=2;
		}

		else {
			g= calculaG( n-1) + 3 *calculaF (n-2);
		}
	}
	return g;
}

int main (){
	int k, n;

	scanf ("%d", &k);
	for (int i=0; i<k; i++){

		scanf ("%d", &n);
		printf("F= %d \n", calculaF(n) );
		printf("G= %d \n", calculaG(n) );
	}
	return 0;
}