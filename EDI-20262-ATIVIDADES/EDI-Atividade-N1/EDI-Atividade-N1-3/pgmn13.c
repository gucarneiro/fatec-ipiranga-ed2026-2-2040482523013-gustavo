#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALOR_PREMIUM 100.0 //define o valor do servico PREMIUM

typedef struct { //define como vai ser a estrutura do tipo Veiculo
    char placa[8];
    float valor;
} Veiculo;

void exibirCabecalho(){ //imprime o cabecalho da empresa
    printf("=================================");
    printf("\nLAVA-RAPIDO BRILHO TOTAL- FILA DE ATENDIMENTO");
    printf("\n=================================");
}

void preencherFrota(Veiculo *frota, int quantidade){ //preenche todas as estruturas do tipo Veiculo, com base na quantidade, fazendo o apontamento direto no endereco de memoria do primeiro elemento
    for (int i = 0; i < quantidade; i++){
        printf("Placa do veiculo %d: ", (i+1));
        scanf("%s", (frota+i)->placa);

        printf("Valor do servico (R$): ");
        scanf("%f", &(frota+i)->valor);
    }
}

void exibirFrotaRecursivo(Veiculo *frota, int indice, int quantidade){// printa todas as estruturas do tipo Veiculo de forma recursiva
    if(indice == quantidade){
        return;
    }
    
    printf("\n%d) Placa: %s | Valor: R$ %.2f", (indice+1), frota[indice].placa, frota[indice].valor);
    exibirFrotaRecursivo(frota, indice + 1, quantidade);
}

float calcularValorTotalRecursivo(Veiculo *frota, int indice, int quantidade){// calcula o valor total de todas as estruturas do tipo Veiculo
    if (indice == quantidade){//esse é o caso base, onde verifica se o indice é igual a quantidade de veiculos
        return 0.0;
    }
    return frota[indice].valor + calcularValorTotalRecursivo(frota, indice + 1, quantidade); //esse é o passo recursivo, onde chamamos a propria funcao para somar o valor atual com o proximo valor com base no indice
}

int buscaVeiculoRecursivo(Veiculo *frota, int indice, int quantidade, char placa[8]){//procura e compara a placa com a placa procurada 
    if(indice > quantidade){
        return -1;
    }
    
    if (strcmp(frota[indice].placa, placa) == 0){
        return indice;
    }
    buscaVeiculoRecursivo(frota, indice + 1, quantidade, placa);
}

int contarPremiumRecursivo(Veiculo *frota, int indice, int quantidade){ //faz a contagem de Veiculos com valor de servicos >= 100
    if (indice == quantidade){
        return 0;
    }
    if (frota[indice].valor >= VALOR_PREMIUM){
        return 1 + contarPremiumRecursivo(frota, indice + 1, quantidade);
    }
    return contarPremiumRecursivo(frota, indice + 1, quantidade);
}


int main()
{
    exibirCabecalho();
    
    int quantidade;
    printf("\nQuantos veiculos serao atendidos hoje? ");
    scanf("%d", &quantidade);

    Veiculo *frota = (Veiculo *) malloc(quantidade * sizeof(Veiculo));
    
    if(frota == NULL){
        printf("");
        return 1;
    }

    preencherFrota(frota, quantidade);
    
    printf("\n\n--- Veiculos atendidos hoje ---");
    int indice = 0;
    exibirFrotaRecursivo(frota, indice, quantidade);
    
    printf("\n\n--- Busca recursiva por placa ---");
    printf("\nPlaca a ser pesquisada: ");
    char placaProcurada[8];
    scanf("%s", placaProcurada);
    
    int indiceEncontrado = buscaVeiculoRecursivo(frota, indice, quantidade, placaProcurada);
    if (indiceEncontrado < 0){
        printf("\nVeiculo nao encontrado na frota.");
    }
    else{
        printf("\nVeiculo encontrado na posicao %d! Placa: %s | Valor: R$ %.2f", (indiceEncontrado + 1), frota[indiceEncontrado].placa, frota[indiceEncontrado].valor);
    }
    
    int totalPremium = contarPremiumRecursivo(frota, indice, quantidade);
    
    float valorTotal = calcularValorTotalRecursivo(frota, indice, quantidade);
    
    printf("\n\n--- Resumo do dia ---");
    printf("\nTotal de veiculos atendidos: %d", quantidade);
    printf("\nServicos premium (>= R$ 100.00): %d", totalPremium);
    printf("\nValor total arrecadado: R$ %.2f", valorTotal);
    
    free (frota);
    frota = NULL;
    printf("\n\nMemoria da frota liberada com sucesso. Sistema encerrado");
    
    return 0;
}