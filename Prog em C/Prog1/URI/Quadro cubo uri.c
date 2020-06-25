#include <stdio.h>

int n, i, quad,cub;

int main (){
	scanf ("%d", &n);
	for (i=1;i<=n; i++){
		quad=i*i;
		cub=i*i*i;
		printf("%d %d %d\n",i,quad,cub);
	}
	return 0;
}
