#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include<iostream>
#include "classePacman.h"

#ifndef INIMIGOAZUL_H
#define INIMIGOAZUL_H

class InimigoAzul:public classePacman{
  friend void atualizaPosicaoInimigoAzul(InimigoAzul&,int,int);
  public:
   InimigoAzul();
   ~InimigoAzul();
   void setImagem();
   ALLEGRO_BITMAP* getImagem();
   int getPosX();
   int getPosY();
   virtual void movimenta(char);

    private: ALLEGRO_BITMAP *imagemInimigo;
    private: int pos_y = 13;
    private: int pos_x = 17;
};

 #endif

