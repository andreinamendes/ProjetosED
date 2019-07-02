#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos{
    int l, c;
    Pos(int l = 0, int c = 0){
        this->l = l;
        this->c = c;
    }
};

vector<Pos> get_neibs(int l, int c){
    return vector<Pos> {Pos(l, c - 1), Pos(l - 1, c), Pos(l, c + 1), Pos(l + 1, c)};
}

bool has_value(vector<string> &mat, int l, int c, char value){
    if(l < 0 || l >= (int) mat.size() || c < 0 || c >= (int) mat[0].size())
        return false;
    return mat[l][c] == value;
}

void show(vector<string> mat, int l, int c){
    for(int a = 0; a < l; a++){
        for(int i = 0; i < c; i++)
            cout << mat[a][i] << ' ';
        cout << endl;
    }
}

void find_way(int l, int c, int x_i, int y_i, int x_f, int y_f, vector<string>& mat){
    
}

int main(){
    srand(time(NULL));

    int l = 0, c = 0;
    cout << "Número de linhas e colunas, respectivamente: ";
    cin >> l >> c;

    vector<string> mat(l);

    for(int a = 0; a < l; a++)
        mat[a].resize(c);

    string obstaculo = ("|@");

    for(int a = 0; a < l; a++)
        for(int i = 0; i < c; i++)
            mat[a][i] = obstaculo[rand() % 2];

    show(mat, l, c);

    int x_i = 0, y_i = 0, x_f = 0, y_f = 0;
    cout << "Digite a linha e a coluna inicial, respectivamente: ";
    cin >> x_i >> y_i;
    cout << "Digite a linha e a coluna final, respectivamente: ";
    cin >> x_f >> y_f;

    if(mat[x_i][y_i] == '|' || mat[x_f][y_f] == '|'){
        cout << 'fail: dados inválidos' << endl;
        return;
    }

    find_way(l, c, x_i, y_i, x_f, y_f, mat);
    show(mat, l, c);

}