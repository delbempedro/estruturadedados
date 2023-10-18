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
        printf("(8) Criar lista\n");
        printf("(1) Inserir item\n");
        printf("(2) Obter endereço do item\n");
        printf("(3) Eliminar item\n");
        printf("(4) Tamanho da lista\n");
        printf("(5) Verificar se o item está na lista\n");
        printf("(6) Inverter a lista\n");
        printf("(7) Obter item do endereço\n");

        //lê na tela a operação desejada
        scanf("%d",NumOp);

        //efetua a operação de acordo com o número fornecido
        if(NumOp==1){

            //cria um ponteiro para item e um int que determinará quantos itens serão inseridos
            item *ele;
            int num;

            //pede ao usuário a quantidade de itens a serem inseridos e salva este valor
            printf("Dite quantos itens deseja inserir\n");
            scanf("%d",&num);

            //pede ao usuário os elemento que ele deseja inserir e inicia um loop inserindo num elementos na lista
            prinf("Digite o(s) item(s) que deseja inserir\n");
            for(int i=0;i<num;i++){

                scanf("%d",&ele);
                inserir(l,ele);

            }

        }else if(NumOp==2){

            //cria um ponteiro para item e um int que determinará quantos endereços serão obtidos
            item *ele;
            int num;

            //pede ao usuário a quantidade de endereços a serem obtidos e salva este valor
            printf("Dite quantos endereços deseja obter\n");
            scanf("%d",&num);

            //pede ao usuário os itens que ele deseja obter o endereço e inicia um loop obtendo num endereços da lista
            prinf("Digite o(s) itens(s) que deseja obter o(s) endereço(s)\n");
            for(int i=0;i<num;i++){

                scanf("%d",&ele);
                int end = obter(l,ele);
                printf("%s%d%s%d%s","O endereço do item",ele," é ",end,"\n");

            }


        }else if(NumOp==3){

            //cria um ponteiro para item e um int que determinará quantos itens serão eliminados
            item *ele;
            int num;

            //pede ao usuário a quantidade de itens a serem eliminados e salva este valor
            printf("Dite quantos itens deseja eliminar\n");
            scanf("%d",&num);

            //pede ao usuário os itens que ele deseja eliminar e inicia um loop eliminando num itens da lista
            prinf("Digite o(s) itens(s) que deseja eliminar\n");
            for(int i=0;i<num;i++){

                scanf("%d",&ele);
                eliminar(l,ele);
                
            }


        }

        printf("Digite 0 se desejar efetuar mais operações e 1 se deseja parar\n");
        scanf("%d",sair);

    }

}