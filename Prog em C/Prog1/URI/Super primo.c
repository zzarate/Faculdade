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
	int result;
	divisor=2;
	while (n>=10){
		result=n%10;
		if( result != 0)
		n/=10;
	}
	if (!primo(result)){
		return 0;
		printf("Super\n");
	}
	else{
		return 1;
		printf("Primo\n");
	}
}

int main (){
	int n, r;

	while(scanf("%d", &n) !=EOF){
		r=primo(n);
		if (r == 1){
			sprimo(n);
		}
		else
			printf("Nada\n");
	}
	return 0;
}