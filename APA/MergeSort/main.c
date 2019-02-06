#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *vet, int tamanho);
void Merge(int *vet, int *E, int *D, int tamanho);

void main()
{
	int vet[7];
	int i;

	printf("Insira o vetor de sete posicoes:");

    for(i=0; i<7; i++){
        scanf("%d", &vet[i]);
    }

	MergeSort(vet,7); //chama MergeSort

	printf("Vetor ordenado: ");

	for(i=0; i<7; i++){
        printf("%d ", vet[i]);
	}
}
void MergeSort(int *vet, int tamanho){

	int meio=0; //acha o meio do array
    int *D, *E;
    int i=0;
    meio = tamanho/2; //divide o array em 2 novos arrays

    if(tamanho<2)//divisão termina quando se acha os elementos individuais
		return;
	else{//codigo para criar os filhos da esquerda e direita do array
		E = (int*)malloc(sizeof(int)*meio);
		D=(int*)malloc(sizeof(int)*(tamanho-meio));
	}
//codigo para copiar o conteudo nos filhos
for(i=0; i<meio; i++){
	E[i]=vet[i];
}for (i=meio; i<tamanho; i++){
	D[i-meio]=vet[i];
}
//Chamadas recursivas
MergeSort(E, meio);
MergeSort(D, tamanho-meio);
Merge(vet, E, D, tamanho); //chama Merge para iniciar os filhos de maneira classificada
}

void Merge(int *vet, int *E, int *D, int tamanho){
	int i=0, j=0, k=0; //i,j,k são indicies pro pai, filho da esquerda e da direita
	int mE, mD; // ão o tamanho do filho da esquerda e da direita

	mE=tamanho/2;
	mD=tamanho-mE;

while(i<mE && j<mD){//Codigo para comparar filhos com o pai
	if(E[i] < D[j]){
		vet[k]=E[i];
		i++;
	}else{
		vet[k]=D[j];
		j++;
	}
	k++;
}
while(i<mE){//codigo para preencher o pai com um filho caso o outro se esgote na comparação
    vet[k] = E[i];
    i++;
    k++;
}while(j<mD){
    vet[k]=D[j];
    j++;
    k++;
}
}




