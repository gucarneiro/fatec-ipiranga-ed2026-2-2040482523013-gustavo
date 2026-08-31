#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char placa[8];
    float valor;
} Veiculo;

void exibirCabecalho(){
    printf("=================================");
    printf("\nLAVA-RAPIDO BRILHO TOTAL- FILA DE ATENDIMENTO");
    printf("\n=================================");
}

void preencherFrota(Veiculo *frota, int quantidade){
    for (int i = 0; i < quantidade; i++){
        printf("Placa do veiculo %d: ", (i+1));
        scanf("%s", (frota+i)->placa);

        printf("Valor do servico (R$): ");
        scanf("%f", &(frota+i)->valor);
    }
}

int main()
{
    int quantidade;
    printf("Quantos veiculos serao atendidos hoje?");
    scanf("%d", &quantidade);

    Veiculo *frota = (Veiculo *) malloc(quantidade * sizeof(Veiculo));
    
    if(frota == NULL){
        printf("");
        return 1;
    }

    preencherFrota(frota, quantidade);

    return 0;
}
