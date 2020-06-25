//Ponteiro de ponteiro

#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, y, *pt1, *pt2, **ptpt1, **ptpt2;

	x=1;
	y=4;

	printf("x= %d y=%d\n", x,y );

	pt1=&x;
	pt2=&y;

	printf("*pt1=%d *pt2=%d\n", *pt1, *pt2 );

	ptpt1=&pt1;
	ptpt2=&pt2;

	printf("**ptpt1=%d **ptpt2=%d\n", **ptpt1, **ptpt2 );

	return 0;
}