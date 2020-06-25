#include <stdio.h>

void imprime_alguma_coisa(int n){
	if (n != 0) {
		imprime_alguma_coisa (n / 2);
		printf("%c /n", '0' + n % 2);
	}
}


int main(){
	int n;

	scanf ("%d", &n);
	imprime_alguma_coisa(n);
	return 0;
	
}