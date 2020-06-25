#include <stdio.h>

struct pts{
	char *c;
	int *i;
	float *f;
};

int main (){
	char caractere;
	int inteiro;
	float real;
	struct pts reg;

	reg.c= &caractere;
	reg.i= &inteiro;
	reg.f= &real;

	scanf ("%c %d %f", reg.c, reg.i, reg.f);
	printf("%c\n %d\n %f\n",caractere, inteiro, real);

	return 0;
}