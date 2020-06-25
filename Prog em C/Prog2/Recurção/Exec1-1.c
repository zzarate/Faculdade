#include <stdio.h>

int pot (int x, int n){
	int r=1, i;
	for (i=0; i<n; i++){
		r=r*x;
	}
	return r;
}

int potr (int x, int n){
	if (n==0)
		return 1;
	else
		return x*potr(x,n-1);
}

int main (){
	int x, n, r;

	scanf ("%d %d", &x, &n);

	r=pot (x,n);
	printf("%d\n", r );
	r=0;
	r=potr(x,n);
	printf("%d\n", r );

	return 0;
}