#include "lista.c"

void main(){   

    //cria as variáveis que determinará a operação e que determinará o fim das operações
    int NumOp;
    int sair = 0;

    //cria a lista
    lista *l = criar();

    //inicia o loop com as operações até que sair seja 1
    while(!sair){

        //imprimi na tela as operções possíveis
        printf("Escolha a operação desejada de acordo com a numeração abaixo:\n");
        printf("(1) Inserir item\n");
        printf("(2) Obter endereço do item\n");
        printf("(3) Eliminar item\n");
        printf("(4) Tamanho da lista\n");
        printf("(5) Verificar se o item está na lista\n");
        printf("(6) Inverter a lista\n");
        printf("(7) Obter item do endereço\n");
        printf("(8) Imprimir lista\n");
        printf("(9) Encerrar execução do programa\n");

        //lê na tela a operação desejada
        scanf("%d",&NumOp);

        //efetua a operação de acordo com o número fornecido
        if(NumOp==1){

            /*cria um ponteiro para item (também cria o próprio item e aponta o ponteiro para o mesmo)
e um int que determinará quantos itens serão inseridos*/
            item *ele;
            item value;
            ele = &value;
            int num;

            //pede ao usuário a quantidade de itens a serem inseridos e salva este valor
            printf("Dite quantos itens deseja inserir\n");
            scanf("%d",&num);

            //pede ao usuário os elemento que ele deseja inserir e inicia um loop inserindo num elementos na lista
            printf("Digite o(s) item(s) que deseja inserir\n");
            for(int i=0;i<num;i++){

                scanf("%d",&value);
                inserir(l,ele);

            }

        }else if(NumOp==2){

            /*cria um ponteiro para item (também cria o próprio item e aponta o ponteiro para o mesmo)
e um int que determinará quantos endereços serão obtidos*/
            item *ele;
            item value;
            ele = &value;
            int num;
            int end;

            //pede ao usuário a quantidade de endereços a serem obtidos e salva este valor
            printf("Dite quantos endereços deseja obter\n");
            scanf("%d",&num);

            //pede ao usuário os itens que ele deseja obter o endereço e inicia um loop obtendo num endereços da lista
            for(int i=0;i<num;i++){

                printf("Digite o item do qual deseja obter o endereço\n");
                scanf("%d",&value);
                end = obter(l,ele);
                printf("%s%d%s%d%s","O endereço do item ",value," é ",end,"\n");

            }

        }else if(NumOp==3){

            /*cria um ponteiro para item (também cria o próprio item e aponta o ponteiro para o mesmo)
e um int que determinará quantos itens serão eliminados*/
            item *ele;
            item value;
            ele = &value;
            int num;

            //pede ao usuário a quantidade de itens a serem eliminados e salva este valor
            printf("Dite quantos itens deseja eliminar\n");
            scanf("%d",&num);

            //pede ao usuário os itens que ele deseja eliminar e inicia um loop eliminando num itens da lista
            printf("Digite o(s) itens(s) que deseja eliminar\n");
            for(int i=0;i<num;i++){

                scanf("%d",&value);
                eliminar(l,ele);
                
            }

            //informa que os itens foram eliminados
            printf("Os itens foram eliminados\n");

        }else if(NumOp==4){

            printf("%s%d%s","A lista tem tamanho ",tamanho(l),"\n");

        }else if(NumOp==5){

            /*cria um ponteiro para item (também cria o próprio item e aponta o ponteiro para o mesmo)
e um int que determinará quantos itens serão procurados na lista*/
            item *ele;
            item value;
            ele = &value;
            int num;

            //pede ao usuário a quantidade de itens a serem eliminados e salva este valor
            printf("Dite quantos itens deseja verificar se estão na lista\n");
            scanf("%d",&num);

            //pede ao usuário os itens que ele verificar se estão na lista e inicia um loop verificando num itens da lista
            for(int i=0;i<num;i++){
                
                printf("Digite o item, que deseja verificar se está na lista\n");
                scanf("%d",&value);

                if(in(l,ele)){
                    printf("%s%d%s","O item ",value," está na lista\n");
                }else{
                    printf("%s%d%s","O item ",value," não está na lista\n");
                }
              
            }

        }else if(NumOp==6){

            //Comunica ao usuário a inversão da lista e a inverte
            printf("A lista foi invertida\n");
            l = inverter(l);

        }else if(NumOp==7){

            /*cria um ponteiro para item (também cria o próprio item e aponta o ponteiro para o mesmo)
e um int que determinará quantos itens serão obtidos*/
            item *ele;
            item value;
            ele = &value;
            int num;
            int item;

            //pede ao usuário a quantidade de itens a serem obtidos e salva este valor
            printf("Dite quantos itens deseja obter\n");
            scanf("%d",&num);

            //pede ao usuário os endereços dos itens que ele deseja obter e inicia um loop obtendo num endereços da lista
            for(int i=0;i<num;i++){

                printf("Digite o endereço do item que deseja obter\n");
                scanf("%d",&value);
                item = get(l,ele);
                printf("%s%d%s%d%s","O item do endereço ",value," é ",item,"\n");

            }

        }else if(NumOp==8){

            //Imprimi a lista
            printf("O estado atual, em sequência, da lista é:\n");
            imprimir(l);

        }else if(NumOp==9){

            //Muda a variável sair para iterromper o loop de execução
            printf("O programa foi finalizado\n");
            sair = 1;

        }

    }

    //limpa a memória alocada para a lista
    limpa(l);

}