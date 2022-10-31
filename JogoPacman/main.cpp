#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include<iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "classePirula.h"
#include "classeTijolos.h"
#include "classePacman.h"
#include "classeInimigoVermelho.h"
#include "inimigoAzul.h"
#include "inimigoRosa.h"
#include "inimigoLaranja.h"
#include<time.h>
#include <string>

using namespace std;

    char cheat[10];
    bool cheat_sem_inimigo = false;
    bool mudei_pra_bloco = false;
    bool mudei_pra_frutas = false;

   //objetos
   classePilula pilula;
   classeTijolos tijolos;
   classePacman pacman;
   //objetos inimigos derivados
   InimigoVermelho inimigo;
   InimigoAzul inimigoAzul;
   InimigoRosa inimigoRosa;
   InimigoLaranja inimigoLaranja;

   //allegro
   ALLEGRO_SAMPLE* pacmanComendoPilula;
   ALLEGRO_SAMPLE* aplausos;
   ALLEGRO_AUDIO_STREAM* music;
   ALLEGRO_SAMPLE* opcao_selecionada;

      //proporcoes da tela
   int largura = 1100;
   int altura = 750;

   int pontos = 0;
   int vitoria = 135;//135
   bool pausado = false;
   bool perdeu = false;
   int danos = 0;
   int danos_limite = 3;

   //personagens
   int jogador = 0;
   int parede = 1;
   int pilulas = 2;
   int inimigo_vermelho = 3;
   int inimigo_azul = 4;
   int inimigo_rosa = 5;
   int inimigo_laranja = 6;

   //minhas strings
   char iniciarGame[31] = "START GAME                    ";
   char conhecer_a_gente[31] = "CONHECER OS DEVS DO PROJETO   ";
   char material_que_usamos[31] = "MATERIAL QUE USAMOS NO PROJETO";
   char carregar_algum_cheat[31] = "CARREGAR ALGUM CHEAT          ";
   char ouvir_musicas_do_jogo[31] = "OUVIR MUSICAS DO JOGO         ";
   char alterar_idioma[31] = "ALTERAR IDIOMA                ";
   char sair_string[31] = "SAIR                          ";
   char escolha_uma_opcao[31] = "Escolha uma opcao: ";
   char pressione_enter_pra_voltar[50] = "Pressione ENTER para retornar ao menu ";
   char criadores_projeto_pacman[75] = "\n\n\n\n\t Criadores: Eliezer Assuncao de Paulo e Camille Custodio de Paiva\n";
   char somos_estudantes_da_ufv[52] = "\t Somos estudantes da UFV e amamos tecnologia ;)\n\n";
   char nossos_creditos_a[20] = "NOSSOS CREDITOS A";
   char imagem_do_pacman[20] = "Imagem do Pacman:";
   char musica_do_menu[20] = "Musica do menu:";
   char sons_do_pacman[20] = "Sons do pacman:";
   char som_do_clique[20] = "Som do clique:";
   char som_de_carregando[20] = "Som de carregando:";
   char digite_o_cheat[20] = "DIGITE O CHEAT:";
   char cheat_ativado[20] = "cheat ativado";
   char carregando_string[17] = "CARREGANDO";
   char idioma_text[7] = "IDIOMA";
   char pontuacao_text[12] = "PONTUACAO";
   char pontos_text[12] = "pontos";
   char situacao[20] = "Jogando...";

   int mapaJogo[15][19];
    void mapa(){
    mapaJogo[0][0] = 1;  mapaJogo[0][1] = 1; mapaJogo[0][2] = 1; mapaJogo[0][3] = 1; mapaJogo[0][4] = 1; mapaJogo[0][5] = 1; mapaJogo[0][6] = 1; mapaJogo[0][7] = 1; mapaJogo[0][8] = 1; mapaJogo[0][9] = 1; mapaJogo[0][10] = 1; mapaJogo[0][11] = 1; mapaJogo[0][12] = 1; mapaJogo[0][13] = 1;  mapaJogo[0][14] = 1;   mapaJogo[0][15] = 1;   mapaJogo[0][16] = 1; mapaJogo[0][17] = 1; mapaJogo[0][18] = 1;
    mapaJogo[1][0] = 1;  mapaJogo[1][1] = inimigo_vermelho; mapaJogo[1][2] = 2; mapaJogo[1][3] = 2; mapaJogo[1][4] = 2; mapaJogo[1][5] = 2; mapaJogo[1][6] = 2; mapaJogo[1][7] = 2; mapaJogo[1][8] = 2; mapaJogo[1][9] = 2; mapaJogo[1][10] = 2; mapaJogo[1][11] = 2; mapaJogo[1][12] = 2; mapaJogo[1][13] = 2;  mapaJogo[1][14] = 2;   mapaJogo[1][15] = 2;   mapaJogo[1][16] = 2; mapaJogo[1][17] = 5; mapaJogo[1][18] = 1;
    mapaJogo[2][0] = 1;  mapaJogo[2][1] = 2; mapaJogo[2][2] = 1; mapaJogo[2][3] = 2; mapaJogo[2][4] = 1; mapaJogo[2][5] = 2; mapaJogo[2][6] = 1; mapaJogo[2][7] = 2; mapaJogo[2][8] = 1; mapaJogo[2][9] = 2; mapaJogo[2][10] = 1; mapaJogo[2][11] = 2; mapaJogo[2][12] = 1; mapaJogo[2][13] = 2;   mapaJogo[2][14] = 1;  mapaJogo[2][15] = 2;   mapaJogo[2][16] = 1; mapaJogo[2][17] = 2; mapaJogo[2][18] = 1;
    mapaJogo[3][0] = 1;  mapaJogo[3][1] = 2; mapaJogo[3][2] = 1; mapaJogo[3][3] = 2; mapaJogo[3][4] = 1; mapaJogo[3][5] = 2; mapaJogo[3][6] = 1; mapaJogo[3][7] = 2; mapaJogo[3][8] = 1; mapaJogo[3][9] = 2; mapaJogo[3][10] = 1; mapaJogo[3][11] = 2; mapaJogo[3][12] = 1; mapaJogo[3][13] = 2;   mapaJogo[3][14] = 1;  mapaJogo[3][15] = 2;   mapaJogo[3][16] = 1; mapaJogo[3][17] = 2; mapaJogo[3][18] = 1;
    mapaJogo[4][0] = 1;  mapaJogo[4][1] = 2; mapaJogo[4][2] = 1; mapaJogo[4][3] = 2; mapaJogo[4][4] = 1; mapaJogo[4][5] = 2; mapaJogo[4][6] = 1; mapaJogo[4][7] = 2; mapaJogo[4][8] = 1; mapaJogo[4][9] = 2; mapaJogo[4][10] = 1; mapaJogo[4][11] = 2; mapaJogo[4][12] = 1; mapaJogo[4][13] = 2;   mapaJogo[4][14] = 1;  mapaJogo[4][15] = 2;   mapaJogo[4][16] = 1; mapaJogo[4][17] = 2; mapaJogo[4][18] = 1;
    mapaJogo[5][0] = 1;  mapaJogo[5][1] = 2; mapaJogo[5][2] = 1; mapaJogo[5][3] = 2; mapaJogo[5][4] = 2; mapaJogo[5][5] = 2; mapaJogo[5][6] = 2; mapaJogo[5][7] = 2; mapaJogo[5][8] = 2; mapaJogo[5][9] = 2; mapaJogo[5][10] = 2; mapaJogo[5][11] = 2; mapaJogo[5][12] = 2; mapaJogo[5][13] = 2;   mapaJogo[5][14] = 2;  mapaJogo[5][15] = 2;   mapaJogo[5][16] = 1; mapaJogo[5][17] = 2; mapaJogo[5][18] = 1;
    mapaJogo[6][0] = 1;  mapaJogo[6][1] = 2; mapaJogo[6][2] = 1; mapaJogo[6][3] = 2; mapaJogo[6][4] = 1; mapaJogo[6][5] = 1; mapaJogo[6][6] = 1; mapaJogo[6][7] = 1; mapaJogo[6][8] = 1; mapaJogo[6][9] = 2; mapaJogo[6][10] = 1; mapaJogo[6][11] = 1; mapaJogo[6][12] = 1; mapaJogo[6][13] = 1;   mapaJogo[6][14] = 1;  mapaJogo[6][15] = 2;   mapaJogo[6][16] = 1; mapaJogo[6][17] = 2; mapaJogo[6][18] = 1;
    mapaJogo[7][0] = 1;  mapaJogo[7][1] = 2; mapaJogo[7][2] = 1; mapaJogo[7][3] = 2; mapaJogo[7][4] = 2; mapaJogo[7][5] = 2; mapaJogo[7][6] = 2; mapaJogo[7][7] = 2; mapaJogo[7][8] = 2; mapaJogo[7][9] = 0; mapaJogo[7][10] = 2; mapaJogo[7][11] = 2; mapaJogo[7][12] = 2; mapaJogo[7][13] = 2;   mapaJogo[7][14] = 2;  mapaJogo[7][15] = 2;   mapaJogo[7][16] = 1; mapaJogo[7][17] = 2; mapaJogo[7][18] = 1;
    mapaJogo[8][0] = 1;  mapaJogo[8][1] = 2; mapaJogo[8][2] = 2; mapaJogo[8][3] = 2; mapaJogo[8][4] = 1; mapaJogo[8][5] = 1; mapaJogo[8][6] = 1; mapaJogo[8][7] = 1; mapaJogo[8][8] = 1; mapaJogo[8][9] = 1; mapaJogo[8][10] = 1; mapaJogo[8][11] = 1; mapaJogo[8][12] = 1; mapaJogo[8][13] = 1;   mapaJogo[8][14] = 1;  mapaJogo[8][15] = 2;   mapaJogo[8][16] = 2; mapaJogo[8][17] = 2; mapaJogo[8][18] = 1;
    mapaJogo[9][0] = 1;  mapaJogo[9][1] = 2; mapaJogo[9][2] = 1; mapaJogo[9][3] = 2; mapaJogo[9][4] = 2; mapaJogo[9][5] = 2; mapaJogo[9][6] = 2; mapaJogo[9][7] = 2; mapaJogo[9][8] = 2; mapaJogo[9][9] = 2; mapaJogo[9][10] = 2; mapaJogo[9][11] = 2; mapaJogo[9][12] = 2; mapaJogo[9][13] = 2;   mapaJogo[9][14] = 2;  mapaJogo[9][15] = 2;   mapaJogo[9][16] = 1; mapaJogo[9][17] = 2; mapaJogo[9][18] = 1;
    mapaJogo[10][0] = 1; mapaJogo[10][1] = 2;mapaJogo[10][2] = 1;mapaJogo[10][3] = 2;mapaJogo[10][4] = 1;mapaJogo[10][5] = 1;mapaJogo[10][6] = 1;mapaJogo[10][7] = 1;mapaJogo[10][8] = 1;mapaJogo[10][9] = 2;mapaJogo[10][10] = 1;mapaJogo[10][11] = 1;mapaJogo[10][12] = 1; mapaJogo[10][13] = 1;  mapaJogo[10][14] = 1; mapaJogo[10][15] = 2; mapaJogo[10][16] = 1;mapaJogo[10][17] = 2;mapaJogo[10][18] = 1;
    mapaJogo[11][0] = 1; mapaJogo[11][1] = 2;mapaJogo[11][2] = 1;mapaJogo[11][3] = 2;mapaJogo[11][4] = 2;mapaJogo[11][5] = 2;mapaJogo[11][6] = 2;mapaJogo[11][7] = 2;mapaJogo[11][8] = 2;mapaJogo[11][9] = 2;mapaJogo[11][10] = 1;mapaJogo[11][11] = 2;mapaJogo[11][12] = 2; mapaJogo[11][13] = 2;  mapaJogo[11][14] = 1; mapaJogo[11][15] = 2; mapaJogo[11][16] = 1;mapaJogo[11][17] = 2;mapaJogo[11][18] = 1;
    mapaJogo[12][0] = 1; mapaJogo[12][1] = 2;mapaJogo[12][2] = 1;mapaJogo[12][3] = 2;mapaJogo[12][4] = 1;mapaJogo[12][5] = 2;mapaJogo[12][6] = 1;mapaJogo[12][7] = 2;mapaJogo[12][8] = 1;mapaJogo[12][9] = 2;mapaJogo[12][10] = 1;mapaJogo[12][11] = 2;mapaJogo[12][12] = 1; mapaJogo[12][13] = 2;  mapaJogo[12][14] = 1; mapaJogo[12][15] = 2; mapaJogo[12][16] = 1;mapaJogo[12][17] = 2;mapaJogo[12][18] = 1;
    mapaJogo[13][0] = 1; mapaJogo[13][1] = 6;mapaJogo[13][2] = 2;mapaJogo[13][3] = 2;mapaJogo[13][4] = 1;mapaJogo[13][5] = 2;mapaJogo[13][6] = 1;mapaJogo[13][7] = 2;mapaJogo[13][8] = 1;mapaJogo[13][9] = 2;mapaJogo[13][10] = 2;mapaJogo[13][11] = 2;mapaJogo[13][12] = 1; mapaJogo[13][13] = 2;  mapaJogo[13][14] = 2; mapaJogo[13][15] = 2; mapaJogo[13][16] = 2;mapaJogo[13][17] = inimigo_azul;mapaJogo[13][18] = 1;
    mapaJogo[14][0] = 1; mapaJogo[14][1] = 1;mapaJogo[14][2] = 1;mapaJogo[14][3] = 1;mapaJogo[14][4] = 1;mapaJogo[14][5] = 1;mapaJogo[14][6] = 1;mapaJogo[14][7] = 1;mapaJogo[14][8] = 1;mapaJogo[14][9] = 1;mapaJogo[14][10] = 1;mapaJogo[14][11] = 1;mapaJogo[14][12] = 1;mapaJogo[14][13] = 1; mapaJogo[14][14] = 1;   mapaJogo[14][15] = 1; mapaJogo[14][16] = 1;mapaJogo[14][17] = 1;mapaJogo[14][18] = 1;

   }

   void testaComponentes(bool test, const char *descricao){
    if(test) return;

    printf("Nao deu pra iniciar %s\n",descricao);
}

   void apresentacao(){
	printf("%s",criadores_projeto_pacman);
	printf("%s",somos_estudantes_da_ufv);
	getchar();
}

