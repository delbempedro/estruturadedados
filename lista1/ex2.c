#include<stdio.h>
#include<stdlib.h>

float** inicializa(int m, int n) {

    //declara as variáveis utilizadas para percorrer os loops
    int i, j;
    //aloca memória para a matriz que será inicializada
    float** matriz = (float**)malloc(m * sizeof(float*));
    for (i = 0; i < m; i++) {
        matriz[i] = (float*)malloc(n * sizeof(float));
    }

//lê os números da matrix
printf("%s","Insira os números da matriz: \n");
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        scanf("%f",&matriz[i][j]); //1 2 3 4 //5 6 7 8
    }
}

//retorna a matriz com os parâmetros recebidos
return matriz;

}

float** multi(float **a,float **b, int m,int n, int o){

int i,j,k;
//aloca memória para a matriz resultante
float **result = (float**)malloc(m*sizeof(float*));
for(i=0;i<m;i++){
    result[i] = (float*)malloc(o*sizeof(float));
}

//faz a multiplicação entre A e B e salva em result
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        for(k=0;k<o;k++){
            result[i][j] += a[i][k]*b[k][j];
        }
    }
}

//retorna a matriz resultante
return result;

}

void freevetor(float **vetor){

    //define n, valor que seŕa utilizado no loop
    int n = sizeof(vetor)/sizeof(vetor[0]);

    //desaloca a memória de cada subponteiro
    for(int i=0;i<n;i++){
        free(vetor[i]);
    }

    //desloca a memória do ponteiro
    free(vetor);

}

int main(){

//declara os variáveis de dimensão das matrizes e o número num de multiplicação delas
int m,n,o,p,num;

//pede as dimensões das matrizes
printf("%s","Digite as dimensões da primeira matriz: \n");
scanf("%i%i",&m,&n); //2 2
printf("%s","Digite as dimensões da segunda matriz: \n");
scanf("%i%i",&o,&p); //2 2

//confere se as matrizes podem ser multiplicadas
if(m!=o || n!=o){
    printf("%s","Estas matrizes não podem ser multiplicadas! \n");
    return 1;
} else{ //m=n=o

    //incializa as matrizes pedindo os valores
    float **a = inicializa(m,n);
    float **b = inicializa(o,p);

    //inicializa a matriz resultado e a auxiliar
    float **aux, **result = a;

    //multiplica A por B salvando em result e aux
    printf("%s","Digite quantas vezes deseja multiplicá-las: \n");
    scanf("%i",&num); //3 
    aux = multi(a,b,m,p,n);
    result = aux;

    //multiplica result por ele mesmo num vezes
    for(int i=1;i<num;i++){
            result = multi(result,aux,m,p,n);
    }

    //imprime a matriz resultante na tela
    printf("%s%i%s","O produto ",num," vezes das matrizes é: \n");
    for (int i=0;i<m;i++) {
        for (int j=0;j<p;j++) {
            printf("%f%s",result[i][j]," ");
        }
        printf("\n");
    }

    //desaloca a memória dos ponteiros
    freevetor(a);
    freevetor(b);
    freevetor(aux);

    }

return 0;

}

/*
o código foi escrito no  editor vscode e utilizando a simulação de terminal
do mesmo, compilou-se o código com o comando ' gcc -o ex2.exe ex2.c ' e
executou-se o código com o comando ' ./ex2.exe ' o que inicializa o código
*/