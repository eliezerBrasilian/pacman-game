#include "classeInimigos.h"

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

