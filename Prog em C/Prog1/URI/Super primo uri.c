#include <stdio.h>

int divisor;

int primo (int n){ // Teste numero primo
	int p;
	divisor=2;
	while(divisor<= n/2){
		if (n%divisor == 0)
			divisor = n;
		else 
			divisor = divisor + 1;
	}
	if (divisor == n/2+1)
		p=1; // 1= PRIMO
	else 
		p=0;// 0= NADA
	return p;
}

void sprimo (int n){ 
	int result, i=0;
	divisor=2;
	while (n>=10){
		result=n%10;
		n/=10;
		if ( n != 2 || n != 3 || n != 5 || n != 7 )
			i++;
	break;
	}
	if (i == 0)
		printf("Super\n");
	else
		printf("Primo\n");
}

int main (){
	int n,r;

	scanf ("%d", &n);
	r=primo(n);
	if (r == 1){ 			// Caso for primo
		sprimo(n);
	}
	else			// Qq outro caso
		printf("Nada\n");
	return 0;
}