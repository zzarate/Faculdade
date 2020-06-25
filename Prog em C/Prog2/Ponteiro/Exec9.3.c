#include <stdio.h>

int main(void){
	int a, b, *pt1, *pt2;

	pt1 = &a;
	pt2 = &b;
	a = 1;
	(*pt1)++;
	b = a + *pt1;
	*pt2 = *pt1 * *pt2;
	printf("a=%d, b=%d, *pt1=%d, *pt2=%d\n", a, b, *pt1, *pt2);

	return 0;
}
