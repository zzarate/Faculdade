#include <stdio.h>

int n, i, r;

int main(){
	scanf ("%d", &r);
	for(i=1; i<=r; i++){
		scanf ("%d", &n);
		if(n>0){
			if (n%2 == 0){
				printf("EVEN POSITIVE\n");
			}
			else{
				printf("ODD POSITIVE\n");
			}
		}
		else
			if(n<0){
				if(n%2 == 0){
					printf("EVEN NEGATIVE\n");
				}
				else {
					printf("ODD NEGATIVE\n");
				}
			}
		else 
			if (n == 0){
			printf("NULL\n");
		}
	}
	return 0;
}
