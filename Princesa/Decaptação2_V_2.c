#include <stdio.h>

void MostrarVetor(int tamanho, int vetor[], int assassino){
    printf("[");
    for(int a = 0; a < tamanho; a++){
        if(a == assassino && vetor[a] < 0)
            printf("<");

        printf("%d", vetor[a]);

        if(a == assassino && vetor[a] > 0)
            printf(">");
        if(a != tamanho - 1)
            printf(" ");
    }
    printf("]");
}

void MovimentaMorto(int tamanho, int vetor[], int vitima){
    for(int a = vitima; a < tamanho - 1; a++) 
        vetor[a] = vetor[a + 1];
    if(vitima < E){=

    }
}

int main(){
    
    int tamanho = 0; //Número de Participantes.
    scanf("%d", &tamanho);
    int escolhido = 0; //O escolhido.
    scanf("%d", &escolhido);
    int fase = 0; //Indica o lado da movimentação.
    scanf("%d", &fase);
    int direcao = 0;
    int saltos = 0;
    int vitima = 0;
    int vetor[tamanho];

    for(int a = 0; a < tamanho; a++){
        vetor[a] = (a + 1) * fase;
        fase *= (-1);
    }

    for(int a = 0; a < tamanho; a++){
        MostrarVetor(tamanho, vetor, escolhido - 1);

    }
    return 0;
}