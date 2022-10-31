#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include<iostream>

#ifndef CLASSEPILULA_H
#define CLASSEPILULA_H

class classePilula{

  public:
      classePilula();
      ~classePilula();
   void setImagemPilula();
   void setImagemFrutas();
   ALLEGRO_BITMAP* getImagemPilula();

    private: ALLEGRO_BITMAP* pilula;


};

 #endif
