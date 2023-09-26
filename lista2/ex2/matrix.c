#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"

void imprimir(Matriz A){

    //aponta as variáveis necessárias para os atributos de "A"
    float** result = A.values;
    int m = A.linha;
    int n = A.coluna;

    //imprimi a matriz resultante na tela
    printf("A matriz resultante é: \n");
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            printf("%f%s",result[i][j]," ");
        }
        printf("\n");
    }

}

int verificamatrizes(int m,int n,int o,int p){

    if ((m == o)&&(n == p)){
        return 1;
    }
    else{
        return 0;
    }

}

void freematriz(Matriz M){

    //atribui "values" de "M" a "vetor"
    float** vetor = M.values;

    //define n, valor que seŕa utilizado no loop
    int n = sizeof(vetor)/sizeof(vetor[0]);

    //desaloca a memória de cada subponteiro
    for(int i=0;i<n;i++){
        free(vetor[i]);
    }

    //desloca a memória do ponteiro
    free(vetor);

}

Matriz create(int linha, int coluna){
    
    //cria a matriz que será retornada
    Matriz result;
    
    float **C = malloc(sizeof(float *) * linha);
      for(int i = 0; i < coluna; i++) 
        C[i] = malloc(sizeof(float) * coluna);
    
    result.linha = linha;
    result.coluna = coluna;
    result.values = C;

    return result;
}

void preenche(Matriz A){

    //recebe os valores da matriz
    for (int i = 0; i < A.linha; i++)
        for (int j = 0; j < A.coluna; j++)
            scanf("%f", &A.values[i][j]);
    

}

int elevar(int a, int n){

    //declara a varável que será retornada
    int result = 1;

    //efetua a potenciação
    for(int i=0;i<n;i++){
        result *= a;
    }
    //retorna a potência n de a
    return result;

}

Matriz mult_mat(Matriz A,Matriz B, int num){

    //verifica se as matrizes são compatíveis com a operação
    if (verificamatrizes(A.linha,A.coluna,B.linha,B.coluna)==1){

        //aloca memória para a matriz resultante
        float **result = (float**)malloc(A.linha*sizeof(float*));
        for(int i=0;i<A.linha;i++){
            result[i] = (float*)malloc(A.coluna*sizeof(float));
        }

        //faz a multiplicação entre A e B e salva em result
        for(int i=0;i<A.linha;i++){
            for(int j=0;j<B.coluna;j++){

                //declara a multiplicação de Aij por Bij
                int mul = A.values[i][j]*B.values[i][j];
                printf("%d %d %s",mul,num,"\n");
                //eleva mul a num
                result[i][j] =  elevar(mul,num);
            }
            
        }
        Matriz resultante = create(A.linha,A.coluna);

        //atribui "values" da matriz "resultante" para "result"
        resultante.values = result;

        //retorna a matriz resultante
        return resultante;

    }else{

        printf("A operação não pode ser feita, as matrizes são imcompatíveis");

    }

}

Matriz sum_mat(Matriz A,Matriz B){
    //verifica se as matrizes são compatíveis com a operação
    if (verificamatrizes(A.linha,A.coluna,B.linha,B.coluna)==1){

        //aloca memória para a matriz resultante
        float **result = (float**)malloc(A.linha*sizeof(float*));
        for(int i=0;i<A.linha;i++){
            result[i] = (float*)malloc(A.coluna*sizeof(float));
        }

        //faz a soma entre A e B e salva em result
        for(int i=0;i<A.linha;i++){
            for(int j=0;j<B.coluna;j++){
                result[i][j] = A.values[i][j]+B.values[i][j];
            }
        }
        Matriz resultante = create(A.linha,B.coluna);

        //atribui "values" da matriz "resultante" para "result"
        resultante.values = result;

        //retorna a matriz resultante
        return resultante;

    }else{

        printf("A operação não pode ser feita, as matrizes são imcompatíveis");

    }

}

Matriz sub_mat(Matriz A,Matriz B){

    //verifica se as matrizes são compatíveis com a operação
    if (verificamatrizes(A.linha,A.coluna,B.linha,B.coluna)==1){

        //aloca memória para a matriz resultante
        float **result = (float**)malloc(A.linha*sizeof(float*));
        for(int i=0;i<A.linha;i++){
            result[i] = (float*)malloc(A.coluna*sizeof(float));
        }

        //faz a subtração entre A e B e salva em result
        for(int i=0;i<A.linha;i++){
            for(int j=0;j<B.coluna;j++){
                 result[i][j] = A.values[i][j]-B.values[i][j];
            }
        }
        Matriz resultante = create(A.linha,B.coluna);

        //atribui "values" da matriz "resultante" para "result"
        resultante.values = result;

        //retorna a matriz resultante
        return resultante;

    }else{

        printf("A operação não pode ser feita, as matrizes são imcompatíveis");

    }

}