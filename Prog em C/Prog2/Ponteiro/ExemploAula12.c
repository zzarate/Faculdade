#include <stdio.h>
#define N 10
int main(void){
	int v[N], *p;
	printf("Informe %d números: ", N);
	for (p = v; p < v + N; p++)
		scanf("%d", p);
	printf("Em ordem inversa: ");
	for (p = v + N - 1; p >= v; p--)
		printf("%d ", *p);
	printf("\n");
	return 0;
}
