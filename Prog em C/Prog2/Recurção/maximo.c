/*Encontra o maior valor */

#include <stdio.h>
#define MAX 100

int maximo (int n, int V[MAX]){
	int aux;
	if (n==1)
		return V[0];
	else{
		aux=maximo(n-1, V);
		if (aux>V[n-1])
			return aux;
		else
			return V[n-1];
	}
}

int main (){
	int n;
	int V[MAX];

	scanf ("%d", &n);

	for (int i=0; i<n; i++){
		scanf ("%d", &V[i]);
	}

	printf("%d\n", maximo(n, V) );

	return 0;

}
