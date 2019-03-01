#include "stdio.h"

void Print_V(int n, int v[n]){
    printf("[");
    for(int a = 0; a < n; a++){
        if(a == n-1){
            printf("%d", v[a]);
        }else{
            printf("%d ", v[a]);
        }
    }
    printf("]\n");
}

void Movimenta_V(int n, int v[n], int vit){

    int aux = v[vit];

    for(int i = vit; i < n - 1; i++){
        
        v[i] = v[i+1];

    }
    
    v[n-1] = aux;

}

int Modifica_V(int n, int v[n], int killer){

    Print_V(n, v);

    if(n == 1){
        return 0;       
    }else{
        if(killer == (n-2)){
            n--;
            killer = 0;
        }else if(killer == n-1){
            Movimenta_V(n, v, 0);
            n--;
            killer = 0;
        }else{
            Movimenta_V(n, v, killer + 1);
            n--;
            killer += 1;
        }

        Modifica_V(n, v, killer);
    }

}

int main(){

    int N, inicial;

    scanf("%d", &N);
    scanf("%d", &inicial);

    int caras[N];

    for(int a = 0; a < N; a++){
        caras[a] = a + 1;
    }

    Modifica_V(N, caras, inicial - 1);

    return 0;
}