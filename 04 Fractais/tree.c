#include "xpaint.h"

void create_tree(int x, int y, int angulo, int tamanho, float espessura){
    if(tamanho < 5)
        return;
    int x2 = x + tamanho * xm_cos(angulo);
    int y2 = y - tamanho * xm_sin(angulo);
     if(tamanho < 80)
         xs_color((XColor){133, 153, 0});
    else
        xs_color((XColor){139,69,19});
    xd_thick_line(x, y, x2, y2, espessura);
    int i = xm_rand(2, 3);
    int var[] = {30, -30, xm_rand(-7, 7)};
    for(int a = 0; a < i; a++){
        create_tree(x2, y2, angulo + var[a], tamanho - xm_rand(5, 15), espessura - xm_rand(0, 1));
        if(tamanho < 10){
            xs_color((XColor){211, 1, 2});
            xd_filled_circle(x2, y2, 3); 
        } 
    }
}

int main(){
    int largura = 1200, altura = 1000;
    x_open(largura, altura);
    float angulo = 90, tamanho = 100, espessura = 6;
    int x = largura / 2, y = altura - 80;
    create_tree(x, y, angulo, tamanho, espessura);
    x_save("figura_base");
    x_close();
    return 0;
}