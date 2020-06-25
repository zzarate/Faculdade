/* Calculadora Infinita*/
/* João Víctor Zárate */
/* T2 - PROG 2 */

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *ant;
    struct cel *prox;
} celula;

void imprime (celula *lista){
    celula *p;

    for (p = lista; p != NULL; p = p->prox){
        printf("%d", p->chave);
    }
    printf("\n");
}

void cria_lista (char c, celula *lista){
    celula *p, *q, *nova;

    p= lista;
    q= lista->prox;

    nova= (celula *) malloc(sizeof(celula));
    nova->chave = c;

    while (q != NULL){
        p= q;
        q= q->prox;
    }
    nova->prox= q;
    nova->ant= p;

    if (p != NULL){
        p->prox = nova;
    }
    if (q != NULL){
        q->ant= nova;
    }
}

void free_num  (celula *numero1, celula *numero2){
    celula *p;

    while (numero1->prox != NULL){
        p= numero1->prox;
        numero1->prox= p->prox;
        free(p);
    }

    while (numero2->prox != NULL){
        p= numero2->prox;
        numero2->prox= p->prox;
        free(p);
    }
}

void soma_num (celula *numero1, celula *numero2, celula *soma){
    celula *p, *q, *nova, *carry;

    carry= (celula *) malloc(sizeof(celula));
    carry->chave= 0;

    p= numero1->prox;
    while(p->prox != NULL){
        p= p->prox;
    }

    q= numero2->prox;
    while(q->prox != NULL){
        q= q->prox;
    }

    while (p != numero1 && q != numero2){
        nova= (celula *) malloc(sizeof(celula));
        if (p->chave + q->chave + carry->chave > 9){
            nova->chave= p->chave + q->chave + carry->chave - 10;
            carry->chave= 1;
        }
        else{
            nova->chave= p->chave + q->chave + carry->chave;
            carry->chave= 0;
        }

        nova->prox= soma->prox;
        nova->ant= soma;
        soma->prox= nova;

        if (nova->prox != NULL){
            nova->prox->ant= nova;
        }

        p = p->ant;
        q = q->ant;
    }

    while (p != numero1){
        nova= (celula *) malloc(sizeof(celula));

        if (p->chave + carry->chave > 9){
            nova->chave= p->chave + carry->chave - 10;
            carry->chave=1;
        }
        else{
            nova->chave= p->chave + carry->chave;
            carry->chave= 0;
        }

        nova->prox= soma->prox;
        nova->ant= soma;
        soma->prox= nova;

        if (nova->prox != NULL){
            nova->prox->ant= nova;
        }
        p = p->ant;
    }

    while (q != numero2){
        nova = (celula *) malloc(sizeof(celula));

        if (q->chave + carry->chave > 9){
            nova->chave = q->chave + carry->chave - 10;
            carry->chave=1;
        }
        else{
            nova->chave= q->chave + carry->chave;
            carry->chave= 0;
        }

        nova->prox= soma->prox;
        nova->ant= soma;
        soma->prox= nova;

        if (nova->prox != NULL){
            nova->prox->ant= nova;
        }
        q=q->ant;
    }

    if (carry->chave > 0){
        nova = (celula *) malloc(sizeof(celula));
        nova->chave= carry->chave;
        nova->prox= soma->prox;
        nova->ant= soma;
        soma->prox= nova;

        if (nova->prox != NULL){
            nova->prox->ant= nova;
        }
        free(carry);
    }
    else
        free(carry);
}

