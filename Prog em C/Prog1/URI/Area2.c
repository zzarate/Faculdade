#include <stdio.h>

int main(){
	double raio, result, pot;
	scanf ("%lf", &raio);
	pot= raio*raio;
	result= pot*3.14159;
	printf("A= %.4f\n", result);
	return 0;
}