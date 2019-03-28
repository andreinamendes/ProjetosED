#include "xpaint.h"

void create_fractal(int x, int y, int raio, int angulo){
    if(raio < 5)
        return;
    xd_circle(x, y, raio);
    int x2, y2;
    for(int a = 0; a < 6; a++){
        x2 = x - raio * xm_cos(angulo);
        y2 = y - raio * xm_sin(angulo);
        xd_circle(x2, y2, raio/3);
        angulo -= 60;
        create_fractal(x2, y2, raio/3, angulo - 60);
    }
}

int main(){
    int largura = 800, altura = 800, raio = 250;
    int x = largura/2, y = altura/2, angulo = 60;
    x_open(largura, altura);
    create_fractal(x, y, raio, angulo);
    x_save("figura_base");
    x_close();
    return 0;
}