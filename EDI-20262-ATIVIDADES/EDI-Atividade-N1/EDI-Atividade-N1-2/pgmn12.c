#include <stdio.h>

#define TAMANHO_ESTOQUE 5
#define ESTOQUE_MINIMO 10

int estoque[TAMANHO_ESTOQUE];

void exibirCabecalho(){
    printf("====================");
    printf("\n|    ConstruMais   |");
    printf("\n====================");
    printf("\nSISTEMA DE ARMAZENAMENTO\n\n");
}

void preencherEstoque(){
    int *p = estoque;

    for (int i = 0; i < TAMANHO_ESTOQUE; i++)    {
        printf("Quantidade do produto %d: ", i+1);
        scanf("%d", *(p+i));
    }
}

int main(){
    exibirCabecalho();

    return 0;
}
