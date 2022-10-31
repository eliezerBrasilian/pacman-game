#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include<iostream>

#ifndef CLASSETIJOLOS_H
#define CLASSETIJOLOS_H

class classeTijolos{
  public:
      classeTijolos();
      ~classeTijolos();
   void setImagemTijolos();
   void setImagemBloco();
   ALLEGRO_BITMAP* getImagemTijolos();
   ALLEGRO_BITMAP* getImagemBlocos();

    private: ALLEGRO_BITMAP *tijolinhos;
    private: ALLEGRO_BITMAP *blocos;
};

 #endif
