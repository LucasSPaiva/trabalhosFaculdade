/*Um quiz sobre variados temas, que contem 20 questoes
  e pode ser jogado por até 4 pessoas

  Integrantes:
      Caio Cesar
      Jean Martins
      Lucas Paiva
      Ulysses Ferreira
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include "Graphics.h"
#include "biblioteca.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    pergunta p[21];
    pilha baralho1, baralho2, baralho3, baralho4, baralho5;
    lista jogadores;
    struct jogador *aux;
    int i, e, r, x[21], cont_perguntas=0, cont_rodadas=0, n_jogadores, barra = 251;
    char intToString[8];

    criaMenu();
    n_jogadores = selecionaJogadores();
    cleardevice();
    closegraph();


    initwindow(1000, 800, "Carregando...");
    dica(n_jogadores);

    for (i=0;i<=20;i++)
    {
        p[i] = geraPerguntas(i);
        x[i] = 0;
    }
    criaLista(&jogadores);
    geraJogadores(&jogadores, n_jogadores);
    criaPilha(&baralho1);
    criaPilha(&baralho2);
    criaPilha(&baralho3);
    criaPilha(&baralho4);
    criaPilha(&baralho5);

    while(cont_perguntas != 20)
    {
        do
        {
            e = numeroAleatorio(21, x);
        }while (e == 0);

        switch(p[e].tema)
        {
            case 1:
                addPilha(&baralho1, p[e]);
                break;
            case 2:
                addPilha(&baralho2, p[e]);
                break;
            case 3:
                addPilha(&baralho3, p[e]);
                break;
            case 4:
                addPilha(&baralho4, p[e]);
                break;
            case 5:
                addPilha(&baralho5, p[e]);
                break;
        }
        x[cont_perguntas] = e;
        cont_perguntas++;

        setlinestyle(0,2,2);
        setcolor(DARKGRAY);
        rectangle(250, 325, 792, 375);
        settextstyle(1, 0, 2);
        outtextxy(250,300, "Carregando...");
        outtextxy(250,400, "Aguarde...");
        setfillstyle(5, LIGHTGRAY);
        bar(251, 326, barra=barra+27, 374);

    }
        outtextxy(250,400, "Pressione alguma tecla para prosseguir");
        getch();
        cleardevice();
        closegraph();
        aux = jogadores.inicio;

    while (cont_rodadas != 20)
    {
        initwindow(1000, 800, "Quiz");


        if (aux->dados_jog.especial == 1){
            r = turnoEspecial(&baralho1, &baralho2, &baralho3, &baralho4, &baralho5, jogadores, n_jogadores);
            aux->dados_jog.especial = 0;
        }
        else if ((cont_rodadas == 3) || (cont_rodadas == 6) || (cont_rodadas == 9) || (cont_rodadas == 12)){
            setcolor(11);
            outtextxy(50, 155, "VALENDO BONUS");
            blocoJogador(jogadores, n_jogadores);
            r = mostraPergunta(&baralho1, &baralho2, &baralho3, &baralho4, &baralho5);
            setcolor(15);
            if (r == 1) aux->dados_jog.especial = 1;
        }
        else {
            blocoJogador(jogadores, n_jogadores);
            r = mostraPergunta(&baralho1, &baralho2, &baralho3, &baralho4, &baralho5);
        }

        verificaResposta(r);
        Sleep(1000);
        if (r == 1) aux->dados_jog.pontuacao++;

        aux->dados_jog.vez = 0;
        aux = aux->prox;
        aux->dados_jog.vez = 1;
        cont_rodadas++;

        cleardevice();
        closegraph();
    }
    initwindow(1000, 800, "Placar final.");
    mostraVencedor(jogadores, n_jogadores);
    getchar();

    return (0);
}
