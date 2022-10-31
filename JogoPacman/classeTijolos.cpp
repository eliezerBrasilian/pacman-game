#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include<iostream>
#include "classeTijolos.h"

using namespace std;

    classeTijolos::classeTijolos(){
        tijolinhos = NULL;
    }
    classeTijolos::~classeTijolos(){
        al_destroy_bitmap(tijolinhos);
    }
    void classeTijolos::setImagemTijolos()
        {
         tijolinhos = al_load_bitmap("../imagensJogo/tijolo.png");
        }
    void classeTijolos::setImagemBloco()
        {
         tijolinhos = al_load_bitmap("../imagensJogo/bloco.png");
        }

    ALLEGRO_BITMAP* classeTijolos::getImagemTijolos(){
        return tijolinhos;
    }
     ALLEGRO_BITMAP* classeTijolos::getImagemBlocos(){
        return blocos;
    }
