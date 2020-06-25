// João Víctor Zárate
// Algoritmo e programação II
// Trabalho

//Execução dos algoritmos Merge-Sort, Quick-Sort, Insertion-Sort e Heap-Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*************************************************

void preenche (int V[],int k){
	int i;
	for (i=0; i<k; i++){
		V[i]=rand()%1000000;
	}
}


//*************************************************

//Troca
void troca(int *a, int *b){
	int aux;

	aux=*a;
	*a=*b;
	*b=aux;
}

//Insertion-Sort
void insertion (int n, int V[]){
	int i,j,x;

	for (i=1; i<n; i++){
		x=V[i];
		for (j=i-1; j>=0 && V[j]< x; j--){
			V[j+1]=V[j];
		}
		V[j+1]=x;
	}
}


//Merge-Sort
void intercala (int p, int q, int r, int V[], int n){
	int i, j, k;
	int *W; // Vetor aux;

	i=p; // Comeco
	j=q; // Meio
	k=0; // Final

	V= (int*) malloc (n* sizeof (int));

	while (i<q && j<r){
		if (V[i]>= V[j]){
			W[k]= V[i];
			i++;
		}
		else {
			W[k]= V[j];
				j++;
		}
		k++;
	}
	while (i < q){
		W[k]= V[i];
		i++;
		k++;
	}
	while (j < r){
		W[k]= V[j];
		j++;
		k++;
	}
	for (i= p; i<r; i++){
		V[i]= W[i-p];
	}
}

void merge (int p,int k,int V[], int n){
	int q; //meio

	if (p < k-1){
		q= (p+k)/2;
		merge (p, q, V, n);
		merge (q, k, V, n);
		intercala (p, q, k, V, n);
	}
}


//Quick-Sort
int separa (int p, int r, int V[]){
	int i, j, x;

	x=V[p]; i=p-1; j=r+1;

	while (1){
		do{
			j--;
		} while(V[j]<x);
		do {
			i++;
		} while (V[i]>x);
		if (i<j){
			troca (&V[i], &V[j]);
		}
		else
			return j;
	}
}

void quick (int p, int r, int V[]){
	int q;

	if (p<r){
		q= separa (p, r, V);
		quick (p, q, V);
		quick (q+1, r, V);
	}
}


//Heap-Sort
int esquerdo(int i){
	return (i*2)+1;
}

int direito(int i){
	return i*2+2;
}

void desce(int k, int V[], int i){
	int e, d, min;

	e= esquerdo(i);
	d= direito(i);

	if(e<k && V[e]<V[i]){
		min= e;
	}
	else
		min= i;

	if (d<k && V[d]< V[min]){
		min=d;
	}
	if (min!= i){
		troca (&V[i], &V[min]);
		desce(k, V, min);
	}

}

void constroi(int k, int V[]){
	for (int i= k/2-1; i>=0; i--){
		desce (k, V, i);
	}
}

void heapsort (int n, int V[]){
	int i;

	constroi (n, V);
	for (i=n-1; i>0; i--){
		troca (&V[0], &V[i]);
		n--;
		desce (n, V,0);
	}
}


//Menu
void menu (){
	printf("\n");
	printf("1- Insertion Sort\n");
	printf("2- Merge Sort\n");
	printf("3- Quick Sort\n");
	printf("4- Heap Sort\n");
	printf("0- Sair\n");
	printf("\n");
	printf("Digite sua opcao desejada: \n");

}

//Opcoes
void opcao (int n, int V[]){
	double t, t1, t2;
	int opt;

	scanf ("%d", &opt);

	switch (opt){
		case 1:
		t1= clock();
		insertion(n, V);
		t2= clock();
		t= (t2-t1)/CLOCKS_PER_SEC;
		printf("Tempo de execucao: %lf\n", t );
		break;

		case 2:
		t1= clock();
		merge (0, n, V, n);
		t2= clock();
		t= (t2-t1)/CLOCKS_PER_SEC;
		printf("Tempo de execucao: %lf\n", t );
		break;

		case 3:
		t1= clock();
		quick (0, n-1, V);
		t2= clock();
		t= (t2-t1)/CLOCKS_PER_SEC;
		printf("Tempo de execucao: %lf\n", t );
		break;

		case 4:
		t1= clock();
		heapsort (n, V);
		t2= clock();
		t= (t2-t1)/CLOCKS_PER_SEC;
		printf("Tempo de execucao: %lf\n", t );
		break;

		default:
		printf("Opcao invalida!\n");

	}
}


//Main

int main (){
	int n, i;
	int *V;

	printf("Quantidade de elementos do vetor: \n");
	scanf ("%d", &n);


	
	printf("Digite os elementos: \n");
	V= (int*) malloc (n* sizeof (int));

	//*********************************

	preenche(V, n);

	//*******************************

	/*
	for (i=0; i<n; i++){
		scanf ("%d", &V[i]);
	}

	*/

	menu();
	opcao(n, V);

	return 0;

}