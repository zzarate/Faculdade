#include <stdio.h>

int qnt, bonus, at1, at2, df1, df2, lv1, lv2, i, Glp1, Glp2;

int main(){
	scanf("%d", &qnt);
	for (i=0; i<qnt; i++){
		scanf ("%d", &bonus);
		scanf("%d %d %d", &at1, &df1, &lv1);
		scanf("%d %d %d", &at2, &df2, &lv2);
		Glp1=(at1+df1)/2;
		if (lv1%2 == 0)
			Glp1+=bonus;
		Glp2=(at2+df2)/2;
		if (lv2%2 == 0)
			Glp2+=bonus;
		if (Glp1 == Glp2)
			printf("Empate\n");
		else if (Glp2 > Glp1)
			printf("Guarte\n");
			else
				printf("Dabriel\n");
	}
	return 0;

}
