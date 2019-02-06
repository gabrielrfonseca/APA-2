#include <stdio.h>
#include <stdlib.h>

int main(){

    int vetor[10];
    int i;

	printf("Insira o vetor de dez posicoes: ");

    for(i=0; i<10; i++){
        scanf("%d", &vetor[i]);
    }

    quickSort(vetor, 0, 9); //Chamada da fun��o

	printf("Vetor ordenado: ");

    for(int i=0;i<10;i++){
        printf("%d ",vetor[i]);
    }

    printf("\n");

    return 0;
}

int dividir(int vetor[], int esq, int dir){ //
    int aux; //troca de posicoes atraves da variavel auxiliar
    int cont = esq;

    for(int i=esq+1; i<=dir; i++){//o la�o ir� avan�ar com i at� achar um elemento maior que pivo para colocoar no lado direito
        if( vetor[i] < vetor[esq] ){
            cont++;
            aux=vetor[i];
            vetor[i]=vetor[cont];
            vetor[cont]=aux;
        }
    }

    aux=vetor[esq];//troca sendo realizada Pivo sendo alocado pra posi��o certa
    vetor[esq]=vetor[cont];
    vetor[cont]=aux;

    return cont;
}

void quickSort(int vetor[],int esq, int dir){
    int pos;
    if(esq < dir){
        pos = dividir(vetor,esq,dir);//acha a posi��o do pivo atraves da fun��o dividir, joga os menores pra esquerda e os maiores pra direita
        quickSort(vetor,esq,pos-1);//ordena recursivamente da esquerda at� pivo - 1
        quickSort(vetor,pos+1,dir);//ordena recursivamente da direita at� pivo + 1
    }
}
