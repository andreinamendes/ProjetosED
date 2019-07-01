#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void ShowMaze(int l, int c, char maze[l][c]){
    //printf("\n");
    for(int a = 0; a < l; a++){
        for(int i = 0; i < c;i++)
            printf("%c", maze[a][i]);
        printf("\n");
    }
    setbuf(stdin, NULL);
    puts("");
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

void MixVector(int pos[]){
    for(int a = 0; a < 4; a++){
        int x = rand() % 4;
        int aux = pos[x];
        pos[x] = pos[a];
        pos[a] = aux;
    }
}

int CreateMaze(int nl, int nc, char maze[nl][nc], bool Visited[nl][nc], int l_i, int c_i){
    if(l_i < 1 || l_i == nl - 1 || c_i < 1 || c_i >= nc - 1)
        return 0;
    if(maze[l_i][c_i] != '@')
        return 0;
    if(Neibers(nl, nc, maze, l_i, c_i) > 1)
        return 0;
    maze[l_i][c_i] = ' ';
    int pos[] = {0, 1, 2, 3};
    MixVector(pos);
    for(int a = 0; a < 4; a++){
        CreateMaze(nl, nc, maze, Visited, l_i + L[pos[a]], c_i + C[pos[a]]);
    }
}

bool FindPosition(int nl, int nc, char maze[nl][nc], bool Visited[nl][nc], int l_i, int c_i, int l_f, int c_f){
    if(maze[l_i][c_i] == '@' || maze[l_f][c_f] == '@')
        return false;
    if(Visited[l_i][c_i] == true)
        return false;
    Visited[l_i][c_i] = true;
    maze[l_i][c_i] = '.';
    if(l_i == l_f && c_i == c_f)
        return true;
    int pos[] = {0, 1, 2, 3};
    MixVector(pos);
    bool result = 0;
    for(int a = 0; a < 4; a++){
        result = FindPosition(nl, nc, maze, Visited, l_i + L[pos[a]], c_i + C[pos[a]], l_f, c_f);
        if(result)
            return true;
    }
    maze[l_i][c_i] = ' ';
    return false;
}

int main(){
    srand(time(NULL));
    int Col = 0, Lin = 0;
    printf("Digite o número de linhas: ");
    scanf(" %d", &Lin);
    printf("Digite o número de colunas: ");
    scanf(" %d", &Col);
    
    char Maze[Lin][Col];
    bool Visited[Lin][Col];

    for(int a = 0; a < Lin; a++)
        for(int i = 0; i < Col; i++)
            Maze[a][i] = '@';

    for(int a = 0; a < Lin; a++)
        for(int i = 0; i < Col; i++)
            Visited[a][i] = false;

    CreateMaze(Lin, Col, Maze, Visited, 1, 1);
    ShowMaze(Lin, Col, Maze);

    int Lin_i = 0, Col_i = 0, Lin_f = 0, Col_f = 0;
    printf("Digite a linha e a coluna inicial, respectivamente: ");
    scanf(" %d %d", &Lin_i, &Col_i);
    printf("Digite a linha e a coluna final, respectivamente: ");
    scanf(" %d %d", &Lin_f, &Col_f);

    FindPosition(Lin, Col, Maze, Visited, Lin_i, Col_i, Lin_f, Col_f);
    ShowMaze(Lin, Col, Maze);

    return 0;
}