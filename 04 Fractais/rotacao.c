#include "xpaint.h"

void create_espiral(int x, int y, int tamanho, int angulo){
    if(tamanho < 5)
        return;
    int x2 = x + tamanho * xm_cos(angulo);
    int y2 = y - tamanho * xm_sin(angulo);
    xd_thick_line(x, y, x2, y2, 3);
    create_espiral(x2, y2, tamanho - 10, angulo - 90);
}

int main(){
    int largura = 600, altura = 600;
    x_open(largura, altura);
    int tamanho = 500, angulo = 0, x = 50, y = 50;
    create_espiral(x, y, tamanho, angulo);
    x_save("figura_base");
    x_close();
    return 0;
}