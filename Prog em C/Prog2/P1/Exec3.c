/*João Víctor Zárate*/
/*Alg Prog 2*/
/* P1 - Exercio 3*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int compara (int i, int n, int V[]){

	if (i<n){
		if (i == V[i])
			return i;
		else{
			i++;
			return compara (i, n, V);
		}
	}
	else
		return -1;
}

int main (){
	int k, n, V[MAX];

	scanf ("%d", &k);
	for (int i=0; i<k; i++){
		scanf ("%d", &n);
		for (int j=0; j<n; j++){
			scanf ("%d", &V[j]);
		}
	}

	printf("%d \n", compara (0, n, V) );

	return 0;
}
