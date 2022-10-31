#include "classeInimigoVermelho.h"

InimigoVermelho::InimigoVermelho(){
    imagemInimigo = NULL;
}
void InimigoVermelho::InimigoSetImagem(){
    imagemInimigo = al_load_bitmap("../imagensJogo/vermelho.png");
}
ALLEGRO_BITMAP* InimigoVermelho::getImagemInimigo(){
    return imagemInimigo;
}
InimigoVermelho::~InimigoVermelho(){
    al_destroy_bitmap(imagemInimigo);
}
int InimigoVermelho::getPosy(){
    return pos_y;
}
int InimigoVermelho::getPosx(){
    return pos_x;
}
void InimigoVermelho::movimenta(char orientacao){
    if(orientacao == 'd')pos_x++;
    if(orientacao == 'e')pos_x--;
    if(orientacao == 'c')pos_y--;
    if(orientacao == 'b')pos_y++;
}

