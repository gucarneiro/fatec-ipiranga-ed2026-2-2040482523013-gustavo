/*
 * Programa criado para calcular o estoque de produtos de uma empresa, fazendo uma simulacao inicial de acrescimo de reposicao 
 * e depois realizar a alteracao, acrescentando a reposicao no valor inicial de cada produto do estoque. Depois realiza a media da quantidade dos
 * produtos e verifica o estado de cada produto, informando se há ou não produtos em estado critico de estoque.
 *
 * Autor: Gustavo Carneiro Alves da Silva
 * Data: 24/08/26
 * Versao: 1.0.0
 */

#include <stdio.h>

#define TAMANHO_ESTOQUE 5 //define a quantidade de produtos no estoque
#define ESTOQUE_MINIMO 10 //define a quantidade de unidades minimas de um produto no estoque

int estoque[TAMANHO_ESTOQUE]; // declaracao da variavel global "estoque"

void exibirCabecalho(){ //cabecalho da empresa e titulo do programa
    printf("====================");
    printf("\n|    ConstruMais   |");
    printf("\n====================");
    printf("\n* SISTEMA DE ESTOQUE *\n\n");
}

void preencherEstoque(){ //percorre o vetor global "estoque" e guarda quantidade informada pelo usuário
    int *p = estoque;

    for (int i = 0; i < TAMANHO_ESTOQUE; i++){
        printf("Quantidade do produto %d: ", i+1);
        scanf("%d", (p+i));
        while (*(p+i) < 0){
            printf("Quantidade invalida, tente novamente.");
            printf("\nQuantidade do produto %d: ", i+1);
            scanf("%d", (p+i));
        }       
    }
}

void exibirEstoque(int momento){ //printa todos os produtos do estoque, de acordo com o momento desejado (0 = estoque atual, 1 = estoque final)
    if (momento == 0){
        printf("\n#--- Estoque Atual ---#");
    } 
    else{
        printf("\n\n#--- Estoque Final ---#");
    }

    int *p = estoque;

    for (int i = 0; i < TAMANHO_ESTOQUE; i++){
        printf("\nQuantidade do produto %d: %d unidades", i+1, *(p+i));
    }
}

float calcularMediaEstoque(){ //calcula a media geral de todos os produtos do estoque
    float soma = 0.0;
    int *p = estoque;
    
    for(int i = 0; i < TAMANHO_ESTOQUE; i++){
        soma += *(p + i); // a diferança entre (p+i) e *(p+i) é que (p+i) faz referencia ao ENDEREÇO DE MEMORIA de uma variavel (por exemplo, o vetor global "estoque")
        // e quando o "i" altera o valor, o endereço da memoria "pula" para o proximo elemento. ja o *(p+i) é o auxiliar do ponteiro, ele indica o VALOR ARMAZENADO
        // neste endereço
    }

    float media = soma / TAMANHO_ESTOQUE;

    return media;
}

void simularReposicao(int quantidadeAtual, int reposicao){ //simmula o acrescimo de reposicao do produto 1 (elemento 0 do vetor global "estoque")
    printf("\n\n#--- Simulacao de reposicao ---#");

    printf("\nSimulacao para o produto 1: %d + %d = %d (NAO aplicado ainda)", quantidadeAtual, reposicao, quantidadeAtual+reposicao);
}

void aplicarReposicaoGeral(int reposicao){ //percorre o vetor global "estoque" utilizando apontamento do endereço e acrescenta o valor da reposicao para cada produto
    int *p = estoque;

    printf("\n\n#--- Aplicacao da reposicao aos produtos ---#");
    printf("\nReposicao de %d unidades para todos os produtos do estoque.", reposicao);

    for (int i = 0; i < TAMANHO_ESTOQUE; i++){
    *(p+i) += reposicao;
    }
}

void identificarEstoqueCritico(int minimo){ //percorre o vetor global "estoque" e verifica se a quantidade do produto é menor que o valor minimo
    int *p = estoque;
    int verificaEstoque = 0;

    printf("\n\n#--- Analise de Estoque | Minimo = 10 Unds por produto ---#");

    for (int i = 0; i < TAMANHO_ESTOQUE; i++){
        if (*(p+i) < minimo){
            printf("\nO produto %d esta em nivel critico: %d unidades (%d unidades abaixo do minimo).", (i+1), *(p+i), (minimo - *(p+i)));
        } 
        else{ //caso o produto seja >= ao minimo, acrescenta 1 na contagem "verificaEstoque", no final verifica se a "verificaEstoque" = TAMANHO_ESTOQUE
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
    int copiaValorProduto = estoque[0], reposicao; //faz uma copia do valor armazenado no elemento 0 do vetor global "estoque"
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