void subtrai_num  (celula *numero1, celula *numero2, celula *sub){
    celula *p, *q, *nova, *carry, *f;

    carry= (celula *) malloc(sizeof(celula));
    carry->chave=0;

    p= numero1->prox;

    while(p->prox != NULL){
        p= p->prox;
    }

    q= numero2->prox;
    while(q->prox != NULL){
        q=q->prox;
    }

    while (p != numero1 && q != numero2){
        nova= (celula *) malloc(sizeof(celula));

        if (p->chave - q->chave < 0){
            nova->chave= p->chave - q->chave + carry->chave + 10;
            carry->chave= -1;
        }
        else{
            nova->chave= p->chave - q->chave + carry->chave;
            carry->chave=0;
        }

        nova->prox= sub->prox;
        nova->ant= sub;
        sub->prox= nova;

        if (nova->prox != NULL){
            nova->prox->ant= nova;
        }

        p= p->ant;
        q= q->ant;
    }

    while (p != numero1){
        nova= (celula *) malloc(sizeof(celula));

        if (p->chave + carry->chave < 0){
            nova->chave= p->chave + carry->chave + 10;
            carry->chave= -1;
        }
        else{
            nova->chave= p->chave + carry->chave;
            carry->chave=0;
        }

        nova->prox= sub->prox;
        nova->ant= sub;
        sub->prox= nova;

        if (nova->prox != NULL){
            nova->prox->ant= nova;
        }
        p= p->ant;
    }

    p= sub->prox;
    while (p->chave == 0){
        f= p;
        p->ant->prox= p->prox;
        p->prox->ant= p->ant;
        p= p->prox;
        free(f);
    }

    free(carry);
}

void mult_num  (celula *numero1, celula *numero2, celula *mult){
    int cont=1;
    celula *p, *q, *r, *s, *nova, *carry;

    carry= (celula *) malloc(sizeof(celula));
    carry->chave=0;

    p= numero1->prox;
    while (p->prox != NULL){
        p= p->prox;
    }

    q= numero2->prox;
    while (q->prox != NULL){
        q= q->prox;
    }

    while (q != numero2){
        if (cont){
            while (p != numero1){
                if (p->chave * q->chave + carry->chave > 9){
                    nova= (celula *) malloc(sizeof(celula));
                    nova->chave= (p->chave * q->chave + carry->chave) % 10;
                    nova->prox= mult->prox;
                    mult->prox= nova;
                    nova->ant= mult;

                    if (nova->prox != NULL){
                        nova->prox->ant= nova;
                    }

                    carry->chave= (p->chave * q->chave + carry->chave) / 10;
                    p= p->ant;
                }

                else{
                    nova= (celula *) malloc(sizeof(celula));
                    nova->chave= p->chave * q->chave + carry->chave;
                    nova->prox= mult->prox;
                    mult->prox= nova;
                    nova->ant= mult;

                    if (nova->prox != NULL){
                        nova->prox->ant= nova;
                    }

                    carry->chave=0;
                    p=p->ant;
                }
            }

            if (carry->chave > 0){
                nova= (celula *) malloc(sizeof(celula));
                nova->chave= carry->chave;
                nova->prox= mult->prox;
                nova->ant= mult;
                mult->prox= nova;

                if (nova->prox != NULL){
                    nova->prox->ant= nova;
                }
            }
            cont=0;

            r= mult->prox;
            while (r->prox != NULL){
                r= r->prox;
            }
            s= r;
        }

        else{
            while (p != numero1){
                if (p->chave * q->chave + carry->chave > 9){
                    nova= (celula *) malloc(sizeof(celula));
                    nova->chave= (p->chave * q->chave + carry->chave) % 10;
                    if (r != mult){
                        r->chave= r->chave + nova->chave;
                    }
                    else{
                        nova->prox= mult->prox;
                        nova->ant= mult;
                        mult->prox= nova;
                        if (nova->prox != NULL){
                            nova->prox->ant = nova;
                        }
                    }

                    carry->chave= (p->chave * q->chave + carry->chave) / 10;
                    p=p->ant;
                    r=r->ant;
                }

                else{
                    nova= (celula *) malloc(sizeof(celula));
                    nova->chave= p->chave * q->chave + carry->chave;
                    if (r != mult){
                        r->chave= r->chave + nova->chave;
                    }
                    else{
                        nova->prox= mult->prox;
                        nova->ant= mult;
                        mult->prox= nova;
                        if (nova->prox != NULL){
                            nova->prox->ant= nova;
                        }
                    }
                    carry->chave= 0;
                    p= p->ant;
                    r= r->ant;
                }
            }

            if (carry->chave > 0){
                nova= (celula *) malloc(sizeof(celula));
                nova->chave= carry->chave;
                nova->prox= mult->prox;
                nova->ant= mult;
                mult->prox= nova;
                if (nova->prox != NULL){
                    nova->prox->ant = nova;
                }
            }
        }
        p= numero1->prox;
        while (p->prox != NULL){
            p= p->prox;
        }
        carry->chave = 0;
        q= q->ant;
        s= s->ant;
        r= s;
    }
    free(carry);
}

