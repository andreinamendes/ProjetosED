#include <stdio.h>

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';
const char BURN = 'x';

//Esquerda, Baixo, Direita, Cima
int L[] = {0, 1, 0, -1};
int C[] = {-1, 0, 1, 0};
int sizeM = sizeof(L)/sizeof(int);

void MostrarMatriz(int nLin, int nCol, char matriz[nLin][nCol]){
    setbuf(stdin, NULL);
    for(int a = 0; a < nLin; a++){
        for(int i = 0; i < nCol; i++)
            printf("%c", matriz[a][i]);
        puts("");
    }
    getchar();    
}

int TocarFogo(int nLin, int nCol, char matriz[nLin][nCol], int Lin, int Col){
    if((Lin < 0) || (Lin >= nLin) || (Col < 0) || (Col >= nCol))
        return 0;
    if(matriz[Lin][Col] != TREE)
        return 0;
    matriz[Lin][Col] = FIRE;
    MostrarMatriz(nLin, nCol, matriz);
    int destruicao = 1;
    for(int a = 0; a < sizeM; a++){
        destruicao += TocarFogo(nLin, nCol, matriz, Lin + L[a], Col + C[a]);
    }    
    matriz[Lin][Col] = BURN;
    MostrarMatriz(nLin, nCol, matriz);
    return destruicao;
}

int main(){

    int nCol = 0;
    int nLin = 0;
    int Lin = 0;
    int Col = 0;
    scanf("%d %d %d %d", &nCol, &nLin, &Lin, &Col);

    char matriz[nLin][nCol];

    for(int a = 0; a < nLin; a++)
        for(int i = 0; i < nCol; i++)
            scanf(" %c", &matriz[a][i]);
    printf("\n");
    int destruicao;
    destruicao = TocarFogo(nLin, nCol, matriz, Lin, Col);
    printf("O total de árvores destruídas: %d\n", destruicao);

    return 0;
}