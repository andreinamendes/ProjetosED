#include "xpaint.h"

void create_floco(int x, int y, int ang, int tamanho){
    if(tamanho < 10)
        return;
    int x2, y2;
    for(int a = 0; a < 5; a++){
        x2 = x + tamanho * xm_cos(ang);
        y2 = y - tamanho * xm_sin(ang);
        xd_thick_line(x, y, x2, y2, 4);
        ang -= 72;
        create_floco(x2, y2, ang, tamanho/3);
    }
    
}

int main(){
    int largura = 1000, altura = 1000;
    x_open(largura, altura);
    int x = largura / 2, y = altura / 2, angulo = 270, tamanho = 300;
    create_floco(x, y, angulo, tamanho);
    x_save("figura_base");
    x_close();
    return 0;
}