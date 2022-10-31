#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "classePacman.h"
#ifndef CLASSE_INIMIGO_VERMELHO_H
#define CLASSE_INIMIGO_VERMELHO_H

class InimigoVermelho:public classePacman{
    friend void atualizaPosicaoInimigoVermelho(InimigoVermelho&,int,int);
    public:
    InimigoVermelho();
    ~InimigoVermelho();
    void InimigoSetImagem();
    ALLEGRO_BITMAP* getImagemInimigo();
    int getPosy();
    int getPosx();
    virtual void movimenta(char);
    private:
        ALLEGRO_BITMAP* imagemInimigo;
        int pos_y = 1;
        int pos_x = 1;
};

#endif // CLASSE_INIMIGOS_H
