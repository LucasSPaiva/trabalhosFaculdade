#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "Graphics.h"
#include "biblioteca.h"

//          PILHA
void criaPilha(pilha *p){
    p->topo=NULL;
}

int addPilha(pilha *p, pergunta per) {
    struct carta *aux;
    aux = (struct carta*)malloc(sizeof(struct carta));
    if(aux == NULL) return 0;

    aux->per = per;
    aux->prox = p->topo;
    p->topo = aux;
    //printf("\nempilhou pergunta: %s", aux->per.pergunta);
    return 1;
}

int removePilha(pilha *p){
	struct carta *aux;
    if (p->topo==NULL) return 0;
	aux = p->topo;
    p->topo = (p->topo)->prox;
    // *d = aux->dado; para retornar o dado do nó que vai remover colocar um ponteiro do tipo do nó como argumento
	free(aux);
	return 1;
}

//           LISTA
void criaLista(lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

int addLista(lista *l, jog jogador) {
    struct jogador *aux;
    aux = (struct jogador*)malloc(sizeof(struct jogador));
    if (aux == NULL) return 0;

    aux->dados_jog = jogador;
    if (l->inicio == NULL) {
        l->inicio = aux;
        l->fim = aux;
        aux->prox = l->inicio;
        return 1;
    } else {
        aux->prox = l->inicio;
        l->fim->prox = aux;
        l->fim = aux;
        return 1;
    }
}

//           PERGUNTAS
pergunta geraPerguntas(int i){
    pergunta p;

    if(i==1) {
        strcpy(p.pergunta, "Sem calculadora, divida 60 por meio e some 20. Qual o resultado?");
        strcpy(p.op1, "40");
        strcpy(p.op2, "50");
        strcpy(p.op3, "100");
        strcpy(p.op4, "140");
        p.resposta = 4;
        p.tema = 1;
    }

    if(i==2) {
        strcpy(p.pergunta, "Dentre os itens abaixo, qual aquele que pode ser considerado um intruso?");
        strcpy(p.op1, "Vaca");
        strcpy(p.op2, "Gato");
        strcpy(p.op3, "Leao");
        strcpy(p.op4, "Lobo Guara");
        p.resposta = 1;
        p.tema = 1;
    }

    if(i==3) {
        strcpy(p.pergunta, "Num aviao ha 4 romanos e 1 ingles, qual o nome da aeromoca?");
        strcpy(p.op1, "Maria");
        strcpy(p.op2, "Leticia");
        strcpy(p.op3, "Luiza");
        strcpy(p.op4, "Ivone");
        p.resposta = 4;
        p.tema = 1;
    }

    if(i==4) {
        strcpy(p.pergunta, "Complete a sequencia: 2, 3, 4, 11, 12, 13, 17, 18...(?)");
        strcpy(p.op1, "24");
        strcpy(p.op2, "20");
        strcpy(p.op3, "19");
        strcpy(p.op4, "30");
        p.resposta = 3;
        p.tema = 1;
    }

    if(i==5) {
        strcpy(p.pergunta, "Na Segunda Guerra Mundial, quais dos paises abaixo faziam parte dos Aliados?");
        strcpy(p.op1, "Italia, Estados Unidos e Uniao Sovietica");
        strcpy(p.op2, "Franca, Uniao Sovietica e Gra Bretanha");
        strcpy(p.op3, "Japao, Franca e Estados Unidos");
        strcpy(p.op4, "Uniao Sovietica, Gra Bretanha e Italia");
        p.resposta = 2;
        p.tema = 2;
    }

    if(i==6) {
        strcpy(p.pergunta, "No Brasil, qual era o nome do documento que oficializava a liberdade de um escravo?");
        strcpy(p.op1, "Carta de alforria");
        strcpy(p.op2, "Carta de liberdade");
        strcpy(p.op3, "Carta aurea");
        strcpy(p.op4, "Carta de abolicao");
        p.resposta = 1;
        p.tema = 2;
    }

    if(i==7) {
        strcpy(p.pergunta, "O Domingo Sangrento foi um acontecimento de qual contexto historico?");
        strcpy(p.op1, "Revolucao Francesa");
        strcpy(p.op2, "Primeira Guerra Mundial");
        strcpy(p.op3, "Revolucao Russa");
        strcpy(p.op4, "Guerra do vietna");
        p.resposta = 3;
        p.tema = 2;
    }

    if(i==8) {
        strcpy(p.pergunta, "Em que periodo da pre historia  o fogo foi descoberto?");
        strcpy(p.op1, "Neolitico");
        strcpy(p.op2, "Paleolitico");
        strcpy(p.op3, "Idade dos metais");
        strcpy(p.op4, "Idade media");
        p.resposta = 1;
        p.tema = 2;
    }

    if(i==9) {
        strcpy(p.pergunta, "Qual das opcoes nao e um inseto?");
        strcpy(p.op1, "Pulga");
        strcpy(p.op2, "Carrapato");
        strcpy(p.op3, "Barata");
        strcpy(p.op4, "Piolho");
        p.resposta = 2;
        p.tema = 3;
    }

    if(i==10) {
        strcpy(p.pergunta, "Qual das opcoes e um nematelminto?");
        strcpy(p.op1, "Minhoca");
        strcpy(p.op2, "Sanguessuga");
        strcpy(p.op3, "Lombriga");
        strcpy(p.op4, "Plenaria");
        p.resposta = 3;
        p.tema = 3;
    }

    if(i==11) {
        strcpy(p.pergunta, "O osso mais longo e mais volumoso do corpo humano e o:");
        strcpy(p.op1, "Martelo");
        strcpy(p.op2, "Femur");
        strcpy(p.op3, "Metacarpo");
        strcpy(p.op4, "Esterno");
        p.resposta = 2;
        p.tema = 3;
    }

    if(i==12) {
        strcpy(p.pergunta, "Qual desses orgaos nao faz parte do sistema respiratorio humano?");
        strcpy(p.op1, "Laringe");
        strcpy(p.op2, "Traqueia");
        strcpy(p.op3, "Diafragma");
        strcpy(p.op4, "Esofago");
        p.resposta = 4;
        p.tema = 3;
    }

    if(i==13) {
        strcpy(p.pergunta, "Depois da biblia, qual foi o livro mais vendido da historia?");
        strcpy(p.op1, "Dom Quixote");
        strcpy(p.op2, "O Pequeno Principe");
        strcpy(p.op3, "Harry Potter");
        strcpy(p.op4, "Alice no Pais das Maravilhas");
        p.resposta = 1;
        p.tema = 4;
    }

    if(i==14) {
        strcpy(p.pergunta, "Qual dessas foi considerada a primeira obra de ficcao cientifica?");
        strcpy(p.op1, "Laranja Mecanica");
        strcpy(p.op2, "Frankenstein ou O Prometeu Moderno");
        strcpy(p.op3, "Viagem ao Centro da Terra");
        strcpy(p.op4, "O Chamado de Cthulhu");
        p.resposta = 2;
        p.tema = 4;
    }

    if(i==15) {
        strcpy(p.pergunta, "Quem compos a Sinfonia n. 9?");
        strcpy(p.op1, "Mozart");
        strcpy(p.op2, "Chopin");
        strcpy(p.op3, "Beethoven");
        strcpy(p.op4, "Bach");
        p.resposta = 3;
        p.tema = 4;
    }

    if(i==16) {
        strcpy(p.pergunta, "Qual desses filmes brasileiros nao foi indicado ao Oscar?");
        strcpy(p.op1, "O Menino e o Mundo");
        strcpy(p.op2, "Cidade de Deus");
        strcpy(p.op3, "Central do Brasil");
        strcpy(p.op4, "Carandiru");
        p.resposta = 4;
        p.tema = 4;
    }

    if(i==17) {
        strcpy(p.pergunta, "Segundo a biblia, quantos animais, de cada especie, moises colocou em sua arca?");
        strcpy(p.op1, "0");
        strcpy(p.op2, "1");
        strcpy(p.op3, "2");
        strcpy(p.op4, "3");
        p.resposta = 1;
        p.tema = 5;
    }

    if(i==18) {
        strcpy(p.pergunta, "Qual desses nao e um xote do falamansa?");
        strcpy(p.op1, "Xote dos Milagres");
        strcpy(p.op2, "Xote Carinhoso");
        strcpy(p.op3, "Xote da Alegria");
        strcpy(p.op4, "Xote universitario");
        p.resposta = 2;
        p.tema = 5;
    }

    if(i==19) {
        strcpy(p.pergunta, "Qual desses paises nao faz fronteira com o Brasil?");
        strcpy(p.op1, "Venezuela");
        strcpy(p.op2, "Colombia");
        strcpy(p.op3, "Equador");
        strcpy(p.op4, "Peru");
        p.resposta = 3;
        p.tema = 5;
    }

    if(i==20) {
        strcpy(p.pergunta, "Dos seguintes sintomas, qual deles nao e comum para o coronavirus?");
        strcpy(p.op1, "Falta de ar");
        strcpy(p.op2, "Dor de garganta");
        strcpy(p.op3, "Febre");
        strcpy(p.op4, "Coriza");
        p.resposta = 4;
        p.tema = 5;
    }
    return p;
}

int numeroAleatorio(int f, int *x) {
    int e, i;
    srand(time(NULL));
    e = rand()%f;

    for (i=0;i<20;i++) {
        if (*x == e) return 0;
        x++;
    }
    return e;
}

int baralhoAleatorio(int f) {
    int e;
    srand(time(NULL));
    e = (rand()%f) + 1;
    return e;
}

int mostraPergunta(pilha *b1, pilha *b2, pilha *b3, pilha *b4, pilha *b5) {
    struct carta *aux;
    int e, r;

    //pega uma pergunta de um tema aleatório, se tiver acabado, pula pro próximo
    e = baralhoAleatorio(5);
    rectangle(40 , 145, 960, 195);
    settextstyle(4, 0, 4);
    outtextxy(250, 155, "Tema");

    switch (e){
        case 1:
            if(b1->topo != NULL) {
                aux = b1->topo;
                outtextxy(400, 155,"Logica");
                break;
            } else e++;
        case 2:
            if(b2->topo != NULL) {
                outtextxy(400, 155,"Historia");
                aux = b2->topo;
                break;
            } else e++;
        case 3:
            if(b3->topo != NULL) {
                outtextxy(400, 155,"Biologia");
                aux = b3->topo;
                break;
            } else e++;
        case 4:
            if(b4->topo != NULL) {
                outtextxy(400, 155,"Artes");
                aux = b4->topo;
                break;
            } else e++;
        case 5:
            if(b5->topo != NULL){
                outtextxy(400, 155,"Conhecimentos Gerais");
                aux = b5->topo;
                break;
            } else if(b1->topo != NULL) {
                outtextxy(400, 155,"Logica");
                aux = b1->topo;
                e = 1;
                break;
            } else if(b2->topo != NULL) {
                outtextxy(400, 155,"Historia");
                aux = b2->topo;
                e = 2;
                break;
            } else if(b3->topo != NULL) {
                outtextxy(400, 155,"Biologia");
                aux = b3->topo;
                e = 3;
                break;
            } else if(b4->topo != NULL) {
                outtextxy(400, 155,"Artes");
                aux = b4->topo;
                e = 4;
                break;
            }
    }

    rectangle(40, 185, 960, 360);
    settextstyle(0,0,0);
    outtextxy(50, 255, aux->per.pergunta);
    outtextxy(50, 415, aux->per.op1);
    outtextxy(50, 485, aux->per.op2);
    outtextxy(50, 555, aux->per.op3);
    outtextxy(50, 625, aux->per.op4);

    r = passandoMouse();
    setlinestyle(0,0,0);
    setcolor(15);
    clearmouseclick(WM_LBUTTONDOWN);


    if (r == aux->per.resposta) r = 1;
    else r = 0;
        switch (e){
        case 1:
            removePilha(b1);
            break;
        case 2:
            removePilha(b2);
            break;
        case 3:
            removePilha(b3);
            break;
        case 4:
            removePilha(b4);
            break;
        case 5:
            removePilha(b5);
            break;
    }

    cleardevice();
    return r;
}

int turnoEspecial(pilha *b1, pilha *b2, pilha *b3, pilha *b4, pilha *b5, lista l, int quantidadePlayers){
    struct carta *aux1;
    int e, r, controle=0;
    struct jogador *aux;
    char intToString[8];
    int rtgJogador[8];
    int i, x=0;
    aux = l.inicio;

    initwindow(1000,800, "Quiz");
    do {
        e = passandoMouse2();

        switch (e){
            case 1:
                if(b1->topo != NULL) {
                    aux1 = b1->topo;
                    controle = 1;
                }
                else acabouTema();
                break;
            case 2:
                if(b2->topo != NULL) {
                    aux1 = b2->topo;
                    controle = 1;
                }
                else acabouTema();
                break;
            case 3:
                if(b3->topo != NULL) {
                    aux1 = b3->topo;
                    controle = 1;
                }
                else acabouTema();
                break;
            case 4:
                if(b4->topo != NULL) {
                    aux1 = b4->topo;
                    controle = 1;
                }
                else acabouTema();
                break;
            case 5:
                if(b5->topo != NULL) {
                    aux1 = b5->topo;
                    controle = 1;
                }
                else acabouTema();
                break;
        }
    } while(controle == 0);


    cleardevice();
    clearmouseclick(WM_LBUTTONDOWN);
    Sleep(100);
    closegraph();
    initwindow(1000, 800, "Quiz");
    setlinestyle(0,0,3);
    settextstyle(0,0,0);


    for(i=0; i < quantidadePlayers; i++){

        if( aux->dados_jog.vez == 1){
            setlinestyle(0,0,6);
            rtgJogador[0] = 40 + x; // o if faz um retangulo preenchido para indicar
            rtgJogador[1] = 30;     // de quem é a vez
            rtgJogador[2] = 240 + x;
            rtgJogador[3] = 30;
            rtgJogador[4] = 240 + x;
            rtgJogador[5] = 105;
            rtgJogador[6] = 40 + x;
            rtgJogador[7] = 105;
            setfillstyle(8,2);
            fillpoly(4, rtgJogador);
            setlinestyle(0,0,3);
        }
        else rectangle(40 + x, 30, 240 + x,105);

        sprintf(intToString, "%i", aux->dados_jog.id);
        outtextxy(50 + x, 40, "Jogador");
        outtextxy(210 + x, 40, intToString);

        sprintf(intToString, "%i", aux->dados_jog.pontuacao);
        outtextxy(50 + x, 60, "Pontos:");
        outtextxy(210 + x, 60, intToString);

        sprintf(intToString, "%i", aux->dados_jog.especial);
        outtextxy(50 + x, 80, "Bonus:");
        outtextxy(210 + x, 80, intToString);


        aux= aux->prox;
        x = x + 240;
    }

    rectangle(40, 185, 960, 360);
    outtextxy(50, 255, aux1->per.pergunta);
    outtextxy(50, 415, aux1->per.op1);
    outtextxy(50, 485, aux1->per.op2);
    outtextxy(50, 555, aux1->per.op3);
    outtextxy(50, 625, aux1->per.op4);

    setlinestyle(0,0,0);
    r = passandoMouse();

    setcolor(15);
    clearmouseclick(WM_LBUTTONDOWN);


    if (r == aux1->per.resposta) r = 1;
    else r = 0;

    switch (e){
        case 1:
            removePilha(b1);
            break;
        case 2:
            removePilha(b2);
            break;
        case 3:
            removePilha(b3);
            break;
        case 4:
            removePilha(b4);
            break;
        case 5:
            removePilha(b5);
            break;
    }

    cleardevice();
    return r;
}

void acabouTema(){
    cleardevice();
    setcolor(13);
    settextstyle(0,0,4);
    setlinestyle(0,0,5);
    rectangle(35,295,965,440);
    outtextxy(60, 300,"Acabaram todas as perguntas");
    outtextxy(270, 350, "deste tema !!");
    outtextxy(150, 400, "Escolha outro tema!!");
    setcolor(15);
    settextstyle(0,0,0);
    setlinestyle(0,0,0);
    Sleep(1500);
    cleardevice();
}

//            JOGADORES
void geraJogadores(lista *l, int n) {
    int e;
    jog jogador;
    srand(time(NULL));
    if (n == 1) {
        addLista(l, jogador);
        l->inicio->dados_jog.id = 1;
        l->inicio->dados_jog.pontuacao = 0;
        l->inicio->dados_jog.especial = 0;
        l->inicio->dados_jog.vez= 1;
    }

    if (n == 2) {
        e = (rand()%2) + 1;
        if (e == 1) {
            addLista(l, jogador);
            l->inicio->dados_jog.id = 1;
            l->inicio->dados_jog.pontuacao = 0;
            l->inicio->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 1;
            addLista(l, jogador);
            l->fim->dados_jog.id = 2;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
        } else {
            addLista(l, jogador);
            l->inicio->dados_jog.id = 2;
            l->inicio->dados_jog.pontuacao = 0;
            l->inicio->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 1;
            addLista(l, jogador);
            l->fim->dados_jog.id = 1;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
        }
    }

    /*
    if (n == 3) {
        e = (rand()%3) + 1;
        if (e == 1) {
            addLista(l, jogador);
            l->inicio->dados_jog.id = 1;
            l->inicio->dados_jog.pontuacao = 0;
            l->inicio->dados_jog.especial = 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 2;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 3;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
        } else if (e == 2) {
            addLista(l, jogador);
            l->inicio->dados_jog.id = 2;
            l->inicio->dados_jog.pontuacao = 0;
            l->inicio->dados_jog.especial = 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 3;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 1;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
        }  else {
            addLista(l, jogador);
            l->inicio->dados_jog.id = 3;
            l->inicio->dados_jog.pontuacao = 0;
            l->inicio->dados_jog.especial = 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 1;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 2;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
        }
    }
    */

    if (n == 4) {
        e = (rand()%4) + 1;
        if (e == 1) {
            addLista(l, jogador);
            l->inicio->dados_jog.id = 1;
            l->inicio->dados_jog.pontuacao = 0;
            l->inicio->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 1;
            addLista(l, jogador);
            l->fim->dados_jog.id = 2;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 3;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 4;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
        } else if (e == 2) {
            addLista(l, jogador);
            l->inicio->dados_jog.id = 2;
            l->inicio->dados_jog.pontuacao = 0;
            l->inicio->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 1;
            addLista(l, jogador);
            l->fim->dados_jog.id = 3;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 4;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 1;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
        }  else if (e == 3){
            addLista(l, jogador);
            l->inicio->dados_jog.id = 3;
            l->inicio->dados_jog.pontuacao = 0;
            l->inicio->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 1;
            addLista(l, jogador);
            l->fim->dados_jog.id = 4;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 1;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 2;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
        } else {
            addLista(l, jogador);
            l->inicio->dados_jog.id = 4;
            l->inicio->dados_jog.pontuacao = 0;
            l->inicio->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 1;
            addLista(l, jogador);
            l->fim->dados_jog.id = 1;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 2;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
            addLista(l, jogador);
            l->fim->dados_jog.id = 3;
            l->fim->dados_jog.pontuacao = 0;
            l->fim->dados_jog.especial = 0;
            l->inicio->dados_jog.vez= 0;
        }
    }

}

void mostraVencedor(lista l, int n) {
    struct jogador *aux;
    int maior_pontuacao, vencedor, i, empate[4], empatou=0, j = 0;
    char intToString[8];
    aux = l.inicio;

    for(i=0;i<4;i++) {
        empate[i] = 0;
    }
    // 1 Jogador
    if (n == 1) {
        settextstyle(10, 0, 8);
        setcolor(GREEN);
        outtextxy(150,100, "   PARABENS ");
        settextstyle(10, 0, 5);
        setcolor(WHITE);
        outtextxy(280, 210,"Voce conseguiu");
        sprintf(intToString, "%i", aux->dados_jog.pontuacao);
        outtextxy(330, 260, intToString);
        outtextxy(400, 260,"pontos!!");
    }

    // 2 Jogadores
    if (n == 2) {
        maior_pontuacao = aux->dados_jog.pontuacao;
        vencedor = aux->dados_jog.id;
        aux = aux->prox; //passa pro segundo jogador da lista

        if (aux->dados_jog.pontuacao == maior_pontuacao) empatou = 1;
        if(aux->dados_jog.pontuacao > maior_pontuacao) {
            maior_pontuacao = aux->dados_jog.pontuacao;
            vencedor = aux->dados_jog.id;
        }
        if (empatou == 1) {
            settextstyle(10, 0, 8);
            setcolor(GREEN);
            outtextxy(150,100, "   PARABENS ");
            settextstyle(10, 0, 5);
            setcolor(WHITE);
            outtextxy(220 , 210,"Voces empataram com");
            sprintf(intToString, "%i", aux->dados_jog.pontuacao);
            outtextxy(330, 260, intToString);
            outtextxy(400, 260,"pontos!!");

        } else {
            settextstyle(10, 0, 8);
            setcolor(GREEN);
            outtextxy(150,100, "   PARABENS ");
            settextstyle(10, 0, 5);
            setcolor(WHITE);
            outtextxy(220 , 210,"O jogador    venceu com");
            sprintf(intToString, "%i", vencedor);
            outtextxy(465, 210, intToString);
            sprintf(intToString, "%i", maior_pontuacao);
            outtextxy(330, 260, intToString);
            outtextxy(400, 260, "pontos!!");
        }
    }

    //4 Jogadores
    if (n == 4) {
        maior_pontuacao = aux->dados_jog.pontuacao;
        vencedor = aux->dados_jog.id;
        aux = aux->prox;

        for(i=0;i<3;i++) {
            if(aux->dados_jog.pontuacao > maior_pontuacao) {
                maior_pontuacao = aux->dados_jog.pontuacao;
                vencedor = aux->dados_jog.id;
            }
            aux = aux->prox;
        }

        for(i=0;i<4;i++) {
            if(aux->dados_jog.pontuacao == maior_pontuacao) {
                empatou = empatou + 1;
                empate[i] = aux->dados_jog.id;
            }
            aux = aux->prox;
        }

        if(empatou > 1) {

            settextstyle(10, 0, 7);
            setcolor(GREEN);
            outtextxy(300,100, " PLACAR ");
            settextstyle(10, 0, 4);
            setcolor(WHITE);
            for(i=0;i<4;i++) {
                outtextxy(170 , 210 + j,"Jogador");
                sprintf(intToString, "%i", aux->dados_jog.id);
                outtextxy(330, 210 + j, intToString);
                sprintf(intToString, "%i", aux->dados_jog.pontuacao);
                outtextxy(570, 210 + j, intToString);
                outtextxy(630, 210 + j, "pontos!!");
                aux = aux->prox;
                j = j + 80;
            }
        } else {
            settextstyle(10, 0, 8);
            setcolor(GREEN);
            outtextxy(150,100, "   PARABENS ");
            settextstyle(10, 0, 5);
            setcolor(WHITE);
            outtextxy(220 , 210,"O jogador    venceu com");
            sprintf(intToString, "%i", vencedor);
            outtextxy(465, 210, intToString);
            sprintf(intToString, "%i", maior_pontuacao);
            outtextxy(330, 260, intToString);
            outtextxy(400, 260, "pontos!!");
        }
    }
}

void dica(int n) {
    setcolor(LIGHTGRAY);
    settextstyle(1,0,1);
    if(n == 1) outtextxy(200, 500, "Dica: jogar com amigos e mais divertido!");
    if(n == 2) outtextxy(200, 500, "Dica: escolham quem vai ser o jogador 1 e quem vai ser o 2.");
    if(n == 4) outtextxy(200, 500, "Dica: escolham um numero, de 1 a 4, para cada jogador.");
    outtextxy(200, 200, "Se voce acertar a rodada bonus, vai poder escolher ");
    outtextxy(200, 220, "o tema da sua proxima pergunta!");
}

void criaMenu(){
    initwindow(1000, 800, "Menu");

    settextstyle(6, 0, 6);
    outtextxy(375, 100, "qui   ika");
    setcolor(4);
    outtextxy(475,100, "Z");
    setcolor(15);
    settextstyle(4, 0, 1);
    rectangle(420,395,560,420);
    outtextxy(425, 400, "1 Jogador");
    rectangle(420,445,590,470);
    outtextxy(425, 450, "2 Jogadores");
    rectangle(420,495,590,520);
    outtextxy(425, 500, "4 Jogadores");
}

int selecionaJogadores(){
    int repetir = 0, jogadores;
    while(repetir != 1)
    {

        if(mousex() >= 420 && mousex() <= 560 &&
           mousey() >= 395 && mousey() <= 420 &&
           ismouseclick(WM_LBUTTONDOWN))
            {
                outtextxy(390, 400, "->");
                setcolor(4);
                rectangle(420,395,560,420);
                Sleep(1000);
                jogadores = 1;
                repetir = 1;
                return jogadores;
            }
        else if(mousex() >= 420 && mousex() <= 590 &&
                mousey() >= 445 && mousey() <= 470 &&
                ismouseclick(WM_LBUTTONDOWN))
            {
                outtextxy(390, 450, "->");
                setcolor(4);
                rectangle(420,445,590,470);
                Sleep(1000);
                jogadores = 2;
                repetir = 1;
                return jogadores;
            }
        else if(mousex() >= 420 && mousex() <= 590 &&
                mousey() >= 495 && mousey() <= 520 &&
                ismouseclick(WM_LBUTTONDOWN))
            {
                outtextxy(390, 500, "->");
                setcolor(4);
                rectangle(420,495,590,520);
                Sleep(1000);
                jogadores = 4;
                repetir = 1;
                return jogadores;
            }
    }
}

int passandoMouse(){

    int resposta = 0;

    setlinestyle(0,0,0);
    while(resposta == 0)
    {
        setlinestyle(0,0,5);

        if(mousex() >= 40 && mousex() <= 960 &&
           mousey() >= 400 && mousey() <= 450 &&
           ismouseclick(WM_MOUSEMOVE))
        {
                setcolor(9);
                rectangle(40, 400, 960, 450);

            if (mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 400 && mousey() <= 450 &&
                ismouseclick(WM_LBUTTONDOWN))
                {
                    setlinestyle(0,0,7);
                    setcolor(12);
                    rectangle(38, 398, 960, 450);
                    resposta = 1;
                    Sleep(1000);
                    return resposta;
                }
        }
        else if(mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 470 && mousey() <= 520 &&
                ismouseclick(WM_MOUSEMOVE))
        {
                    setcolor(9);
                    rectangle(40, 470, 960, 520);

                if (mousex() >= 40 && mousex() <= 960 &&
                    mousey() >= 470 && mousey() <= 520 &&
                    ismouseclick(WM_LBUTTONDOWN))
                {
                    setlinestyle(0,0,7);
                    setcolor(12);
                    rectangle(38, 468, 960, 520);
                    resposta = 2;
                    Sleep(1000);
                    return resposta;
                }
        }
        else if(mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 540 && mousey() <= 590 &&
                ismouseclick(WM_MOUSEMOVE))
        {
                    setcolor(9);
                    rectangle(40, 540, 960, 590);

            if (mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 540 && mousey() <= 590 &&
                ismouseclick(WM_LBUTTONDOWN))
                {
                    setlinestyle(0,0,7);
                    setcolor(12);
                    rectangle(38, 538, 960, 590);
                    resposta = 3;
                    Sleep(1000);
                    return resposta;
                }
        }
        else if(mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 610 && mousey() <= 660 &&
                ismouseclick(WM_MOUSEMOVE))
        {
            setcolor(9);
            rectangle(40, 610, 960, 660);

            if (mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 610 && mousey() <= 660 &&
                ismouseclick(WM_LBUTTONDOWN))
                {
                    setlinestyle(0,0,7);
                    setcolor(12);
                    rectangle(38, 608, 960, 660);
                    resposta = 4;
                    Sleep(1000);
                    return resposta;
                }
        }
        else
        {
            setcolor(15);
            rectangle(40, 400, 960, 450);
            rectangle(40, 470, 960, 520);
            rectangle(40, 540, 960, 590);
            rectangle(40, 610, 960, 660);
        }
    }
}

int passandoMouse2(){

    int resposta = 0;
    cleardevice();
    setcolor(3);
    settextstyle(0,0 ,3);
    outtextxy(40, 50," Turno especial! Escolha o");
    outtextxy(35, 90, "tema da sua proxima pergunta!");
    setcolor(15);

    while(resposta == 0)
    {
        setlinestyle(0,0,4);

        if(mousex() >= 40 && mousex() <= 960 &&
           mousey() >= 130 && mousey() <= 180 &&
           ismouseclick(WM_MOUSEMOVE))
        {
                setcolor(10);
                rectangle(40, 130, 960, 180);

            if (mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 130 && mousey() <= 180 &&
                ismouseclick(WM_LBUTTONDOWN))
                {
                    setlinestyle(0,0,7);
                    setcolor(12);
                    rectangle(40, 130, 960, 180);
                    resposta = 1;
                    Sleep(1000);
                    clearmouseclick(WM_LBUTTONDOWN);
                    setcolor(15);
                    return resposta;
                }
        }
        else if(mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 230 && mousey() <= 280 &&
                ismouseclick(WM_MOUSEMOVE)){
                setcolor(10);
                rectangle(40, 230, 960, 280);

                if (mousex() >= 40 && mousex() <= 960 &&
                    mousey() >= 230 && mousey() <= 280 &&
                    ismouseclick(WM_LBUTTONDOWN))
                {
                    setlinestyle(0,0,7);
                    setcolor(12);
                    rectangle(40, 230, 960, 280);
                    resposta = 2;
                    Sleep(1000);
                    clearmouseclick(WM_LBUTTONDOWN);
                    setcolor(15);
                    return resposta;
                }
        }
        else if(mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 330 && mousey() <= 380 &&
                ismouseclick(WM_MOUSEMOVE)){
                setcolor(10);
                rectangle(40, 330, 960, 380);

            if (mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 330 && mousey() <= 380 &&
                ismouseclick(WM_LBUTTONDOWN))
                {
                    setlinestyle(0,0,7);
                    setcolor(12);
                    rectangle(40, 330, 960, 380);
                    resposta = 3;
                    Sleep(1000);
                    clearmouseclick(WM_LBUTTONDOWN);
                    setcolor(15);
                    return resposta;
                }
        }
        else if(mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 430 && mousey() <= 480 &&
                ismouseclick(WM_MOUSEMOVE)){
                setcolor(10);
                rectangle(40, 430, 960, 480);

            if (mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 430 && mousey() <= 480 &&
                ismouseclick(WM_LBUTTONDOWN)){
                    setlinestyle(0,0,7);
                    setcolor(12);
                    rectangle(40, 430, 960, 480);
                    resposta = 4;
                    Sleep(1000);
                    clearmouseclick(WM_LBUTTONDOWN);
                    setcolor(15);
                    return resposta;
                }
        }
        else if(mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 530 && mousey() <= 580 &&
                ismouseclick(WM_MOUSEMOVE)){
                setcolor(10);
                rectangle(40, 530, 960, 580);

            if (mousex() >= 40 && mousex() <= 960 &&
                mousey() >= 530 && mousey() <= 580 &&
                ismouseclick(WM_LBUTTONDOWN)){
                    setlinestyle(0,0,7);
                    setcolor(12);
                    rectangle(40, 530, 960, 580);
                    resposta = 5;
                    Sleep(1000);
                    clearmouseclick(WM_LBUTTONDOWN);
                    setcolor(15);
                    return resposta;
                }
        }
        else
        {
                    setcolor(15);
                    rectangle(40, 130, 960, 180);
                    outtextxy(100, 140,"Logica");
                    rectangle(40, 230, 960, 280);
                    outtextxy(100, 240,"Historia");
                    rectangle(40, 330, 960, 380);
                    outtextxy(100, 340,"Biologia");
                    rectangle(40, 430, 960, 480);
                    outtextxy(100, 440,"Artes");
                    rectangle(40, 530, 960, 580);
                    outtextxy(100, 540,"Conhecimento gerais");
        }
    }
}

void blocoJogador(lista l, int quantidadePlayers){
    struct jogador *aux;
    char intToString[8];
    int rtgJogador[8];
    int i, x=0;

    aux = l.inicio;
    for(i=0; i < quantidadePlayers; i++){

        if( aux->dados_jog.vez == 1){
            setlinestyle(0,0,6);
            rtgJogador[0] = 40 + x; // o if faz um retangulo preenchido para indicar
            rtgJogador[1] = 30;     // de quem é a vez
            rtgJogador[2] = 240 + x;
            rtgJogador[3] = 30;
            rtgJogador[4] = 240 + x;
            rtgJogador[5] = 105;
            rtgJogador[6] = 40 + x;
            rtgJogador[7] = 105;
            setfillstyle(8,2);
            fillpoly(4, rtgJogador);
            setlinestyle(0,0,3);
        }
        else{
            setlinestyle(0,0,3);
            rectangle(40 + x, 30, 240 + x,105);
        }

        sprintf(intToString, "%i", aux->dados_jog.id); // Converte o int pontos para uma string..
        outtextxy(50 + x, 40, "Jogador");
        outtextxy(110 + x, 40, intToString);

        sprintf(intToString, "%i", aux->dados_jog.pontuacao); // Converte o int pontos para uma string..
        outtextxy(50 + x, 60, "Pontos:");
        outtextxy(110 + x, 60, intToString);

        sprintf(intToString, "%i", aux->dados_jog.especial); // Converte o int bonus para uma string..
        outtextxy(50 + x, 80, "Bonus:");
        outtextxy(110 + x, 80, intToString);


        aux= aux->prox;
        x = x + 240;
    }
}

void verificaResposta(int resposta){
    cleardevice();
    rectangle(400, 270, 650, 380);
    if (resposta == 1){
        setcolor(3);
        settextstyle(8,0,5);
        outtextxy(420, 300, "Correto!");
    } else{
        setcolor(4);
        settextstyle(8,0,5);
        outtextxy(420, 300, "Errado!!");
    }
    setcolor(15);
    settextstyle(0,0,3);
}
