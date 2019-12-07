#include<stdlib.h>
#include<stdio.h>
#define TAMMAX 6

typedef struct
{
    int Elem[TAMMAX];
    int Fim;
    int Inicio;
} Fila;

void InicializaFila(Fila *q){
    q->Fim=-1;
    q->Inicio=-1;
}

int FilaVazia(Fila *q){
    if (q->Inicio == q->Fim){
        return 1;
    }
        else{
            return 0;
        }
}

int FilaCheia(Fila *q){
    if ((q->Inicio==-1)&&(q->Fim == TAMMAX-1))
    {
        return 1;
    }
        else{
            return 0;
        }
}

void DeslocaFila(Fila *q){
    int desloc;
    desloc=q->Inicio + 1;
    for (int i=q->Inicio+1; i<=q->Fim; i++){
        q->Elem[i-desloc]=q->Elem[i];
    }
    q->Inicio=-1;
    q->Fim=q->Fim - desloc;
}

void InsereFila(Fila *q, int x){
    printf("\nInsere na fila.\n");
    if (FilaCheia(q) == 0){
        printf("\nInserindo na fila...\n");
        if (q->Fim == TAMMAX-1){
            DeslocaFila(q);
        }
        (q->Fim)++;
        q->Elem[q->Fim]=x;
        printf("\nInserido na fila, %d\n", q->Elem[q->Fim]);
    }
        else{
            printf("\nFila Cheia.\n");
        }
}

void RemoveFila(Fila *q, int *x){
    if (!FilaVazia(q)){
        (q->Inicio)++;
        *x=q->Elem[q->Inicio];}
        else{
            InicializaFila(q);
            printf("\nFila vazia.\n");
        }
}


int ElemInicio(Fila *q){
    if (!FilaVazia(q)){
        return q->Elem[(q->Inicio)+1];
    }
}

void MostraFila(Fila *q){
    for(int i=q->Inicio;i<q->Fim;i++){
        printf("\nElemento %d é %d",i+1,q->Elem[i+1]);
    }
}

void MostraMatriz(int ma[9][16])
{
    int i,j;
    for (i=0; i<9; i++){
        printf("\n");
        for (j=0; j<16; j++){
            printf("\t%i", ma[i][j]);
        } 
    }

}

void NovoJogo(int ma[][16])
{
    int i,j; 
    for (i=0; i<9; i++){
      for (j=0; j<16; j++){
        ma[i][j] = rand() % 4;

        while (ma[i][j]==0){
            ma[i][j] = rand() % 4;
        }
      } 
    }

    MostraMatriz(ma);
    //char = '\u25A0'
}

int main(){
    Fila fi;
    int rem, i, j;
    int matriz[9][16];
    int perdeu=0;
    int l=9, c=16;

    NovoJogo(matriz);
    InicializaFila(&fi);

    while (!perdeu){
        printf("\n Escolha uma linha \n\t");;
        scanf("%d", &i);
        printf("\n Escolha uma coluna \n\t");;
        scanf("%d", &j);


    }
}

/*void MostraMatriz(int *ma)
{
    int i,j;
    for (i=0; i<9; i++){
        printf("\n");
      for (j=0; j<16; j++){
        printf("%i", *ma[i][j]);
      } 
    }

}
void NovoJogo(int *ma[9][16])
{
    int i,j; 
    for (i=0; i<9; i++){
      for (j=0; j<16; j++){
        *ma[i][j] = rand() % 4;

        while (*ma[i][j]==0){
            *ma[i][j] = rand() % 4;
        }
      } 
    }

    MostraMatriz(ma);
    //char = '\u25A0'


int main(){
    Fila fi;
    int rem, i, j;
    int matriz[9][16];
    int perdeu=0;

    NovoJogo(matriz[9][16]);
    InicializaFila(&fi);

    while (!perdeu){
        printf("\n Escolha uma linha \n");;
        scanf("%d", &i);
        printf("\n Escolha uma coluna \n");;
        scanf("%d", &j);


    }
}*/