#include<stdio.h>
#include<stdlib.h>

char** leentrada(){

    //declara um ponteiro char com um tamanho inicial arbitrário
    int tamanho = 100;
    char **input = (char**)malloc(3*sizeof(char*));
    for(int i=0;i<3;i++){
        input[i] = (char*)malloc(tamanho*sizeof(char));
    }

    //pede a string a ser tratada
    printf("%s","Insira a string desejada: \n");

    int i=0;
    char carac;
    //armazena cada informação recebida
    while(carac != '\n'){

        //lê um caracter        
        scanf("%c", &carac);

        //inicia o armazenamento da string
        if(carac=='"'){
            int k = 0;
            //armazena até que se encontre outra aspa
            while(carac!='"'){
                //lê o caracter e o armazena
                scanf("%c", &carac);
                input[i][k] = carac;
                k++;

                if(k==tamanho-1){
                    tamanho = tamanho*2;
                    input[i] = (char*)realloc(input[i], tamanho*sizeof(char));
        
                }
            }
        }
        printf("%s",&input[i]);
        //incrementa i por 1
        i++;
    }

//retorna o ponteiro com as informações recebidas
return input;

}

char* concatena(char *entrada){

    //aloca espaço na memória para 'saida'
    char *saida = (char*)malloc(sizeof(char));

    //salva o tamanho de entrada
    int n = sizeof(entrada);

    //declara os índices de 'entrada' e 'saida' e uma variável auxiliar
    int i = 0;
    int k = 1;
    int salvari = 0;

    //insere o primeiro caracter de 'saida'
    saida[0] = '"';

    //percorre 'entrada' até encontrar '"' salvando os caracteres de interresse em 'saida'
    while(entrada[i]!='"'){
        i++;
        if(entrada[i]=='\n'){
            i = 0;
        }
    while(entrada[i]!='"'){
        saida[k] = entrada[i];
        i++;
        k++;
    }


    salvari = i;
    while(entrada[i]!='"'){
        i++;
    }
    while(entrada[i]!='"'){
        i++;
    }


    //insere o primeiro caracter de 'saida'
    saida[k] = '"';
    saida[k+1] = '\0';
        
    return saida;

}
}

void main(){

//lê a tela do terminal e cria um ponteiro apontando para elas
char **strings;
strings = leentrada();

/*//concatena as informações em um string
char *string;
string = concatena(strings);

//imprime a string resultante
printf("%s%s",string,"\n");

//libera a memórica alocada dinamicamente ao longo do programa
free(strings);
free(string);*/

}

/*
o código foi escrito no  editor vscode e utilizando a simulação de terminal
do mesmo, compilou-se o código com o comando ' gcc -o ex1.exe ex1.c ' e
executou-se o código com o comando ' ./ex1.exe ' o que inicializa o código


  }
    i += 5;
    while(entrada[i]!='"'){
        saida[k] = entrada[i];
        i++;
        k++;
    }

    //reinicia o índice de 'entrada'
    i = 0;

    //percorre 'entrada' até encontrar 'c' salvando os caracteres de interresse em 'saida'
    while(entrada[i]!='c'){
        i ++;
        if(entrada[i]=='\n'){
            i = 0;
        }
    }
    i += 5;
    saida[k] = entrada[i];
    k++;

    //reinicia o índice de 'entrada'
    i = 0;

    //percorre 'entrada' até encontrar 'b' salvando os caracteres de interresse em 'saida'
    while(entrada[i]!='b'){
        i++;
        if(entrada[i]=='\n'){
            i = 0;
        }
    }
    i += 5;
    while(entrada[i]!='"'){
        saida[k] = entrada[i];
        i++;
        k++;
    }

*/