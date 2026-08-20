/*
 * Programa criado para calcular a media de alunos e realizar uma simulação de acrescimo de bonus, sem alteração no valor inicial,
 * e depois realizar a alteração, acrescentando o bonus no valor inicial para cada nota e recalcular a média final apos alteração.
 *
 * Autor: Gustavo Carneiro Alves da Silva
 * Data: 17/08/26
 * Versao: 1.0.0
 */

#include <stdio.h>

#define TAMANHO_TURMA 5 //define a quantidade de alunos na turma

void exibirCabecalho(){ //cabecalho da instiuicao e titulo do programa
    printf("+------------------------------------+\n");
    printf("| Faculdade de Tecnologia - Ipiranga |\n");
    printf("+------------------------------------+\n");
    printf("Sistema de Ajuste e Análise de Notas.\n\n");
}

float calculcarMedia (float notas[], int tamanho){ //calculo de media realizado por laço de repeticao "for" para percorrer todo array
    //utilizamos a declaração de um vetor como parametro pois um vetor, em C, ja faz apontamento direto para o endereço de memoria do primeiro elemento (indice 0)
    float soma = 0;
    for (int i = 0; i < tamanho; i++){
        soma += notas[i];
    }
    float media = soma / tamanho;

    return media;
}

void simularAjuste (float notaOriginal, float bonus){ //simulacao de atribuicao de bonus, pega o primeiro valor do array (notas[0]) e printa o valor SEM alterar o valor inicial
    notaOriginal += bonus;
    printf("%.2f", notaOriginal);
}

void aplicarBonus (float *nota, float bonus){ //realiza o acrescimo de bonus utilizando apontamento no endereço de memoria da variavel "nota"
    *nota += bonus;
}

int main() {
    exibirCabecalho();

    float notas[TAMANHO_TURMA], bonus;

    for(int i = 0; i < TAMANHO_TURMA; i++){ //laco de repeticao para percorrer o array e guardar as notas dos alunos
        printf("Digite a nota do aluno %d: ", (i+1));
        scanf("%f", &notas[i]);
        while (notas[i] < 0 || notas[i] > 10){//validacao de nota, verifica se é uma nota válida dentro do padrão 0 a 10
            printf("\nNota inválida, tente novamente: ");
            printf("\nDigite a nota do aluno %d: ", (i+1));
            scanf("%f", &notas[i]);
        }
    }

    printf("\nInforme o valor do bonus a aplicar: (utilize '.')");
    scanf("%f", &bonus);
    while (bonus < 0){ //validacao de bonus, verifica se o bonus é maior ou igual a 0
        printf("Bonus inválido, tente novamente.");
        printf("\nInforme o valor do bonus a aplicar: (utilize '.')");
        scanf("%f", &bonus);
    }
    

    printf("\n#---- Media da Turma antes do bonus: ----#");
    printf("\nMedia: %.2f", calculcarMedia(notas, TAMANHO_TURMA));

    printf("\n\n#---- Simulação de ajuste: ----#");
    printf("\nSimulação do aluno 1: %.2f + %.2f = ", notas[0], bonus);
    simularAjuste(notas[0], bonus);
    printf(" (NÃO aplicado ainda.)");
    printf("\nNota do aluno 1 apos a simulação (*SEM ALTERAÇÕES*): %.2f", notas[0]);

    printf("\n\n#---- Aplicacao do bonus: ----#");
    printf("\nBonus de %.2f aplicado em TODAS as notas da turma.", bonus);

    

    printf("\n\n#---- Notas finais da turma: ----#");
    for (int i = 0; i < TAMANHO_TURMA; i++){ //laco de repeticao para realizar a alteracao das notas conforme a funcao "aplicarBonus" e printar o resultado das notas apos acrescimo
        aplicarBonus(&notas[i], bonus);
        printf("\nAluno %d: %.2f", (i+1), notas[i]);
    }

    printf("\n\n#---- Media da turma apos ajuste de bonus: ----#");
    printf("\nMedia final: %.2f", calculcarMedia(notas, TAMANHO_TURMA));

    return 0;
} //fim do main
