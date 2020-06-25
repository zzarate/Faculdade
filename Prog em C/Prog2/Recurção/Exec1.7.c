#include <stdio.h>
#include <stdlib.h>

int log_2 (int n){
	if (n == 1){
		return 0;
	}

	else
		return 1 + log_2 (n/2);
}

int main (){
	int n;

	scanf ("%d", &n);

	printf("%d \n", log_2(n) );

	return 0;
}