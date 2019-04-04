#include "stdio.h"

void SWAP(int vector[], int a, int b){
    int aux = vector[a];
    vector[a] = vector[b];
    vector[b] = aux;
} 

void Show(int vector[], int n){
    printf("[");
    for(int a = 0; a < n; a++){
        printf("%d", vector[a]);
        if(a < n - 1)
            printf(" ");
    }
    printf("]\n");
}

int find_menor(int vector[], int a, int b){
    int imenor = 0;
    if(vector[a] < vector[b])
        imenor = a;
    else
        imenor = b;
    return imenor;
}

void Moves_values(int vector[], int n, int index){
    for(int a = index - 1; a < 0; a++){
        if(vector[a] > vector[index]){
            SWAP(vector, a, index);
        }
    }
}

void Insertion(int vector[], int n){
    int imenor = 0;
    for(int a = 0; a < n - 1; a++){
        imenor = find_menor(vector, a, a+1);
        Moves_values(vector, n, imenor);
    }
}

int main(){

    int n = 0;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);
    int vector[n];
    printf("Digite os valores do vetor: \n");
    for(int a = 0; a < n; a++)
        scanf("%d", &vector[a]);
    Insertion(vector, n);
    Show(vector, n);
    
    return 0;
}