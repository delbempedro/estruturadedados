typedef struct bloco{

    char name[100];
    struct bloco *ant,*prox;

}no;

typedef struct{

    no *ini;
    no *fim;

}lista;

//cria a lista
lista *create();
//insere um nome na posição x da lista
void inserir(lista *l, char *nome, int *pos);
//insere um nome de maneira ordenada
void ordinserir(lista *l, char *nome);
//remove um nome da lista
void remover(lista *l, char *nome, int *erro);
//retorna se o nome existe na lista
int exist(lista *l, char *nome);
//imprimi a lista
void printAll(lista *l);
//verifica se a lista está vazia
int isEmpty(lista *l);
//limpa a lista e a memória alocada
void limpar(lista *l);
