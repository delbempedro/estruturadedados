#include "lista.c"

void main(){

    lista *l = criar();

    item value = 1;
    item *ele = &value;

    for(int i=0;i<10;i++){
        value = i;
        inserir(l,ele);
    }

    value = 5;

    eliminar(l,ele); 

    int valor = get(l,ele);

    printf("%d%s",valor,"\n");

    //printf()"%d%s%d%s",l->ini->info," ",l->fim->info,"\n");

}