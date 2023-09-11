#include<stdio.h>
#include<stdlib.h>

char* concatena(char prim[], char seg[], char conc[]){

    //aloca espaço para a string concatenada
    char *saida = (char*)malloc(sizeof(char));

    //declara a variável que percorrerá os espaços da string
    int saidaindice = 0;

    //percorre a primeira string pegando os caracteres de interesse
    for(int i = 0;prim[i]!='\0';i++){
        saida[saidaindice] = prim[i];
        saidaindice++;
    }

    //percorre a string de concatenação pegando os caracteres de interesse
    for(int i = 0;conc[i]!='\0';i++){
        saida[saidaindice] = conc[i];
        saidaindice++;
    }

    //percorre a segunda string pegando os caracteres de interesse
    for(int i = 0;seg[i]!='\0';i++){
        saida[saidaindice] = seg[i];
        saidaindice++;
    }

    //retorna a string
    return saida;

}


void main(){

//declara as strings que serão concatenadas
char primeiro[30],segundo[30],caracter[10];

//pede ao usuário quais serão as strings
printf("%s","Insira a primeira string: \n");
scanf("%s",primeiro); //Delbem
printf("%s","Insira a segunda string: \n");
scanf("%s",segundo); //Pedro
printf("%s","Insira o caracter de separação: \n");
scanf("%s",caracter); //,

//retorna ao usuário a string concatenada
printf("%s%s",concatena(primeiro,segundo,caracter),"\n");

}

/*
o código foi escrito no  editor vscode e utilizando a simulação de terminal
do mesmo, compilou-se o código com o comando ' gcc -o ex1.exe ex1.c ' e
executou-se o código com o comando ' ./ex1.exe ' o que inicializa o código
*/