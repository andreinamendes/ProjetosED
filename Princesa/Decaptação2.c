#include <stdio.h>


void print_vetor(int tamanho, int vetor[], int assassino){
    
    printf("[");
    for(int a = 0; a < tamanho; a++){
        
        if(a == assassino && vetor[assassino] < 0){

            printf("<");
            printf("%d", vetor[a]);
        }else{

            printf("%d", vetor[a]);
            printf(">");
        }

        if(a != tamanho - 1) printf(" ");
    }
    printf("]\n");
}

void Movimenta_Defunto(int tamanho, int vetor[], int vitima){

    for(int a = vitima; a < tamanho - 1; a++) 
        vetor[a] = vetor[a + 1];
}

int Descobre_Killer(int tamanho, int vetor[], int assassino){

    int limite_incremento = 0;

    if(vetor[assassino] < 0){
    
        limite_incremento = vetor[assassino] * (-1);
        for(int a = 0; a < limite_incremento; a++){

            if(assassino == 0) assassino = tamanho - 1;
            else assassino--;
        }
    }else if(vetor[assassino] > 0){

        limite_incremento = vetor[assassino];
        for(int a = 0; a < limite_incremento; a++) assassino = (assassino + 1) % tamanho;
    }

    printf("%d ", limite_incremento);
    printf("%d", assassino);

    return assassino;
}

int Mata_Lascado(int tamanho, int vetor[], int escolhido){

    int assassino = escolhido; //Assassino é o indice do killer.
    int vitima = 0;

    if(tamanho == 1){

        return 0;
    }else{

        if(vetor[assassino] < 0){
            
            if(assassino == 0) 
                vitima = tamanho - 1; //Caso base para quando o assassino for o primeiro valor e tiver que subtrair.
            else 
                vitima = (assassino - 1) % tamanho;
            Movimenta_Defunto(tamanho, vetor, vitima);
            tamanho--;
            assassino = Descobre_Killer(tamanho, vetor, assassino);
        }else if(vetor[assassino] > 0){

            vitima = (assassino + 1) % tamanho;
            Movimenta_Defunto(tamanho, vetor, vitima);
            tamanho--;
            assassino = Descobre_Killer(tamanho, vetor, assassino);
        }

        print_vetor(tamanho, vetor, assassino);
        Mata_Lascado(tamanho, vetor, assassino);
    }
}

encontrar_vivo(vet, size, inicial, dir)
    if (dir == 1) 
        return (inicial + 1) % size
    return (inicial + size - 1) % size
    

matar(vet, *size, *E, vai_morrer)
    for(int i = vai_morrer; i < size - 1; i++)
        vet[i] = vet[i + 1];
    se vai_morrer < E:
        *E -= 1
    *size -= 1



int main(){

    int N = 0; //Número de Participantes.
    scanf("%d", &N);
    int E = 0; //O escolhido.
    scanf("%d", &E);
    int FASE = 0; //Indica o lado da movimentação.
    scanf("%d", &FASE);

    int Vetor[N];

    for(int a = 0; a < N; a++){
        saltos
        dir
        vai_morrer = encontrar_vivo(vet, size, inicia, dir)
        matar(vet, &size, &E, ref, dir)

        if(FASE < 0){

            if(a % 2 == 0) Vetor[a] = (a + 1) * (-1); //Adiciona o valor de a (que for par) negativo.
            else Vetor[a] = a + 1;
        }else{
            
            if(a % 2 == 1) Vetor[a] = (a + 1) * (-1); //Adiciona o valor de a (que for ímpar) negativo.
            else Vetor[a] = a + 1;
        }
    } 

    print_vetor(N, Vetor, E - 1);
    Mata_Lascado(N, Vetor, E - 1);

    return 0;
}