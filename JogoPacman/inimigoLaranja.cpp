#include "inimigoLaranja.h"

InimigoLaranja::InimigoLaranja(){
    imagemInimigoLaranja = NULL;
}
void InimigoLaranja::setImagem(){
    imagemInimigoLaranja = al_load_bitmap("../imagensJogo/laranja.png");
}
ALLEGRO_BITMAP* InimigoLaranja::getImagem(){
    return imagemInimigoLaranja;
}
InimigoLaranja::~InimigoLaranja(){
    al_destroy_bitmap(imagemInimigoLaranja);
}
int InimigoLaranja::getPosY(){
    return pos_y;
}
int InimigoLaranja::getPosX(){
    return pos_x;
}
void InimigoLaranja::movimenta(char orientacao){
    if(orientacao == 'd')pos_x++;
    if(orientacao == 'e')pos_x--;
    if(orientacao == 'c')pos_y--;
    if(orientacao == 'b')pos_y++;
}
