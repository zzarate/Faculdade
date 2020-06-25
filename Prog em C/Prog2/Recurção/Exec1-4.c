#include <stdio.h>
#define MAX 100

float soma (int n,float V[MAX]){
	if (n == 1){
		return V[0];
	}
	else
		V[n-1] += V[n-2]+ V[n-1];
		return soma (n-1, V);

}

int main (){
	float V[MAX];
	int n;
	scanf ("%d", &n);

	for (int i=0; i<n; i++){
		scanf ("%f", &V[i]);
	}
	printf("%.2f\n", soma (n, V) );

	return 0;
}