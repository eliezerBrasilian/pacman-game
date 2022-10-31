#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "classePacman.h"
#ifndef INIMIGO_LARANJA_H
#define INIMIGO_LARANJA_H

class InimigoLaranja:public classePacman{
friend void atualizaPosicaoInimigoLaranja(InimigoLaranja&,int,int);
  public:
   InimigoLaranja();
   ~InimigoLaranja();
   void setImagem();
   ALLEGRO_BITMAP* getImagem();
   int getPosX();
   int getPosY();
   virtual void movimenta(char orientacao);

    private: ALLEGRO_BITMAP *imagemInimigoLaranja;
    private: int pos_y = 13;
    private: int pos_x = 1;

};


#endif
