#include <stdio.h>
#define MAX 

int fat (int n){
 if (n==0 || n==1){
 	return 1;
 }
 else 
 	return n* fat (n -1);
}

int main (){
	int n;

	scanf ("%d", &n);
	printf("%d\n", fat(n) );

	return 0;
}