typedef struct complex{
    int real, imag;
}complex;

//cria um número complexo dado dois parâmetros
complex create(int a,int b);
//declara a função que retorna a norma do número complexo
int modo(complex A);
//declara a função que retorna a soma de dois números complexos
complex soma(complex A, complex B);
//declara a função que retorna a subtração de dois números complexos
complex sub(complex A, complex B);
//declara a função que retorna a multiplicação de dois números complexos
complex mul(complex A, complex B);
//declara a função que retorna a divisão de dois números complexos
complex divi(complex A, complex B);