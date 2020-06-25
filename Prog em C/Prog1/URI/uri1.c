#include <stdio.h>
#include <string.h>
#define max 51
int main(void){
	int n, i;
	int cont=0, j=0;
	char frase[max]
	scanf("%d", &n);

	for(i=0; i<n; i++){
		gets (frase);
		while(frase[j]!=\0){
			if(frase[j]!=' '){
				cont++;
			}
			else
				cont=0;
			

			j++;
		}
	}
}