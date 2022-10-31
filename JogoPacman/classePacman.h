#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include<iostream>

#ifndef CLASSEPACMAN_H
#define CLASSEPACMAN_H

class classePacman{
  friend void atualizaVidas(classePacman&,int);
  friend void atualizaPosicaoPacman(classePacman&,int,int);
  public:
   classePacman();
   ~classePacman();
   void setImagem();
   ALLEGRO_BITMAP* getImagemFrente();
   ALLEGRO_BITMAP* getImagemEsquerda();
   ALLEGRO_BITMAP* getImagemDireita();
   ALLEGRO_BITMAP* getImagemCima();
   ALLEGRO_BITMAP* getImagemBaixo();
   virtual void movimenta(char);
   int getPosX();
   int getPosY();

    private: ALLEGRO_BITMAP *pacmanImagemFrente;
    private: ALLEGRO_BITMAP *pacmanImagemEsq;
    private: ALLEGRO_BITMAP *pacmanImagemDir;
    private: ALLEGRO_BITMAP *pacmanImagemBaixo;
    private: ALLEGRO_BITMAP *pacmanImagemCima;
    private: int pos_y = 7;
    private: int pos_x = 9;
    private: int velocidade = 1;

};

 #endif

