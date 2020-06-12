typedef struct {
    int id;
    int pontuacao;
    int especial;
    int vez;
} jog;

struct jogador{
    jog dados_jog;
    struct jogador *prox;
};

typedef struct {
    struct jogador *inicio;
    struct jogador *fim;
} lista;

/* FILA
typedef struct {
    struct jogador *inicio;
    struct jogador *fim;
} fila;
*/

typedef struct {
    char pergunta[170];
    char op1[50];
    char op2[50];
    char op3[50];
    char op4[50];
    int resposta;
    int tema;
}pergunta;

struct carta {
    pergunta per;
    struct carta *prox;
};

typedef struct {
    struct carta *topo;
}pilha;

/* FILA
void criaFila(fila *f);
int addFila(fila *f, int id);
void mostraFila(fila f);
*/

// Pilha
void criaPilha(pilha *p);
int addPilha(pilha *p, pergunta per);
int removePilha(pilha *p);

// Lista
void criaLista(lista *l);
int addLista(lista *l, jog jogador);

// Perguntas
pergunta geraPerguntas(int i);
int numeroAleatorio(int f, int *x);
int baralhoAleatorio(int f);
int mostraPergunta(pilha *b1, pilha *b2, pilha *b3, pilha *b4, pilha *b5);
int turnoEspecial(pilha *b1, pilha *b2, pilha *b3, pilha *b4, pilha *b5, lista l, int quantidadePlayers);

// Jogadores
void geraJogadores(lista *l, int n);
void mostraVencedor(lista l, int n);
void dica(int n);

void alternativas (int x1, int y1, int x2, int y2, char letra [5]);
void criaMenu();
int selecionaJogadores();
int passandoMouse();
int passandoMouse2();
void acabouTema();
void blocoJogador(lista l, int quantidadePlayers);
void verificaResposta(int resposta);
