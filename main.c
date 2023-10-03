#include <stdio.h>
#define TAM 10

typedef struct pilha {
    int dados[TAM];
    int n;
}Pilha;

void inicializa(Pilha *p, int valor1, int valor2){
    p->n = valor1;
    for(int i = 0; i < TAM; i++){
        p->dados[i] = valor2;
    }
}

int cheia(Pilha *p){
    return(p->n >= TAM);
}

int vazia(Pilha *p){
    return (p->n <= 0);
}

int topo(Pilha *p){
    return p->dados[p->n-1];
}

int empilha(Pilha *p, int valor){
    if(cheia(p))return 0;
    else{
        p->dados[p->n]=valor;
        p->n++;
    }
    return 1;
}

int desempilha(Pilha *p){
    if(vazia(p)) return 0;
    else{
        p->n--;
        return p->dados[p->n];
    }
}

int main(){
    Pilha P;
    int op,num, res;

    inicializa(&P,0,-999);

    scanf("%d",&op);
    do{
        switch(op){
            case 1:
                scanf("%d",&num);
                if(empilha(&P,num) == 1) printf("empilhado\n");
                else printf("pilha cheia\n");
                break;
            case 2:
                res = desempilha(&P);
                if(res == 0) printf("pilha vazia\n");
                else printf("%d\n",res);
                break;
            case 3:
                printf("%d\n",topo(&P));
                break;
            case -1:
                break;
        }
        if(op!=-1) scanf("%d",&op);
    }while(op!=-1);

    return 0;
}
