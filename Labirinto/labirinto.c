#include <stdio.h>

void ShowMaze(int l, int c, char Maze[l][c]){
    //printf("\n");
    for(int a = 0; a < l; a++){
        for(int i = 0; i < c;i++)
            printf("%c", Maze[a][i]);
        printf("\n");
    }
    setbuf(stdin, NULL);
    getchar();   
}

int L[] = {0, 1, 0, -1};
int C[] = {-1, 0, 1, 0};
int sizeM = sizeof(L)/sizeof(int);

int Neibers(int nl, int nc, char Maze[nl][nc], int l, int c){
    int neib = 0;
    for(int a = 0; a < sizeM; a++){
        if(Maze[l + L[a]][c + C[a]] == ' '){
            neib++;
        }
    } 
    return neib;
}

int CreateMaze(int nl, int nc, char Maze[nl][nc], int pos[]){
    if(pos[0] < 1 || pos[0] >= nl - 1 || pos[1] < 1 || pos[1] >= nc - 1)
        return 0;
    if(Maze[pos[0]][pos[1]] != '@')
        return 0;
    if(Neibers(nl, nc, Maze, pos[0], pos[1]) > 1)
        return 0;
    Maze[pos[0]][pos[1]] = ' ';
    ShowMaze(nl, nc, Maze);
    
    CreateMaze(nl, nc, Maze, pos);
}

int main(){

    int Col = 0;
    int Lin = 0;
    printf("Digite o número de linhas: ");
    scanf(" %d", &Lin);
    printf("Digite o número de colunas: ");
    scanf(" %d", &Col);
    char Maze[Lin][Col];
    int posicao[] = {1, 1};

    for(int a = 0; a < Lin; a++)
        for(int i = 0; i < Col; i++)
            Maze[a][i] = '@';

    ShowMaze(Lin, Col, Maze);
    CreateMaze(Lin, Col, Maze, posicao);

    return 0;
}