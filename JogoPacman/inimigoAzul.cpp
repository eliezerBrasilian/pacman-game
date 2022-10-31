#include "inimigoAzul.h"

InimigoAzul::InimigoAzul(){
    imagemInimigo = NULL;
}
void InimigoAzul::setImagem(){
    imagemInimigo = al_load_bitmap("../imagensJogo/azul.png");
}
ALLEGRO_BITMAP* InimigoAzul::getImagem(){
    return imagemInimigo;
}
InimigoAzul::~InimigoAzul(){
    al_destroy_bitmap(imagemInimigo);
}
int InimigoAzul::getPosY(){
    return pos_y;
}
int InimigoAzul::getPosX(){
    return pos_x;
}
void InimigoAzul::movimenta(char orientacao){
    if(orientacao == 'd')pos_x++;
    if(orientacao == 'e')pos_x--;
    if(orientacao == 'c')pos_y--;
    if(orientacao == 'b')pos_y++;
}


