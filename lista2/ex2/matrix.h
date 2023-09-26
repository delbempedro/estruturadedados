//declara a estrutura da matriz
typedef struct Matriz{

    float linha,coluna;
    float **values;

}Matriz;

//declara a função geradora da matriz
Matriz create(int a, int b);
//declara uma função que preeenche a matriz com valores inseridos no terminal
void preenche(Matriz A);
//declara a função multiplicação de matrizes
Matriz mult_mat(Matriz A, Matriz B,int n);
//define a operação auxiliar de multiplicação
int elevar(int a, int n);
//declara a função soma de matrizes
Matriz sum_mat(Matriz A, Matriz B);
//declara a função subtração de matrizes
Matriz sub_mat(Matriz A, Matriz B);
//imprimi uma matriz no terminal
void imprimir(Matriz A);