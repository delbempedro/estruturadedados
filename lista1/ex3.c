#include<stdio.h>
#include<stdlib.h>

float *lenotas(int alunos){

    //aloca um espaço na memória para um vetor de float's com tamanho de "alunos"
    float *notas = (float*)malloc(alunos*sizeof(float));

    //pede as notas dos alunos e as armazena
    printf("%s","Insira as notas dos alunos: \n");
    for(int i=0;i<alunos;i++){
        scanf("%f",&notas[i]); //9 8
    }

    //retorna uma lista com as notas lidas
    return notas;
}

float media(float *lista, int tamanho){

//declara a variável onde somar-se-á as notas
float soma;

//soma os valores do vetor lista
for(int i=0;i<tamanho;i++){
    soma += lista[i];
}

//desaloca a memória utilizada para 'lista'
free(lista);

//retorna a média
return soma/tamanho;

}

int main(){

//declara a variável em que se armazenará o número de alunos e a média
int alunos;
float med;

//pede as notas dos alunos
printf("%s","Insira a quantidade de alunos: \n");
scanf("%d",&alunos); //2

//pede os nomes dos alunos e os armazena
char *nomes[alunos];
printf("%s","Insira os nomes dos alunos: \n");
for(int i=0;i<alunos;i++){
    scanf("%s",&nomes[i]); //pedro matheus
}

//retorna a média das notas
printf("%f%s",media(lenotas(alunos),alunos),"\n");

return 0;
}

/*
o código foi escrito no  editor vscode e utilizando a simulação de terminal
do mesmo, compilou-se o código com o comando ' gcc -o ex3.exe ex3.c ' e
executou-se o código com o comando ' ./ex3.exe ' o que inicializa o código
*/