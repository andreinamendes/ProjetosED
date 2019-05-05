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

void bubble(int vector[], int n){
    for(int a = 0; a < n; a++){
        for(int i = 0; i < n - 1; i++){
            int imenor = find_menor(vector, i, i+1);    
            SWAP(vector, i, imenor);
            Show(vector, n);
        }
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