/*João Víctor Zárate*/
/*Alg Prog 2*/
/* P1 - Exercio 1*/

#include <stdio.h>
#include <stdlib.h>

int potencia (int x, int n){
	int aux=1;

	if (n == 0){
		return 1;
	}

	else{
		if (n%2 == 0){
			n= n/2;
			for (int i=1; i<=n; i++){
				aux= aux*x;
			}
			return aux*aux;
		}

		else{
			n= n-1;
			for (int i=1; i<=n; i++){
				aux= aux*x;
			}
			return aux*x;

		}
	}

}

int main(){
	int k;
	int a, b;

	scanf ("%d", &k);
	for (int i=0; i< k; i++){
		scanf ("%d %d", &a, &b);

		printf("%d \n",potencia (a, b) );
	}

	 return 0;
}