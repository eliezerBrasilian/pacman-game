#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include<iostream>
#include "classePirula.h"

using namespace std;

classePilula::classePilula(){
    pilula = NULL;
}
classePilula::~classePilula(){
    al_destroy_bitmap(pilula);
}
void classePilula::setImagemPilula()
{
    pilula = al_load_bitmap("../imagensJogo/comestivel.png");
}
void classePilula::setImagemFrutas()
{
    pilula = al_load_bitmap("../imagensJogo/frutas.png");
}
ALLEGRO_BITMAP* classePilula::getImagemPilula(){
        return pilula;
}


