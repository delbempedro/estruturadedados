#include "lista.c"

void main(){

    lista *l = criar();

    item value = 1;
    item *ele = &value;

    for(int i=0;i<10;i++){
        value = i;
        inserir(l,ele);
    }

    lista *inv = inverter(l);
    printf("saiu\n");
    printf("%d%s",tamanho(inv),"\n");
/*    for(int i=0;i<10;i++){
        value = i;
        printf("%d%s",get(inv,ele),"\n");
    }*/

    

    //printf()"%d%s%d%s",l->ini->info," ",l->fim->info,"\n");

}