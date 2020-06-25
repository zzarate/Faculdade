#include <stdio.h>

int fib (int i){
	if (i ==1 || i == 2)
		return 1;
	else 
		return fib (i-1) + fib (i-2);
}


int main (){
	int n;

	scanf ("%d", &n);
	printf("%d\n", fib (n) );
	return 0;
}