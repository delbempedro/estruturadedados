#include"double_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//cria a lista
lista *create(){

    //declara um ponteira para lista e aloca um espaço de lista para o mesmo
    lista *l = (lista*)malloc(sizeof(lista));

    //inicializa o no com NULL em suas componentes
    l -> ini = NULL;
    l -> fim = NULL;

    //retorna o ponteiro para lista
    return l;

}

//insere um nome na posição x da lista
void inserir(lista *l, char *nome, int *pos){

    //aloca espaço para os nós utilizados
    no *n = (no*)malloc(sizeof(no));
    no *aux1 = (no*)malloc(sizeof(no));
    no *aux2 = (no*)malloc(sizeof(no));

    //copia a string nome para name no nó
    strncpy(n->name,nome,100);

    if(l->ini==NULL){/*se a lista estiver vazia, aponta o fim e o começo para n
e aponta seu prox e seu ant para NULL*/

        l->ini = n;
        l->fim = n;
        n->prox = NULL;
        n->ant = NULL;

    }else{

        aux1 = l->ini;//atribui ao ponteiro auxiliar com l->ini

        while((aux1!=NULL)&&(*pos>1)){/*muda o ponteiro auxiliar para o seu próximo
até que o mesmo seja o ponteiro na posição anterior que deseja-se inserir um nome*/
                aux1 = aux1 -> prox;
                (*pos)--;

        }
        if(aux1==l->ini){//se a posição passada for <=0

            n->prox = l->ini;
            l->ini->ant = n;
            n->ant = NULL;
            l->ini = n;

        }else if(aux1==NULL){//se a posição passada for =>"tamanho da lista"

            n->ant = l->fim;
            l->fim->prox = n; 
            n->prox = NULL;
            l->fim = n;

        }else{//se a posição passada for intermediária

            aux2 = aux1->ant;
            n->prox = aux1;
            n->ant = aux2;
            aux2->prox = n;
            aux1->ant = n;         

        }

    }

}


//insere um nome de maneira ordenada
void ordinserir(lista *l, char *nome){

    /*declara o nó que apontará para o nó corrente da lista,
    apontando-o para o começo da lista*/
    no *n = l->ini;

    //cria um ponteiro para a posição onde será inserido o nome
    int *posicao;
    int pos = 1;
    posicao = &pos;

    if(isEmpty(l)){//se a lista estiver vazia

        inserir(l,nome,posicao);

    }else{//se a lista não estiver vazia

        while((n!=NULL)&&(strcmp(n->name,nome)<0)){/*enquanto a string
corrente for menor que a string a ser inserida*/
            n = n->prox;
            (*posicao)++;

        }

        inserir(l,nome,posicao);

    }

}


//remove um nome da lista
void remover(lista *l, char *nome, int *erro){

    *erro = 0;//supõe que não há erro

    if(exist(l,nome)){//se o nome passado estiver na lista

        /*declara o nó que apontará para o nó corrente da lista,
    apontando-o para o começo da lista*/
        no *n = l->ini;

        //declara ponteiros para nós auxiliares
        no *aux1,*aux2;

        while(strcmp(n->name,nome)!=0){//passa para o próximo nó até encontrar o nome

            n = n->prox;

        }
        if(n==l->ini){//se for passado o primeiro item

            l->ini = l->ini->prox;
            l->ini->ant = NULL;
            free(n);

        }else if(n==l->fim){//se for passado o último item

            l->fim = l->fim->ant;
            l->fim->prox = NULL;
            free(n);

        }else{//se for passado um item intermediário

            aux1 = n->ant;
            aux2 = n->prox;
            aux1->prox = aux2;
            aux2->ant = aux1;
            free(n);

        }

    }else{//se o nome passado não estiver na lista

        *erro = 1;

    }
}

//retorna se o nome existe na lista
int exist(lista *l, char *nome){

    /*declara o nó que apontará para o nó corrente da lista,
apontando-o para o começo da lista*/
    no *n = l->ini;

    //declara a existência como falsa
    int existe = 0;

    //procura o nome na lista enquanto não chegar ao seu fim
    while((n!=NULL)&&(!existe)){

        if(!strcmp(n->name,nome)){
            existe = 1;
        }
        n = n->prox;

    }

    //retorna 1 se existir e 0 se não
    return existe;

}

//imprimi a lista
void printAll(lista *l){

    /*declara o nó que apontará para o nó corrente da lista,
apontando-o para o começo da lista*/
    no *n = l->ini;

    //imprimi na tela todos os nomes da lista enquanto não chegar ao seu fim
    while(n!=NULL){

        printf("%s\n",n->name);
        n = n->prox;

    }


}

//verifica se a lista está vazia
int isEmpty(lista *l){

    //retorna 1 se a lista estiver vazia e 0 se não
    return l->ini==NULL;

}

//limpa a lista e a memória alocada
void limpar(lista *l){

    /*declara o nó que apontará para o nó corrente da lista,
apontando-o para o começo da lista*/
    no *n = l->ini;

    while(!isEmpty(l)){//enquanto a lista não estiver vazia

        l->ini = l->ini->prox;
        l->ini->ant = NULL;
        free(n);
    }

}