#include "lista.c"

void main(){   

    lista *l = criar();

    item value = 1;
    item *ele = &value;

    for(int i=0;i<10;i++){
        value = i;
        inserir(l,ele);
    }
    value = 0;
    
    lista *inv = inverter(l);

    imprimir(inv);
    

}