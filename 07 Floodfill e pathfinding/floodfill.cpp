#include <iostream>
#include "../Libs/xmat.h"
#include "../Libs/xpaint.h"
#include <vector>

using namespace std;

int main(){

    int l = 0, c = 0;
    cout << "Número de linhas e colunas, respectivamente: ";
    cin >> l >> c;

    xmat_init(l, c);

    vector<string> mat;

    string color = "rgb";

    for(int a = 0; a < l; a++){
        for(int i = 0; i < c; i++){
            mat[a][i] = xm_rand(0, 2);
        }
    }

    xmat_draw(mat);
    x_save("floodfill");
    x_close();
}