#include <stdio.h>
int main(void){
	int matriz[20][20];
	int n, m, i;
	int l, c;
	int x;
	scanf("%d", &n);
	scanf("%d", &m);
	x = n+3;
	for(i=0; i<n; i++){
		for(l=0; l<m; l++){
			for(c=0; c<m; c++){
				scanf("%d", &matriz[l][c]);
			}
		}
		for(l=0; l<m; l++){
			for(c=0; c<m; c++){
			matriz[l][c]= matriz[l][c]*matriz[l][c];
			}
		}
		printf("Quadrado da matriz #%d:\n", x);
		for(l=0; l<m; l++){
			for(c=0; c<m; c++){
				printf("%d ", matriz[l][c]);
			}
			printf("\n");
		}
	}
	return 0;
}