void divide_num  (celula *numero1, celula *numero2, celula *div){
    int aux=1, n1=1, n2=1;
    celula *nova, *carry;
    celula *p, *q, *r, *s, *t, *v;

    nova= (celula *) malloc(sizeof(celula));
    nova->chave= 1;
    nova->prox= div->prox;
    div->prox= nova;
    nova->ant= div;

    p= (celula *) malloc(sizeof(celula));
    p->ant= NULL;
    p->prox= NULL;

    while (aux){
        mult_num (numero2, div, p);
        q= numero1->prox;
        while (q->prox != NULL){
            q = q->prox;
            n1++;
        }
        r= p->prox;
        while (r->prox != NULL){
            r= r->prox;
            n2++;
        }
        v= div->prox;
        while (v->prox != NULL){
            v= v->prox;
        }

        q= numero1->prox;
        r= p->prox;
        while (p->prox != NULL && aux){
            if (n2 > n1){
                t= div->prox;
                while (t->prox != NULL){
                    t= t->prox;
                }

                carry= (celula *) malloc(sizeof(celula));
                carry->chave= -1;

                while (t != NULL){
                    if (t->chave + carry->chave < 0){
                        t->chave= t->chave + carry->chave + 10;
                        t= t->ant;
                    }
                    else{
                        t->chave= t->chave + carry->chave;
                        carry->chave= 0;
                        t= t->ant;
                    }
                }
                aux=0;
            }
            else{
                if (n1 > n2){
                    while (p->prox != NULL){
                        s= p->prox;
                        p->prox= s->prox;
                        free(s);
                    }
                    if (v->chave + 1 > 9){
                        v->chave= 0;

                        nova= (celula *) malloc(sizeof(celula));
                        nova->chave= 1;

                        if (v->ant != div){
                            while(v->ant != div){
                                v= v->ant;
                                v->chave= v->chave + nova->chave;
                                if (v->chave > 9){
                                    v->chave= 0;
                                    nova->chave= 1;
                                }
                                else{
                                    nova->chave=0;
                                }
                            }
                        }
                        else{
                            nova->prox= div->prox;
                            nova->ant= div;
                            div->prox= nova;
                            if (nova->prox != NULL){
                                nova->prox->ant= nova;
                            }
                        }
                    }
                    else{
                        v->chave= v->chave + 1;
                    }
                }
                else{
                    if (r->chave > q->chave){
                        t= div->prox;
                        while (t->prox != NULL){
                            t= t->prox;
                        }

                        carry= (celula *) malloc(sizeof(celula));
                        carry->chave= -1;

                        while (t != NULL){
                            if (t->chave + carry->chave < 0){
                                t->chave= t->chave + carry->chave + 10;
                                t= t->ant;
                            }
                            else{
                                t->chave= t->chave + carry->chave;
                                carry->chave= 0;
                                t= t->ant;
                            }
                        }
                        aux=0;
                    }

                    else{
                        if (q->chave > r->chave){
                            while (p->prox != NULL){
                                s= p->prox;
                                p->prox= s->prox;
                                free(s);
                            }
                            if (v->chave + 1 > 9){
                                v->chave = 0;

                                nova= (celula *) malloc(sizeof(celula));
                                nova->chave = 1;

                                if (v->ant != div){
                                    while(v->ant != div){
                                        v= v->ant;
                                        v->chave = v->chave + nova->chave;
                                        if (v->chave > 9){
                                            v->chave = 0;
                                            nova->chave = 1;
                                        }
                                        else{
                                            nova->chave = 0;
                                        }
                                    }
                                }
                                else{
                                    nova->prox= div->prox;
                                    nova->ant= div;
                                    div->prox= nova;
                                    if (nova->prox != NULL){
                                        nova->prox->ant= nova;
                                    }
                                }
                            }
                            else{
                                v->chave= v->chave + 1;
                            }
                        }
                        else{
                            q= q->prox;
                            r= r->prox;
                            if (q == NULL && r == NULL){
                                aux=0;
                            }
                        }
                    }
                }
            }
        }
        n1=1;
        n2=1;
    }
}

