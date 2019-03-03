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
    printf("]\n");
}

void MovimentaMorto(int *tamanho, int vetor[], int vitima, int* assassino){
    for(int a = vitima; a < *tamanho - 1; a++){
        vetor[a] = vetor[a + 1];
    }
    
    if(vitima < *assassino)
        *assassino -= 1;
    
    *tamanho -= 1;
}

void NovoAssassino(int tamanho, int direcao, int* asssassino, int saltos){
    if (direcao == 1)
        while(saltos > 0){
            *asssassino = (*asssassino + 1) % tamanho;
            saltos--;
        }
    else
        while(saltos > 0){
            *asssassino = (*asssassino + tamanho - 1) % tamanho;
            saltos--;
        }
}   

int main(){
    
    int tamanho = 0;
    scanf("%d", &tamanho);
    int escolhido = 0;
    scanf("%d", &escolhido);
    int fase = 0;
    scanf("%d", &fase);
    int direcao = 0;
    int saltos = 0;
    int vitima = 0;
    int assassino = 0;
    int vetor[tamanho];

    for(int a = 0; a < tamanho; a++){
        vetor[a] = (a + 1) * fase;
        fase *= -1;
    }

    assassino = escolhido - 1;
    MostrarVetor(tamanho, vetor, assassino);

    while(tamanho > 1){
        direcao = vetor[assassino] > 0 ? 1 : -1;
        saltos = vetor[assassino] > 0 ? vetor[assassino] : -vetor[assassino];
        vitima = direcao == 1 ? (assassino + 1) % tamanho : (assassino + tamanho - 1) % tamanho;
        MovimentaMorto(&tamanho, vetor, vitima, &assassino);
        NovoAssassino(tamanho, direcao, &assassino, saltos);
        MostrarVetor(tamanho, vetor, assassino);
    }
    return 0;
}