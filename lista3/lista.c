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

//insere um item na lista à esquerda
void inseriresq(lista* l,item* x){

    //declara um ponteiro para no e aloca espaço de um no para o mesmo
    no *n = (no*)malloc(sizeof(no));

    //salva x em info de n
    n -> info = *x;
    //inicializa prox de n como NULL
    n -> prox = NULL;

    //se l estiver vazia, aponta seu início para n, se não aponta 
    if(l -> ini == NULL){

        l -> ini = n;
        l -> fim = n;

    }else n -> prox = l -> ini;
    l -> ini = n;

}

//retorna o endereço do item fornecido
int obter(lista* l,item* x, int *erro){

    //cria o contador de endereço
    int end = 0;

    //cria um ponteiro para no e o aponta para p inicio de l
    no *n;
    n = l->ini;

    //define, como padrão, a ausência de erro
    *erro = 0;

    //enquanto info de n não for igual ao item, adiciona-se 1 a end
    while(n->info!=*x){

        end++;
        n = n-> prox;

    }
    if(n==NULL){//se o item não estiver na lista
        *erro = 1;
        return;
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

/*declara a variável de iteração e o ponteiro, que apontará
para a mesma, que será passado com parâmetro da função inseriresq*/
    int i;
    int *value;
    value = &i;

    //define tam como o tamanho de l
    int tam = tamanho(l);

    //cria um ponteiro para no
    no *n;

    //cria a lista que será retornada
    lista *invertida = criar();
    
    //declara as variáveis que receberão os valores da lista
    int *pointer;
    int valor;
    pointer = &valor;

    //define o ponteiro de erro da função get
    int *erro;

    //inverte a lista
    for(i=0;i<tam;i++){
        
        valor = get(l,value,erro);
        inseriresq(invertida,pointer);

    }

    limpa(l);

    //retorna a lista invertida
    return invertida;

}

//retorna o item de posição x
int get(lista* l,int *x, int *erro){

    //cria um ponteiro para no e o aponta para p inicio de l
    no *n;
    n = l->ini;

    //define a ausẽncia de erro, como padrão
    *erro = 0;

    //inicia um loop até o x-éssimo no ou até o fim da lista (n=NULL)
    int i = 0;
    while((n!=NULL)&&(i<*x)){

        //muda n para o proximo no e incrementa i por 1
        n = n->prox;
        i++;
        
    }if(n!=NULL){//retorna o valor do x-éssimo no, se o no não for NULL

        return n->info;

    }else{//muda erro para 1, se o endereço fornecido for maior que a lista
        
        *erro = 1;
        return;

    }

}

//imprimi, em sequência, os itens atuais da lista
void imprimir(lista *l){

    /*declara a variável de iteração e o ponteiro, que apontará
para a mesma, que será passado com parâmetro da função get*/
    int i;
    int *pos;
    pos = &i;

    //define o ponteiro de erro da função get
    int *erro;

    //define tam como o tamanho de l
    int tam = tamanho(l);

    //inicia o loop imprimindo os itens de posição i-éssima
    for(i=0;i<tam;i++){

        printf("%d%s",get(l,pos,erro),"\n");

    }    

}

//limpa a memória alocada para a lista
void limpa(lista *l){

    //cria um ponteiro para no e o aponta para o começo da lista
    no *n;
    n = l -> ini;

    //elimina os itens da lista até ela estar vazia
    while(n!=NULL){

        
        /*define uma variável para receber o item a ser eliminado e aponta
o ponteiro de no para o começo da lista*/
        item *item = &n->info;
        n = l -> ini;

        //elimina o primeiro item da lista
        eliminar(l,item);

    }

}