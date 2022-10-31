#include "inimigoRosa.h"

InimigoRosa::InimigoRosa(){
    imagemInimigo = NULL;
}
void InimigoRosa::setImagem(){
    imagemInimigo = al_load_bitmap("../imagensJogo/rosa.png");
}
ALLEGRO_BITMAP* InimigoRosa::getImagem(){
    return imagemInimigo;
}
InimigoRosa::~InimigoRosa(){
    al_destroy_bitmap(imagemInimigo);
}
int InimigoRosa::getPosY(){
    return pos_y;
}
int InimigoRosa::getPosX(){
    return pos_x;
}
void InimigoRosa::movimenta(char orientacao){
    if(orientacao == 'd')pos_x++;
    if(orientacao == 'e')pos_x--;
    if(orientacao == 'c')pos_y--;
    if(orientacao == 'b')pos_y++;
}



