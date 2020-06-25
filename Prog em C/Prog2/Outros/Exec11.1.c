#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void gera(int n, int v[]){
	int i;
	for(i=0; i<n; i++)
		v[i]= rand()%20000;
}

void min_max (int n, int V[MAX], int *max, int *min){

	*max= V[0];
	*min= V[0];

	for (int i=1 ; i<n; i++){
		if (V[i]>*max)
			*max=V[i];
		if (V[i]<*min)
			*min=V[i];
	}
}

int main (){
	int V[MAX];
	int n;
	int max, min;


	scanf ("%d", &n);
	gera (n, V);
	for (int i = 0; i < n; ++i){
		printf("%d ", V[i] );
	}
	printf("\n");

	min_max (n, V, &max, &min);

	printf("Min= %d, max=%d \n", min, max );



}