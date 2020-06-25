#include <stdio.h>
#include <math.h>

double a,b,c;
double a_triangulo,r_circulo,a_trapezio,a_quadrado,a_retangulo;

int main(){
	scanf("%lf %lf %lf",&a, &b, &c);
	a_triangulo= (a*c) /2;
	r_circulo= 3.14159* pow(c,2);
	a_trapezio= ((a+b)*c) /2;
	a_quadrado= b*b;
	a_retangulo= a*b;

	printf("TRIANGULO: %.3lf\n",a_triangulo);
	printf("CIRCULO: %.3lf\n",r_circulo);
	printf("TRAPEZIO: %.3lf\n",a_trapezio);
	printf("QUADRADO: %.3lf\n",a_quadrado);
	printf("RETANGULO: %.3lf\n",a_retangulo);
	return 0;

}
