#include <stdio.h>

#define TAMANHO_ESTOQUE 5
#define ESTOQUE_MINIMO 10

int estoque[TAMANHO_ESTOQUE];

void exibirCabecalho(){
    printf("====================");
    printf("\n|    ConstruMais   |");
    printf("\n====================");
    printf("\n* SISTEMA DE ESTOQUE *\n\n");
}

void preencherEstoque(){
    int *p = estoque;

    for (int i = 0; i < TAMANHO_ESTOQUE; i++){
        printf("Quantidade do produto %d: ", i+1);
        scanf("%d", (p+i));
    }
}

void exibirEstoque(int momento){
    if (momento == 0){
        printf("\n\n#--- Estoque Atual ---#");
    } 
    else{
        printf("\n\n#--- Estoque Final ---#");
    }

    int *p = estoque;

    for (int i = 0; i < TAMANHO_ESTOQUE; i++){
        printf("\nQuantidade do produto %d: %d unidades", i+1, *(p+i));
    }
}

float calcularMediaEstoque(){
    float soma;
    int *p = estoque;
    
    for(int i = 0; i < TAMANHO_ESTOQUE; i++){
        soma += *(p + i);
    }

    float media = soma / TAMANHO_ESTOQUE;

    return media;
}

void simularReposicao(int quantidadeAtual, int reposicao){
    printf("\n\n#--- Simulacao de reposicao ---#");

    printf("\nSimulacao para o produto 1: %d + %d = %d (NAO aplicado ainda)", quantidadeAtual, reposicao, quantidadeAtual+reposicao);
}

void aplicarReposicaoGeral(int reposicao){
    int *p = estoque;

    printf("\n\n#--- Aplicacao da reposicao aos produtos ---#");
    printf("\nReposicao de %d unidades para todos os produtos do estoque.", reposicao);

    for (int i = 0; i < TAMANHO_ESTOQUE; i++){
    *(p+i) += reposicao;
    }
}

void identificarEstoqueCritico(int minimo){
    int *p = estoque;
    int verificaEstoque = 0;

    printf("\n\n#--- Analise de Estoque | Minimo = 10 Unds por produto ---#");

    for (int i = 0; i < TAMANHO_ESTOQUE; i++){
        if (*(p+i) < minimo){
            printf("\nO produto %d esta em nivel critico: %d unidades (%d unidades abaixo do minimo)", (i+1), *(p+i), (minimo - *(p+i)));
        } 
        else{
            verificaEstoque++;
        }
    }

    if (verificaEstoque == TAMANHO_ESTOQUE){
        printf("\nNenhum produto em estado critico. Estoque está regular.");
    }
}

int main(){
    exibirCabecalho();

    preencherEstoque();
    int copiaValorProduto = estoque[0], reposicao;
    printf("\nQuantidade de reposicao a aplicar: ");
    scanf("%d", &reposicao);
    
    exibirEstoque(0);

    simularReposicao(copiaValorProduto, reposicao);
    printf("\nQuantidade do produto 1 apos simulacao (sem alteracoes): %d", estoque[0]);

    aplicarReposicaoGeral(reposicao);

    exibirEstoque(1);

    printf("\n\n#--- Media geral do estoque ---#");
    printf("\nMedia final: %.2f unidades", calcularMediaEstoque());

    identificarEstoqueCritico(ESTOQUE_MINIMO);

    return 0;
}
