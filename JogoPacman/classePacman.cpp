#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include<iostream>
#include "classePacman.h"

classePacman::classePacman(){
    pacmanImagemCima = NULL;
    pacmanImagemBaixo = NULL;
    pacmanImagemEsq = NULL;
    pacmanImagemDir = NULL;
}

classePacman::~classePacman(){
    al_destroy_bitmap(pacmanImagemFrente);
    al_destroy_bitmap(pacmanImagemEsq);
    al_destroy_bitmap(pacmanImagemDir);
    al_destroy_bitmap(pacmanImagemCima);
    al_destroy_bitmap(pacmanImagemBaixo);
}

ALLEGRO_BITMAP* classePacman::getImagemFrente()
{
   return pacmanImagemFrente;
}
ALLEGRO_BITMAP* classePacman::getImagemEsquerda()
{
   return pacmanImagemEsq;
}
ALLEGRO_BITMAP* classePacman::getImagemDireita()
{
   return pacmanImagemDir;
}
ALLEGRO_BITMAP* classePacman::getImagemCima()
{
   return pacmanImagemCima;
}
ALLEGRO_BITMAP* classePacman::getImagemBaixo()
{
   return pacmanImagemBaixo;
}

void classePacman::setImagem()
        {

            pacmanImagemFrente = al_load_bitmap("../imagensJogo/pacman_frente.png");
            pacmanImagemEsq = al_load_bitmap("../imagensJogo/pacman_esq.png");
            pacmanImagemDir = al_load_bitmap("../imagensJogo/pacman_dir.png");
            pacmanImagemCima = al_load_bitmap("../imagensJogo/pacman_cima.png");
            pacmanImagemBaixo = al_load_bitmap("../imagensJogo/pacman_baixo.png");

        }
int classePacman::getPosX()
{
    return pos_x;
}

int classePacman::getPosY()
{
    return pos_y;
}

void classePacman::movimenta(char orientacao){
    if(orientacao == 'd')pos_x++;
    if(orientacao == 'e')pos_x--;
    if(orientacao == 'c')pos_y--;
    if(orientacao == 'b')pos_y++;

}

