#include"double_list.c"

void main(){

    //cria a lista
    lista *l = create();

    //declara a variável que decide a continuação ou não do programa
    int continuar = 1;

    //declara a variável que decide as operações
    int op = 1;

    //declara a variável que impede a inserção ordenada e por posição na mesma execução do código
    int insercao = 0;

    //pergunta ao usuário qual é a operação desejada
    while(continuar){

        //imprimi na tela as operções possíveis
        printf("Escolha a operação desejada de acordo com a numeração abaixo:\n");
        printf("(0) Encerrar execução do programa\n");
        printf("(1) Inserir nome por posição\n");
        printf("(2) Inserir nome por ordem\n");
        printf("(3) Remover nome\n");
        printf("(4) Verificar se o nome está na lista\n");
        printf("(5) Imprimir lista\n");
        printf("(6) Verificar se a lista está vazia\n");

        //faz a leitura da operação
        scanf("%d",&op);

        //efetua a operação de acordo com o número fornecido
        if(op==0){

            //muda a variável que define a continuação para 0
            continuar = 0;

        }else if(op==1){

            if(insercao!=2){//garante que outro tipo de inserção não foi feito ainda

                /*cria um ponteiro para char[], e int, (também cria o próprio char[], e int, e aponta o ponteiro para o mesmo)
    e um int que determinará quantos itens serão inseridos*/
                char *nome;
                char name[100];
                nome = name;
                int posicao;
                int *pos;
                pos = &posicao;
                int numero;

                //pede ao usuário a quantidade de nomes a serem inseridos e salva este valor
                printf("Digite quantos nomes deseja inserir\n");
                scanf("%d",&numero);

                //pede ao usuário o(s) nome(s) que ele deseja inserir, a(s) posição(ões), e inicia um loop inserindo num nomes na lista
                for(int i=0;i<numero;i++){

                    printf("Digite o nome que deseja inserir e sua posição\n");
                    scanf("%s",name);
                    scanf("%d",&posicao);
                    inserir(l,nome,pos);

                }

                //evita a mudança no tipo de inserção
                insercao = 1;
            }else{

                printf("Não é possível fazer este tipo de inserção, uma vez que outro tipo já foi feito\n");

            }

        }else if(op==2){

            if(insercao!=1){

                /*cria um ponteiro para char[] (também cria o próprio char[] e aponta o ponteiro para o mesmo)
    e um int que determinará quantos itens serão inseridos*/
                char *nome;
                char name[100];
                nome = name;
                int numero;

                //pede ao usuário a quantidade de nomes a serem inseridos e salva este valor
                printf("Digite quantos nomes deseja inserir\n");
                scanf("%d",&numero);

                //pede ao usuário o(s) nome(s) que ele deseja inserir e inicia um loop inserindo num nomes na lista
                printf("Digite o(s) nome(s) que deseja inserir\n");
                for(int i=0;i<numero;i++){

                    scanf("%s",name);
                    ordinserir(l,nome);

                }

                //evita a mudança no tipo de inserção
                insercao = 2;

            }else{

                printf("Não é possível fazer este tipo de inserção, uma vez que outro tipo já foi feito\n"); 

            }
            
        }else if(op==3){

            /*cria um ponteiro para char[] (também cria o próprio char[] e aponta o ponteiro para o mesmo)
    e um int que determinará quantos itens serão inseridos*/
            char *nome;
            char name[100];
            nome = name;
            int numero;

            //declara o ponteiro e variável de erro
            int *err;
            int erro;
            err = &erro;

            //pede ao usuário a quantidade de nomes a serem removidos e salva este valor
            printf("Digite quantos nomes deseja remover\n");
            scanf("%d",&numero);

            //pede ao usuário o(s) nome(s) que ele deseja remover e inicia um loop inserindo num nomes na lista
            printf("Digite o(s) nome(s) que deseja remover\n");
            for(int i=0;i<numero;i++){

                scanf("%s",name);
                remover(l,nome,err);
                if(*err==1){

                    printf("O item não está na lista\n");

                }

            }
            
        }else if(op==4){

            /*cria um ponteiro para char[] (também cria o próprio char[] e aponta o ponteiro para o mesmo)
    e um int que determinará quantos itens serão inseridos*/
            char *nome;
            char name[100];
            nome = name;
            int numero;

            //pede ao usuário a quantidade de nomes a serem verificados e salva este valor
            printf("Digite quantos nomes deseja verificar a existência\n");
            scanf("%d",&numero);

            //pede ao usuário o(s) nome(s) que ele deseja verificar e inicia um loop inserindo num nomes na lista
            for(int i=0;i<numero;i++){

                printf("Digite o nome que deseja verificar se está na lista\n");
                scanf("%s",name);
                if(exist(l,nome)){

                printf("O item está na lista\n");

                }else{

                    printf("O item não está na lista\n");

                }

            }
            
        }else if(op==5){

            printAll(l);

        }else if(op==6){
            
            if(isEmpty(l)){

                printf("A lista está vazia\n");

            }else{

                printf("A lista não está vazia\n");

            }
            
        }

    }



}

/*
o código foi escrito por:
Pedro Calligaris Delbem
N°USP: 5255417
e
Tony Maciel Alexander
N°USP: 12624850
no  editor vscode e utilizando a simulação de terminal
do mesmo, compilou-se o código com o comando ' gcc -o main.exe main.c ' e
executou-se o código com o comando ' ./main.exe ' o que inicializa o código
*/