#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo.h"

complex create(int a, int b){

    //cria o complexo resultante
    complex result;

    //define as variáveis necessárias
    result.real = a;
    result.imag = b;

    //retorna o complexo
    return result;
}

int modo(complex A){

    //retorna a raiz da soma do quadrado da parte real pelo quadrado da parte imaginária
    return sqrt(A.real*A.real + A.imag*A.imag);

}


complex soma(complex A, complex B){

    //retorna a soma dos números complexos
    return create(A.real+B.real,A.imag+B.imag);

}

complex sub(complex A, complex B){

    //retorna a subtração dos números complexos
    return create(A.real-B.real,A.imag-B.imag);

}

//declara a função que retorna a multiplicação de dois números complexos
complex mul(complex A, complex B){

    //retorna a multiplicação dos números complexos
    return create(A.real*B.real - A.imag*B.imag,A.real*B.imag + A.imag*B.real);

}

//declara a função que retorna a divizão de dois números complexos
complex divi(complex A, complex B){

    //retorna a divisão dos números complexos
    return create( (A.real*B.real - A.imag*B.imag)/(B.real*B.real + B.imag*B.imag),(A.imag*B.real - A.real*B.imag)/(B.real*B.real + B.imag*B.imag) );

}