int main (){
    celula *p, *q, *num1, *num2, *soma, *sub, *mult, *div;
    int n1=0, n2=0, cont=1;
    char c, opt;

    num1= (celula *) malloc(sizeof(celula));
    num1->ant= NULL;
    num1->prox= NULL;

    num2= (celula *) malloc(sizeof(celula));
    num2->ant= NULL;
    num2->prox= NULL;

    scanf("%c", &c);
    while(c >= '0' && c <= '9'){
        cria_lista(c - '0', num1);
        n1++;
        scanf("%c", &c);
    }

    scanf(" %c", &opt);

    scanf(" %c", &c);
    while(c >= '0' && c <= '9'){
        cria_lista(c - '0', num2);
        n2++;
        scanf("%c", &c);
    }

    while (num1->prox->chave != 0 || opt != '*' || num2->prox->chave != 0){

        switch (opt){

            case '+':
                soma= (celula *) malloc(sizeof(celula));
                soma->ant= NULL;
                soma->prox= NULL;

                soma_num(num1, num2, soma);
                imprime(soma->prox);
                while (soma->prox != NULL){
                    p=soma->prox;
                    soma->prox= p->prox;
                    free(p);
                }
                free_num (num1, num2);
                free(soma);
                break;

            case '-':
                sub= (celula *) malloc(sizeof(celula));
                sub->ant= NULL;
                sub->prox= NULL;
                if (n1 >= n2){
                    if (n1 > n2){
                        subtrai_num (num1, num2, sub);
                        imprime(sub->prox);
                    }
                    else{
                        p= num1->prox;
                        q= num2->prox;
                        while (p != NULL && q != NULL && cont){
                            if (p->chave > q->chave){
                                subtrai_num (num1, num2, sub);
                                imprime(sub->prox);
                                cont = 0;
                            }
                            else{
                                if (q->chave > p->chave){
                                    subtrai_num (num2, num1, sub);
                                    printf("-");
                                    imprime(sub->prox);
                                    cont=0;
                                }
                            }
                            p= p->prox;
                            q= q->prox;
                        }
                        if (cont == 1){
                            printf("0\n");
                        }
                    }
                }
                else{
                    subtrai_num (num2, num1, sub);
                    printf("-");
                    imprime(sub->prox);
                }
                while (sub->prox != NULL){
                    p= sub->prox;
                    sub->prox= p->prox;
                    free(p);
                }
                free_num (num1, num2);
                free(sub);
                break;

            case '*':
                mult= (celula *) malloc(sizeof(celula));
                mult->ant= NULL;
                mult->prox= NULL;

                mult_num (num1, num2, mult);
                imprime(mult->prox);
                while (mult->prox != NULL){
                    p= mult->prox;
                    mult->prox= p->prox;
                    free(p);
                }
                free_num (num1, num2);
                free(mult);
                break;

            case '/':
                div= (celula *) malloc(sizeof(celula));
                div->ant = NULL;
                div->prox = NULL;

                divide_num (num1, num2, div);
                imprime(div->prox);
                while (div->prox != NULL){
                    p= div->prox;
                    div->prox= p->prox;
                    free(p);
                }
                free_num (num1, num2);
                free(div);
                break;
        }

        n1=0;
        n2=0;

        scanf("%c", &c);
        while(c >= '0' && c <= '9'){
            cria_lista(c - '0', num1);
            n1++;
            scanf("%c", &c);
        }

        scanf(" %c", &opt);

        scanf(" %c", &c);
        while(c >= '0' && c <= '9'){
            cria_lista(c - '0', num2);
            n2++;
            scanf("%c", &c);
        }
    }

    free(num1);
    free(num2);

    return 0;
}