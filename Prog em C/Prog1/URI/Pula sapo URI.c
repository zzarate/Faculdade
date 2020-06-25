#include <stdio.h>

int main (){
	int ps, nc, i;

	scanf ("%d %d", &ps, &nc);
	int vetc [nc];
	for (i=0; i<nc;i++){		//	PREENCHE A 
		scanf ("%d", &vetc[i]);	//		MATRIZ
	}
	for (i=1;i<nc;i++){						
		if (vetc[i]>= vetc[i-1]){			//	testa se é maior que o anteior.
			if((vetc[i]-vetc[i-1])>ps){ 	//	verifica se a altura do cano é 
				printf("GAME OVER\n");		//maior que a do pulo.
				return 0;
			}
		}
		else if ((vetc[i-1]-vetc[i])>ps){	// testa se é maior que a altura
			printf("GAME OVER\n");			// do pulo.
			return 0;
		}
		i++;
	}
	printf("YOU WIN\n");
	return 0;
}