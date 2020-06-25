#include <stdio.h>

int v1,v2,v3, num1,num2, num3;

int main(){

  scanf ("%d %d %d", &v1, &v2, &v3);
  num1=0, num2=0, num3=0;

  //VERIFICA MENOR NUMERO (NUM1)
  if (v1<v2 && v1<v3){
    num1=v1;
  }
  else if (v2<v1 && v2<v3){
      num1=v2;
    }
    else if (v3<v1 && v3<v2){
        num1=v3;
      }

  //VERIFICA NUMERO DO MEIO (NUM2)
  if (v1<v2 && v1>v3){
    num2=v1;
  }
  else if (v2>v1 && v2<v3){
      num2=v2;
    }
    else if (v2<v1 && v2>v3){
      num2=v2 ;
      }
      else if (v3<v1 && v3>v2){
         num2=v3;
       }
       else if (v3>v1 && v3<v2){
        num2=v3;
       }
       else if (v1>v2 && v1<v3){
        num2=v1;
       }

  // VERIFICA MAIOR NUMERO (NUM3)
  if (v1>v2 && v1>v3){
    num3=v1;
  }
  else if (v2>v1 && v2>v3){
      num3=v2;
    }
    else if (v3>v1 && v3>v2){
        num3=v3;
      }
  
  //PRINTA A PORRA TODA
  printf("%d\n%d\n%d\n",num1,num2,num3 );
  printf("\n");
  printf("%d\n%d\n%d\n",v1, v2, v3 );

  return 0;
}