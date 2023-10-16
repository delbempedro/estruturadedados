#include "lista.h"

//cria a lista encadeada
lista *criar(){

    //declara um ponteira para lista e aloca um espaço de lista para o mesmo
    lista *l = (lista*)malloc(sizeof(lista));

    //inicializa o no com NULL em suas componentes
    l -> ini = NULL;
    l -> fim = NULL;

    //retorna o ponteiro para lista
    return l;

}

//insere um item na lista
void inserir(lista* l,item* x){

    //declara um ponteiro para no e aloca espaço de um no para o mesmo
    no *n = (no*)malloc(sizeof(no));

    //salva x em info de n
    n -> info = *x;
    //inicializa prox de n como NULL
    n -> prox = NULL;

    //se l estiver vazia, aponta seu início para n, se não aponta 
    if(l -> ini == NULL){

        l -> ini = n;

    }else l -> fim -> prox = n;
    l -> fim = n;

}

//retorna o endereço do item fornecido
int obter(lista* l,item* x){

    //cria o contador de endereço
    int end = 0;

    //cria um ponteiro para no e o aponta para p inicio de l
    no *n;
    n = l->ini;

    //enquanto info de n não for igual ao item, adiciona-se 1 a end
    while((n->info!=*x)&&(n!=NULL)){

        end++;
        n = n-> prox;

    }
    if(n==NULL){//se o item não estiver na lista
        printf("Este item não está na lista\n");
        return -1;
    }else return end;//retorna o endereço do item na lista

}

//elimina o item da lista
void eliminar(lista* l,item* x){

    //cria um ponteiro para no e o aponta para o começo da lista, alem de criar um ponteiro auxiliar
    no *n, *aux;
    n = l->ini;

    //declara a variável que determinará a saída do loop
    int sair = 0;

    while((n!=NULL)&&(!sair)){//fica em loop até chegar ao fim da lista ou encontrar o item a ser eliminado

        if(n->info!=*x){//se o item atual não é o desejado
            
            //salva n em aux e muda n para prox de n
            aux = n;
            n = n->prox;
            
        }else{
            
            if(n==l->ini){//o item é o primeiro da lista

                //muda o começo para o item seguinte
                l->ini = l->ini->prox;
                
                if(l->ini==NULL){//se o item eliminado for o único da lista

                    //muda fim para NULL, indicando que a lista esta vazia
                    l->fim=NULL;
                    
                }
            }else if(n==l->fim){//se o item eliminado for o último da lista

                //muda o fim para o ponteiro auxiliar (item anterior ao eliminado) e muda o prox de fim para NULL
                l->fim = aux;
                l->fim->prox=NULL;
                
            }else aux->prox=n->prox;/*caso o item eliminado for um item do meio da lista
apenas pula-se o mesmo, mudando o prox de aux (anterior) para o prox de n (item eliminado)*/
            
            //libera a memória alcada para n e muda a variável sair para sair do loop
            free(n);
            sair = 1;

        }    

    }

}

//retorna o tamanho da lista
int tamanho(lista* l){

    //cria um ponteiro para no e o aponta para p inicio de l
    no *n;
    n = l->ini;

    //declara o contador
    int count = 0;

    while(n!=NULL){//fica em loop até o fim da lista

        //incrementa um no contador e muda n para o próximo no
        count++;
        n = n->prox;

    }

    //retorna o contador
    return count;

}

//verifica se o item está na lista
int in(lista* l,item* x){

    //cria um ponteiro para no e o aponta para p inicio de l
    no *n;
    n = l->ini;

    //declara variável que indica se o item está ou não na lista
    int retorna = 0;

    //loop até o fim fa lista ou até encontrar o item procurado
    while((n!=NULL)&&(n->info!=*x)){

        //muda n para o proximo no
        n = n->prox;

    }if(n!=NULL){//item está na lista

    //atribui a retorna o valor que corresponde ao item estar na lista
    retorna = 1;

    }

    //retorna 1 se o item estiver na lista e 0 se não estiver
    return retorna;

}

//inverte a lista
lista *inverter(lista* l){

    //salva o tamnho da lista original
    int tam = tamanho(l);

    //cria um ponteiro para no e o aponta para p inicio de l e dois ponteiros auxiliares
    no *n, *p1, *p2;
    n = l->ini;

    //cria a lista que será retornada
    lista *invertida = criar();

    //finaliza invertida com o começo da lista original
    invertida -> fim = n;

    printf("1\n");
    //faz a mudança de ponteiros para o primeiro item
    p1 = n->prox;
    p2 = p1->prox;

    //faz a mudança de ponteiros do item 2 até o penúltimo
    for(int i=0;i<tam-2;i++){
    printf("2\n");
       p1->prox = n;
       printf("3\n");
       n = p1;
       printf("4\n");
       p1 = p2;
       printf("5\n");
       printf("%d%s",p1->info,"oi\n");
       p2 = p1->prox;
printf("6\n");
    }

    //inicia a lista invertida com o fim da lista inicial
    invertida -> ini = p2;
printf("7\n");
    invertida -> fim = NULL;
printf("8\n");
    //retorna a lista invertida
    return invertida;

}

//retorna o item de posição x
int get(lista* l,int *x){

    //cria um ponteiro para no e o aponta para p inicio de l
    no *n;
    n = l->ini;

    //inicia um loop até o x-éssimo no ou até o fim da lista (n=NULL)
    int i = 0;
    while((n!=NULL)&&(i<*x)){

        //muda n para o proximo no e incrementa i por 1
        n = n->prox;
        i++;
        
    }if(n!=NULL){//retorna o valor do x-éssimo no, se o no não for NULL

        return n->info;

    }else{//retorna uma mensagem de erro se o endereço fornecido for maior que a lista
        
        printf("A lista é menor que o endereço fornecido\n");
        return -1;

    }

}