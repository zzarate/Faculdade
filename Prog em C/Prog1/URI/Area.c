#include <stdio.h>
#include <math.h>

double raio;
double result;

int main(){
	 double pot;
	printf("Digite o valor do raio: \n");
	scanf ("%lf%*c", &raio);
	pot = pow (raio,2);
	result = pot*3.14159;

	printf("A= %.4f\n",result );
	return 0;
}