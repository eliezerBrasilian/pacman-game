
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include<iostream>
#include "classePacman.h"

#ifndef INIMIGOROSA_H
#define INIMIGOROSA_H

class InimigoRosa:public classePacman{
  public:
   InimigoRosa();
   ~InimigoRosa();
   void setImagem();
   ALLEGRO_BITMAP* getImagem();
   int getPosX();
   int getPosY();
   virtual void movimenta(char);

    private: ALLEGRO_BITMAP *imagemInimigo;
    private: int pos_y = 1;
    private: int pos_x = 17;
};

 #endif

