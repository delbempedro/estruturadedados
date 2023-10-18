#include <stdio.h>
#include <stdlib.h>

//tipo de item utilizado na lista
typedef int item;

//no que serve como indexador da lista
typedef struct No{
    item info;
    struct No *prox;
}no;

//lista encadeada
typedef struct{
    no *ini,*fim;
}lista;

//cria a lista encadeada
lista *criar();
//insere um item na lista
void inserir(lista* l,item* x);
//insere um item na lista à esquerda
void inseriresq(lista* l,item* x);
//retorna o endereço do item fornecido
int obter(lista* l,item* x, int *erro);
//elimina o item da lista
void eliminar(lista* l,item* x);
//retorna o tamanho da lista
int tamanho(lista* l);
//verifica se o item está na lista
int in(lista* l,item* x);
//inverte a lista
lista *inverter(lista* l);
//retorna o item de posição x
int get(lista* l,int *x,int *erro);
//imprimi, em sequência, os itens atuais da lista
void imprimir(lista *l);
//limpa a memória alocada para a lista
void limpa(lista *l);