void mudaIdioma(char idioma){
    if(idioma == '1'){
                   strcpy(iniciarGame,"START GAME                    ");
                   strcpy(conhecer_a_gente,"KNOW WHO WE ARE               ");
                   strcpy(material_que_usamos,"MATERIAL WE USE IN THE PROJECT");
                   strcpy(carregar_algum_cheat,"LOAD SOME CHEATS              ");
                   strcpy(ouvir_musicas_do_jogo,"PLAY SONGS                    ");
                   strcpy(alterar_idioma,"CHANGE LANGUAGE               ");
                   strcpy(sair_string,"EXIT                          ");
                   strcpy(escolha_uma_opcao,"Choose an option: ");
                   strcpy(pressione_enter_pra_voltar," Tap ENTER to go back to MENU ");
                   strcpy(criadores_projeto_pacman,"\n\n\n\n\t Creators: Eliezer Assuncao de Paulo and Camille Custodio de Paiva\n");
                   strcpy(somos_estudantes_da_ufv,"\t We are UFV students and we love technology ;)\n\n");
                   strcpy(nossos_creditos_a,"OUR CREDITS TO");
                   strcpy(musica_do_menu,"Menu sound:");
                   strcpy(sons_do_pacman,"Pacman sounds:");
                   strcpy(som_do_clique,"Tap sound:");
                   strcpy(som_de_carregando,"Loading sound:");
                   strcpy(digite_o_cheat,"TYPE THE CHEAT:");
                   strcpy(cheat_ativado,"cheat ativated");
                   strcpy(idioma_text,"LANGUAGE");
                   strcpy(carregando_string,"LOADING");
                   strcpy(pontuacao_text,"SCORE");
                   strcpy(pontos_text,"points");
                   strcpy(situacao,"Playing...");

                }
            if(idioma == '2'){
                   strcpy(iniciarGame,"INICIAR JOGO                   ");
                   strcpy(conhecer_a_gente,"CONHECER OS DEVS DO PROJETO   ");
                   strcpy(material_que_usamos,"MATERIAL QUE USAMOS NO PROJETO");
                   strcpy(carregar_algum_cheat,"CARREGAR ALGUM CHEAT          ");
                   strcpy(ouvir_musicas_do_jogo,"OUVIR MUSICAS DO JOGO         ");
                   strcpy(alterar_idioma,"ALTERAR IDIOMA                ");
                   strcpy(sair_string,"SAIR                          ");
                   strcpy(escolha_uma_opcao,"Escolha uma opcao: ");
                   strcpy(pressione_enter_pra_voltar," Pressione ENTER para continuar ");
                   strcpy(criadores_projeto_pacman,"\n\n\n\n\t Criadores: Eliezer Assuncao de Paulo e Camille Custodio de Paiva\n");
                   strcpy(somos_estudantes_da_ufv,"\t Somos estudantes da UFV e amamos tecnologia ;)\n\n");
                   strcpy(nossos_creditos_a,"NOSSOS CREDITOS A");
                   strcpy(imagem_do_pacman,"Imagem do Pacman:");
                   strcpy(musica_do_menu,"Musica do Menu");
                   strcpy(sons_do_pacman,"Sons do pacman:");
                   strcpy(som_do_clique,"Som do clique:");
                   strcpy(som_de_carregando,"Som de carregando:");
                   strcpy(digite_o_cheat,"DIGITE O CHEAT:");
                   strcpy(cheat_ativado,"cheat ativado");
                   strcpy(idioma_text,"IDIOMA");
                   strcpy(carregando_string,"CARREGANDO");
                   strcpy(pontuacao_text,"PONTUACAO");
                   strcpy(pontos_text,"pontos");
                   strcpy(situacao,"Jogando...");
                }
}
   char menuInicial(){

        char opcao;

          do{
              system("cls");
              printf("\n\n\n\n\t ________________________________________________________________________________________________________\n");
              printf("\t{                                                                                                        }\n");
              printf("\t{***                                  _____________________________________                              }\n");
              printf("\t{                                    |   S - %s|                             }\n",iniciarGame);
              printf("\t{                                    |   I - %s|                             }\n",conhecer_a_gente);
              printf("\t{                                    |   M - %s|                             }\n",material_que_usamos);
              printf("\t{                                    |   C - %s|                             }\n",carregar_algum_cheat);
              printf("\t{                                    |   O - %s|                             }\n",ouvir_musicas_do_jogo);
              printf("\t{                                    |   X - %s|                             }\n",sair_string);
              printf("\t{                                    |_____________________________________|                             }\n");
              printf("\t{                                                                                                        }\n");
              printf("\t{                                                                                                        }\n");
              printf("\t{                                                                                                     ***}\n");
              printf("\t{________________________________________________________________________________________________________}\n");

              printf("\t                                      %s",escolha_uma_opcao);
              cin >> opcao;

              if(opcao == 's' )break;
              if(opcao == 'i' )break;
              if(opcao == 'x' )break;
              if(opcao == 'm' )break;
              if(opcao == 'c' )break;
              if(opcao == 'o' )break;
              if(opcao == 'a' )break;

          }
          while(opcao != 's' && opcao != 'i' && opcao != 'x' && opcao!= 'm' && opcao!= 'c' && opcao!= 'o');

  	system("cls");
	return opcao;
}

   //teclas pressionadas
   bool teclaCimaPressionada = false;
   bool teclaBaixoPressionada = false;
   bool teclaEsquerdaPressionada = false;
   bool teclaDireitaPressionada = false;

   void inicializaObjetos(){
        pilula.setImagemPilula();
        if(mudei_pra_bloco == false)tijolos.setImagemTijolos();
        if(mudei_pra_bloco == true)tijolos.setImagemBloco();
        if(mudei_pra_frutas == false)pilula.setImagemPilula();
        if(mudei_pra_frutas == true)pilula.setImagemFrutas();
        pacman.setImagem();

        if(cheat_sem_inimigo == false){
            inimigo.InimigoSetImagem();
            inimigoAzul.setImagem();
            inimigoRosa.setImagem();
            inimigoLaranja.setImagem();
        }
   }

ALLEGRO_BITMAP* pacImagem;
ALLEGRO_BITMAP* tijolosImagem;
ALLEGRO_BITMAP* pilulaImagem;
ALLEGRO_BITMAP* inimigoVermelhoImagem;
ALLEGRO_BITMAP* inimigoAzulImagem;
ALLEGRO_BITMAP* inimigoRosaImagem;
ALLEGRO_BITMAP* inimigoLaranjaImagem;
ALLEGRO_BITMAP* gameOverImagem;

  void checa_minhas_trapacas(){
        if(cheat_sem_inimigo == true){
            inimigo_vermelho = pilulas;
            inimigo_azul = pilulas;
            inimigo_rosa = pilulas;

            mapaJogo[1][1] = pilulas;
            mapaJogo[13][17] = pilulas;
            mapaJogo[1][17] = pilulas;
            mapaJogo[13][1] = pilulas;

            vitoria += 4;
        }
    }
void atualizaMapa(int posx,int posy, int posicao_x_inimigo, int posicao_y_inimigo, int posicao_x_inimigo_azul,
                  int posicao_y_inimigo_azul,int posicao_x_inimigo_rosa,int posicao_y_inimigo_rosa,
                  int posicao_x_inimigo_laranja,int posicao_y_inimigo_laranja)
{

    int i,j;

    for(i=0;i<15;i++)
        {
            for(j=0;j<19;j++)
           {
               if(mapaJogo[i][j]== parede) al_draw_bitmap(tijolosImagem,49 * j, 49 * i ,0);
               if(mapaJogo[i][j]== pilulas) al_draw_bitmap(pilulaImagem, 19 + 49 * j, 19 + 49 * i ,0);

               if(mapaJogo[i][j] == jogador)
               {

                if(teclaEsquerdaPressionada)
                    {
                        pacImagem = pacman.getImagemEsquerda();
                        teclaEsquerdaPressionada = false;
                    }
                if(teclaDireitaPressionada)
                    {
                        pacImagem = pacman.getImagemDireita();
                        teclaDireitaPressionada = false;
                    }
                if(teclaCimaPressionada)
                    {
                        pacImagem = pacman.getImagemCima();
                        teclaCimaPressionada = false;

                    }

                if(teclaBaixoPressionada)
                    {
                        pacImagem = pacman.getImagemBaixo();
                        teclaBaixoPressionada = false;
                    }

                   al_draw_bitmap(pacImagem, 49 * posx, posy * 49, 0);
               }


                if((mapaJogo[i][j] == inimigo_vermelho && pontos < vitoria)  && cheat_sem_inimigo == false)
                {
                    al_draw_bitmap(inimigoVermelhoImagem, 49 * posicao_x_inimigo, posicao_y_inimigo * 49, 0);
                } else if(mapaJogo[i][j] == inimigo_vermelho && pontos >= vitoria) al_draw_bitmap(pilulaImagem, 19 + 49 * j, 19 + 49 * i ,0);

                if(mapaJogo[i][j] == inimigo_azul && pontos < vitoria &&  cheat_sem_inimigo == false)
                {
                    al_draw_bitmap(inimigoAzulImagem, 49 * posicao_x_inimigo_azul, posicao_y_inimigo_azul * 49, 0);
                }else if(mapaJogo[i][j] == inimigo_azul && pontos >= vitoria) al_draw_bitmap(pilulaImagem, 19 + 49 * j, 19 + 49 * i ,0);

                if(mapaJogo[i][j] == inimigo_rosa && pontos < vitoria &&  cheat_sem_inimigo == false)
                {
                    al_draw_bitmap(inimigoRosaImagem, 49 * posicao_x_inimigo_rosa, posicao_y_inimigo_rosa * 49, 0);
                }else if(mapaJogo[i][j] == inimigo_rosa && pontos >= vitoria) al_draw_bitmap(pilulaImagem, 19 + 49 * j, 19 + 49 * i ,0);

                if(mapaJogo[i][j] == inimigo_laranja && pontos < vitoria &&  cheat_sem_inimigo == false)
                {
                    al_draw_bitmap(inimigoLaranjaImagem, 49 * posicao_x_inimigo_laranja, posicao_y_inimigo_laranja * 49, 0);
                }else if(mapaJogo[i][j] == inimigo_rosa && pontos >= vitoria) al_draw_bitmap(pilulaImagem, 19 + 49 * j, 19 + 49 * i ,0);
        }
    }
}
void checaColisaoInimigoAzul(int *randomAzul,int *randomAzul_antigo){
   srand(time(0));

    char orientacao;
    srand (time(NULL));

     if(*randomAzul == 0)orientacao = 'e';
     if(*randomAzul == 1)orientacao = 'd';
     if(*randomAzul == 2)orientacao = 'c';
     if(*randomAzul == 3)orientacao = 'b';

    if(orientacao == 'e'){
        if(mapaJogo[inimigoAzul.getPosY()][inimigoAzul.getPosX()-1] != parede)
        {
            if( (inimigoAzul.getPosY() == pacman.getPosY()) && (inimigoAzul.getPosX() == pacman.getPosX()))
            {
                      al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoAzul.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomAzul_antigo == *randomAzul){
                    *randomAzul = rand()%4;
            }
            *randomAzul_antigo = *randomAzul;
        }
    }

    if(orientacao == 'd'){
        if(mapaJogo[inimigoAzul.getPosY()][inimigoAzul.getPosX()+1] != parede)
        {
            if( (inimigoAzul.getPosY() == pacman.getPosY()) && (inimigoAzul.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoAzul.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomAzul_antigo == *randomAzul){
                    *randomAzul = rand()%4;
            }
            *randomAzul_antigo = *randomAzul;
        }
    }


    if(orientacao == 'c'){
        if(mapaJogo[inimigoAzul.getPosY()-1][inimigoAzul.getPosX()] != parede)
        {
            if( (inimigoAzul.getPosY() == pacman.getPosY()) && (inimigoAzul.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoAzul.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomAzul_antigo == *randomAzul){
                    *randomAzul = rand()%4;
            }
            *randomAzul_antigo = *randomAzul;
        }
    }

       if(orientacao == 'b'){
        if(mapaJogo[inimigoAzul.getPosY()+1][inimigoAzul.getPosX()] != parede)
        {
            if( (inimigoAzul.getPosY() == pacman.getPosY()) && (inimigoAzul.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoAzul.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomAzul_antigo == *randomAzul){
                    *randomAzul = rand()%4;
            }
            *randomAzul_antigo = *randomAzul;
        }
       }

}
void checaColisaoInimigoVermelho(){
    char orientacao;
    if(mapaJogo[inimigo.getPosy()][inimigo.getPosx()+1] != parede )
                {
                    if( (inimigo.getPosy() == pacman.getPosY()) && (inimigo.getPosx() == pacman.getPosX()))
                    {
                      al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
                    }
                    if(inimigo.getPosx() < pacman.getPosX()){
                        orientacao = 'd';
                        inimigo.movimenta(orientacao);
                    }

                }
                if(mapaJogo[inimigo.getPosy()][inimigo.getPosx()-1] != parede)
                {
                    if( (inimigo.getPosy() == pacman.getPosY()) && (inimigo.getPosx() == pacman.getPosX()))
                    {
                          al_draw_bitmap(gameOverImagem,170,100,0);
                          strcpy(situacao,"GAME OVER");
                          perdeu = true;
                          pausado = true;
                    }
                    if(inimigo.getPosx() > pacman.getPosX())
                       {
                           orientacao = 'e';
                            inimigo.movimenta(orientacao);
                       }

                }
                if(mapaJogo[inimigo.getPosy()+1][inimigo.getPosx()] != parede)
                {
                    if( (inimigo.getPosy() == pacman.getPosY()) && (inimigo.getPosx() == pacman.getPosX()))
                    {
                        al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
                    }
                    if(inimigo.getPosy() < pacman.getPosY()){
                        orientacao = 'b';
                        inimigo.movimenta(orientacao);
                    }
                }
                if(mapaJogo[inimigo.getPosy()-1][inimigo.getPosx()] != parede )
                {
                    if( (inimigo.getPosy() == pacman.getPosY()) && (inimigo.getPosx() == pacman.getPosX()))
                    {
                        al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
                    }
                    if(inimigo.getPosy() > pacman.getPosY())
                       {
                           orientacao = 'c';
                          inimigo.movimenta(orientacao);
                       }
                }
}
void checaColisaoRandomRosa(int *randomRosa,int *randomRosa_antiga){
    srand(time(0));

    char orientacao;
    srand (time(NULL));

     if(*randomRosa == 0)orientacao = 'e';
     if(*randomRosa == 1)orientacao = 'd';
     if(*randomRosa == 2)orientacao = 'c';
     if(*randomRosa == 3)orientacao = 'b';

    if(orientacao == 'e'){
        if(mapaJogo[inimigoRosa.getPosY()][inimigoRosa.getPosX()-1] != parede)
        {
            if( (inimigoRosa.getPosY() == pacman.getPosY()) && (inimigoRosa.getPosX() == pacman.getPosX()))
            {
                      al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoRosa.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomRosa_antiga == *randomRosa){
                    *randomRosa = rand()%4;
            }
            *randomRosa_antiga = *randomRosa;
        }
    }

    if(orientacao == 'd'){
        if(mapaJogo[inimigoRosa.getPosY()][inimigoRosa.getPosX()+1] != parede)
        {
            if( (inimigoRosa.getPosY() == pacman.getPosY()) && (inimigoRosa.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoRosa.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomRosa_antiga == *randomRosa){
                    *randomRosa = rand()%4;
            }
            *randomRosa_antiga = *randomRosa;
        }
    }


    if(orientacao == 'c'){
        if(mapaJogo[inimigoRosa.getPosY()-1][inimigoRosa.getPosX()] != parede)
        {
            if( (inimigoRosa.getPosY() == pacman.getPosY()) && (inimigoRosa.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoRosa.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomRosa_antiga == *randomRosa){
                    *randomRosa = rand()%4;
            }
            *randomRosa_antiga = *randomRosa;
        }
    }

       if(orientacao == 'b'){
        if(mapaJogo[inimigoRosa.getPosY()+1][inimigoRosa.getPosX()] != parede)
        {
            if( (inimigoRosa.getPosY() == pacman.getPosY()) && (inimigoRosa.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoRosa.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomRosa_antiga == *randomRosa){
                    *randomRosa = rand()%4;
            }
            *randomRosa_antiga = *randomRosa;
        }
       }
}
void checaColisaoRandomLaranja(int *randomLaranja,int *randomLaranja_antiga){
    srand(time(0));

    char orientacao;
    srand (time(NULL));

     if(*randomLaranja == 0)orientacao = 'e';
     if(*randomLaranja == 1)orientacao = 'd';
     if(*randomLaranja == 2)orientacao = 'c';
     if(*randomLaranja == 3)orientacao = 'b';

    if(orientacao == 'e'){
        if(mapaJogo[inimigoLaranja.getPosY()][inimigoLaranja.getPosX()-1] != parede)
        {
            if( (inimigoLaranja.getPosY() == pacman.getPosY()) && (inimigoLaranja.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoLaranja.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomLaranja_antiga == *randomLaranja){
                    *randomLaranja = rand()%4;
            }
            *randomLaranja_antiga = *randomLaranja;
        }
    }

    if(orientacao == 'd'){
        if(mapaJogo[inimigoLaranja.getPosY()][inimigoLaranja.getPosX()+1] != parede)
        {
            if( (inimigoLaranja.getPosY() == pacman.getPosY()) && (inimigoLaranja.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoLaranja.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomLaranja_antiga == *randomLaranja){
                    *randomLaranja = rand()%4;
            }
            *randomLaranja_antiga = *randomLaranja;
        }
    }


    if(orientacao == 'c'){
        if(mapaJogo[inimigoLaranja.getPosY()-1][inimigoLaranja.getPosX()] != parede)
        {
            if( (inimigoLaranja.getPosY() == pacman.getPosY()) && (inimigoLaranja.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoLaranja.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomLaranja_antiga == *randomLaranja){
                    *randomLaranja = rand()%4;
            }
            *randomLaranja_antiga = *randomLaranja;
        }
    }

       if(orientacao == 'b'){
        if(mapaJogo[inimigoLaranja.getPosY()+1][inimigoLaranja.getPosX()] != parede)
        {
            if( (inimigoLaranja.getPosY() == pacman.getPosY()) && (inimigoLaranja.getPosX() == pacman.getPosX()))
            {
                al_draw_bitmap(gameOverImagem,170,100,0);
                      strcpy(situacao,"GAME OVER");
                      perdeu = true;
                      pausado = true;
            }
            else inimigoLaranja.movimenta(orientacao);
        }
        //batemos na parede
        else {
        //forcar randomRosa obter um valor diferente do anterior
            while(*randomLaranja_antiga == *randomLaranja){
                    *randomLaranja = rand()%4;
            }
            *randomLaranja_antiga = *randomLaranja;
        }
       }
}
void checaColisaoPacman(char orientacao){
    if(orientacao == 'd'){
        if(mapaJogo[pacman.getPosY()][pacman.getPosX() + 1] != parede)
        {
            teclaDireitaPressionada = true;
            pacman.movimenta(orientacao);
        }
        else{ pacImagem = pacman.getImagemFrente();}

        //pilulas
        if(mapaJogo[pacman.getPosY()][pacman.getPosX()] == pilulas)
        {
            pontos++;
            mapaJogo[pacman.getPosY()][pacman.getPosX()] = jogador;
            al_play_sample(pacmanComendoPilula, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        }
    }
    if(orientacao == 'e'){
      if(mapaJogo[pacman.getPosY()][pacman.getPosX() - 1] != parede)
        {
            teclaEsquerdaPressionada = true;
            pacman.movimenta(orientacao);
        }
      else {teclaEsquerdaPressionada = false;pacImagem = pacman.getImagemFrente();}
        //pilulas
      if(mapaJogo[pacman.getPosY()][pacman.getPosX()] == pilulas)
      {
        pontos++;
        mapaJogo[pacman.getPosY()][pacman.getPosX()] = jogador;
        al_play_sample(pacmanComendoPilula, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
      }
    }
    if(orientacao == 'c'){
        if(mapaJogo[pacman.getPosY()-1][pacman.getPosX()] != parede)
        {
          teclaCimaPressionada = true;
          pacman.movimenta(orientacao);
        }
        else{teclaCimaPressionada = false;pacImagem = pacman.getImagemFrente();}
            //pilulas
            if(mapaJogo[pacman.getPosY()][pacman.getPosX()] == pilulas)
            {
               pontos++;
               mapaJogo[pacman.getPosY()][pacman.getPosX()] = jogador;
               al_play_sample(pacmanComendoPilula, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            }
        }
    if(orientacao == 'b'){
        if(mapaJogo[pacman.getPosY()+1][pacman.getPosX()] != parede)
        {
            teclaBaixoPressionada = true;
            pacman.movimenta(orientacao);
        }
        else {teclaBaixoPressionada = false;pacImagem = pacman.getImagemFrente();}
            //pilulas
        if(mapaJogo[pacman.getPosY()][pacman.getPosX()] == pilulas)
        {
            pontos++;
            mapaJogo[pacman.getPosY()][pacman.getPosX()] = jogador;
            al_play_sample(pacmanComendoPilula, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        }
    }

}

void checaPontuacao(){
    if(pontos == vitoria) {
        strcpy(situacao,"VENCEU!!");
        al_play_sample(aplausos, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);//135
        inimigo_vermelho = pilulas;
        inimigo_azul = pilulas;
        inimigo_rosa = pilulas;
        inimigo_laranja = pilulas;
        vitoria = -1;
    }
}
void comecarJogo(){

    gameOverImagem = al_load_bitmap("../imagensJogo/gameover.png");
    testaComponentes(gameOverImagem,"pacman.png");

    ALLEGRO_DISPLAY *display = al_create_display(largura,altura);
    al_set_window_title(display,"PACMAN-ELIEZER-CAMILLE");
    ALLEGRO_FONT *font = al_create_builtin_font();

    ALLEGRO_TIMER *timer = al_create_timer(2.0/10.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

    testaComponentes(al_install_audio(), "audio");
    testaComponentes(al_init_acodec_addon(), "audio codecs");
    testaComponentes(al_reserve_samples(16), "reserve samples");

    pacmanComendoPilula = al_load_sample("../musicasJogo/pacman_chomp.wav");
    testaComponentes(pacmanComendoPilula, "pacman_eatfruit");
    ALLEGRO_AUDIO_STREAM* music = al_load_audio_stream("../musicasJogo/pacman_sound.mp3", 2, 2048);
    testaComponentes(music, "music");
    aplausos = al_load_sample("../musicasJogo/aplausos.wav");
    testaComponentes(aplausos, "aplausos");

    al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_ONCE);
    al_attach_audio_stream_to_mixer(music, al_get_default_mixer());

    inicializaObjetos();
                pacImagem = pacman.getImagemFrente();
                tijolosImagem = tijolos.getImagemTijolos();
                pilulaImagem = pilula.getImagemPilula();
                inimigoVermelhoImagem = inimigo.getImagemInimigo();
                inimigoAzulImagem = inimigoAzul.getImagem();
                inimigoRosaImagem = inimigoRosa.getImagem();
                inimigoLaranjaImagem = inimigoLaranja.getImagem();

    testaComponentes(timer,"timer");
    testaComponentes(queue,"fila de eventos");
    testaComponentes(font,"fonte");

    al_register_event_source(queue,al_get_keyboard_event_source());
    al_register_event_source(queue,al_get_display_event_source(display));
    al_register_event_source(queue,al_get_timer_event_source(timer));

    bool done = false;
    bool renderiza = true;
    ALLEGRO_EVENT evento;

    al_start_timer(timer);
    checa_minhas_trapacas();

    //mapa();

    #define KEY_SEEN     1
    #define KEY_RELEASED 2

    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));

    srand(time(0));
    int randomRosa = rand()%4;
    int randomRosa_antiga = randomRosa;

    int randomLaranja = rand()%4;
    int randomLaranja_antiga = randomLaranja;
    srand (time(NULL));

    int randomAzul = rand()%4;
    int randomAzul_antigo = randomAzul;
    srand (time(NULL));

    al_start_timer(timer);

    char avancar;

       while(!key[ALLEGRO_KEY_ESCAPE]){

        al_wait_for_event(queue,&evento);

        switch(evento.type)
        {
            case ALLEGRO_EVENT_TIMER:

                if(key[ALLEGRO_KEY_UP]) avancar = 'c';
                if(key[ALLEGRO_KEY_DOWN]) avancar = 'b';
                if(key[ALLEGRO_KEY_LEFT]) avancar = 'e';
                if(key[ALLEGRO_KEY_RIGHT]) avancar = 'd';
                if(key[ALLEGRO_KEY_ESCAPE]) done = true;
                if(key[ALLEGRO_KEY_SPACE] && pausado == false) pausado = true;
                if(key[ALLEGRO_KEY_1] && pausado == true) {pausado = false; perdeu = false;}

                for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                    key[i] &= KEY_SEEN;

                renderiza = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                key[evento.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
                break;
            case ALLEGRO_EVENT_KEY_UP:
                key[evento.keyboard.keycode] &= KEY_RELEASED;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(renderiza && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_textf(font, al_map_rgb(255, 255, 255), 950, 100, 0, "  %s",pontuacao_text);
            al_draw_textf(font, al_map_rgb(255, 255, 255), 950, 120, 0, "--%s: %d--", pontos_text,pontos);
            al_draw_textf(font, al_map_rgb(255, 255, 255), 950, 140, 0, "--%s--", situacao);

            atualizaMapa(pacman.getPosX(),pacman.getPosY(),inimigo.getPosx(),inimigo.getPosy(),
                         inimigoAzul.getPosX(),inimigoAzul.getPosY(),inimigoRosa.getPosX(),inimigoRosa.getPosY(),
                         inimigoLaranja.getPosX(),inimigoLaranja.getPosY());

        if(pausado == false){
            if(cheat_sem_inimigo == false && vitoria != -1){//pra mostrar batidas do inimigo, devo ter inimigos no jogo e nao devo ter vencido ainda

                //controlando inimigo vermelho
                checaColisaoInimigoVermelho();

                //controlando inimigo azul
                checaColisaoInimigoAzul(&randomAzul,&randomAzul_antigo);

                //controlando inimigo rosa
                checaColisaoRandomRosa(&randomRosa,&randomRosa_antiga);

                //controlando inimigo laranja
                checaColisaoRandomLaranja(&randomLaranja,&randomLaranja_antiga);
            }

            //controla pacman
            checaColisaoPacman(avancar);

            //checa pontuacao
            checaPontuacao();
            }

            if(perdeu == true){
                al_draw_bitmap(gameOverImagem,170,100,0);
            }

            al_flip_display();
            renderiza = false;
        }
    }


    al_destroy_bitmap(tijolosImagem);
    al_destroy_bitmap(pilulaImagem);
    al_destroy_bitmap(pacImagem);
    al_destroy_bitmap(inimigoLaranjaImagem);
    al_destroy_bitmap(inimigoRosaImagem);
    al_destroy_bitmap(inimigoVermelhoImagem);
    al_destroy_bitmap(gameOverImagem);
    al_destroy_display(display);
    al_destroy_font(font);
    al_destroy_audio_stream(music);
    al_destroy_event_queue(queue);
    al_destroy_sample(pacmanComendoPilula);

}
void menuDeOpcoes(){
    char opcaoEscolhidaPeloPlayer;
    int musicaEscolhida;

     do{
    	opcaoEscolhidaPeloPlayer = menuInicial();

		  if(opcaoEscolhidaPeloPlayer == 's')
		  {
              al_play_sample(opcao_selecionada, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
              al_destroy_audio_stream(music);
              //meuMenuDeLoading();
              comecarJogo();

		  }

		  if(opcaoEscolhidaPeloPlayer == 'i')
		  {
            al_play_sample(opcao_selecionada, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		  	apresentacao();
		  	printf("\n\n\t %s",pressione_enter_pra_voltar);
		  	//system("pause");
			getchar();

		  }

		  if(opcaoEscolhidaPeloPlayer == 'x'){
		  	exit(1);
		  }
		  if(opcaoEscolhidaPeloPlayer == 'm'){
		      al_play_sample(opcao_selecionada, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            printf("                            %s",nossos_creditos_a);
            printf("\n\n    %s https://images.app.goo.gl/927BFS9wQdrvDidAA",imagem_do_pacman);
            printf("\n\n    %s https://www.youtube.com/watch?v=SP0RCMtfm4o&ab_channel=AlecKoff",musica_do_menu);
            printf("\n\n    %s https://www.classicgaming.cc/classics/pac-man/sounds",sons_do_pacman);
            printf("\n\n    %s Music by <a href=/users/666herohero-25759907/?tab=audio&amp;utm_source=link-attribution&amp;utm_medium=referral&amp;utm_campaign=audio&amp;utm_content=21834>666HeroHero</a> from <a href=https://pixabay.com/?utm_source=link-attribution&amp;utm_medium=referral&amp;utm_campaign=music&amp;utm_content=21834>Pixabay</a>",som_do_clique);
            printf("\n\n    %s Music from <a href=https://pixabay.com/music/?utm_source=link-attribution&amp;utm_medium=referral&amp;utm_campaign=music&amp;utm_content=34979>Pixabay</a>",som_de_carregando);

            printf("\n\n\n\n\n                        ");
		  	system("pause");


		  }

		  if(opcaoEscolhidaPeloPlayer == 'c'){
            al_play_sample(opcao_selecionada, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

            printf("                            %s",digite_o_cheat);
            cin >> cheat;

            if(cheat[0] == 'e' && cheat[1] == 'l' && cheat [2] == 'i' && cheat[3] == 'e' && cheat[4] == 'z' && cheat[5] == 'e' && cheat[6] == 'r'){
                cout << cheat_ativado; cheat_sem_inimigo = true;
            }
            if(cheat[0] == 'c' && cheat[1] == 'a' && cheat[2] == 'm' && cheat[3] == 'i' && cheat[4] == 'l' && cheat[5] == 'l' && cheat[6] == 'e'){
                cout << cheat_ativado; cheat_sem_inimigo = true;
            }
            if(cheat[0] == 'b' && cheat[1] == 'l' && cheat[2] == 'o' && cheat[3] == 'c' && cheat[4] == 'o'){
                cout << cheat_ativado; mudei_pra_bloco = true;
            }
            if(cheat[0] == 'f' && cheat[1] == 'r' && cheat[2] == 'u' && cheat[3] == 't' && cheat[4] == 'a' && cheat[5] == 's'){
                cout << cheat_ativado; mudei_pra_frutas = true;
            }

            printf("\n\n\n\n                        ");
		  	system("pause");
			getchar();

		  }
		  if(opcaoEscolhidaPeloPlayer == 'o'){
            al_play_sample(opcao_selecionada, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
             printf("\n\n\n\n\t ________________________________________________________________________________________________________\n");
              printf("\t{                                                                                                        }\n");
              printf("\t{***                                  _____________________________________                              }\n");
              printf("\t{                                       1 - LEAGUE_OF_LEGENDS_MENU.mp3                                   }\n");
              printf("\t{                                       2 - NIGHT_IN_DETROIT.mp3                                         }\n");
              printf("\t{                                       3 - SUSPENSE_SOUND.mp3                                           }\n");
              printf("\t{                                      _____________________________________                             }\n");
              printf("\t{                                                                                                        }\n");
              printf("\t{                                                                                                        }\n");
              printf("\t{                                                                                                     ***}\n");
              printf("\t{________________________________________________________________________________________________________}\n");

              printf("                                                 %s",escolha_uma_opcao);
              cin >> musicaEscolhida;
              if(musicaEscolhida == 1){
                    al_destroy_audio_stream(music);
                    music = al_load_audio_stream("../musicasJogo/som1.mp3", 2, 2048);
                    testaComponentes(music, "music");
                    al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
                    al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
              }
              if(musicaEscolhida == 2){
                    al_destroy_audio_stream(music);
                    music = al_load_audio_stream("../musicasJogo/night_in_detroit.mp3", 2, 2048);
                    testaComponentes(music, "music");
                    al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
                    al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
              }
              if(musicaEscolhida == 3){
                    al_destroy_audio_stream(music);
                    music = al_load_audio_stream("../musicasJogo/suspense_sound_free.mp3", 2, 2048);
                    testaComponentes(music, "music");
                    al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
                    al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
              }

               printf("\n\n\n\n                       ");
                system("pause");
			 getchar();

		  }
		  al_play_sample(opcao_selecionada, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	}while(opcaoEscolhidaPeloPlayer != 's');

}
void meuMenuDeLoading()
{
    testaComponentes(al_init(),"allegro completo");

    testaComponentes(al_install_audio(), "audio");
    testaComponentes(al_init_acodec_addon(), "audio codecs");
    testaComponentes(al_reserve_samples(16), "reserve samples");

    ALLEGRO_AUDIO_STREAM* music = al_load_audio_stream("../musicasJogo/night_in_detroit.mp3", 2, 2048);
    testaComponentes(music, "night_in_detroit.mp3");
    al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
    al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
int i;
    system("cls");

        for(i=0;i<17;i++)
        {

            printf("\n\n\n");

            printf("\t\t\t\t\t---------------- %s PACMAN..... ",carregando_string);
            system("cls");

            printf("\n\n\n");

            printf("\t\t\t\t\t---------------- %s PACMAN.... ",carregando_string);
            system("cls");


            printf("\n\n\n");

            printf("\t\t\t\t\t---------------- %s PACMAN... ",carregando_string);
            system("cls");
            //printf("\n\n\t\t\t\t\t---------------------------------------");

           printf("\n\n\n");
                    printf("\t\t\t\t\t---------------- PACMAN %s.. ",carregando_string);
                    system("cls");

           printf("\n\n\n");
                    printf("\t\t\t\t\t---------------- PACMAN %s. ",carregando_string);
                    system("cls");

        }
        al_destroy_audio_stream(music);

}

int main(){

    testaComponentes(al_init(),"allegro completo");
    testaComponentes(al_install_keyboard(),"instalacao do teclado");
    testaComponentes(al_init_image_addon(),"instalacao pra rodar imagem addon");

    testaComponentes(al_install_audio(), "audio");
    testaComponentes(al_init_acodec_addon(), "audio codecs");
    testaComponentes(al_reserve_samples(16), "reserve samples");

    music = al_load_audio_stream("../musicasJogo/som1.mp3", 2, 2048);
    testaComponentes(music, "music");
    al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
    al_attach_audio_stream_to_mixer(music, al_get_default_mixer());

    opcao_selecionada = al_load_sample("../musicasJogo/slash.mp3");
    testaComponentes(opcao_selecionada, "opcao_selecionada.mp3");

    mapa();
    char idioma;

    do{
            system("cls");
                printf("\n\n\n\n\n                                              %s                \n",idioma_text);
                printf("                                                      1- ENGLISH                \n");
                printf("                                                      2- PORTUGUES                \n\n\n\n\n\n");

                cin >> idioma;
            }while(idioma != '1' && idioma != '2');
            system("pause");
            mudaIdioma(idioma);


   menuDeOpcoes();


   return 0;
}
