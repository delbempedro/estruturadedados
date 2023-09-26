#include"matrix.c"

void main(){

    //declara as variáveis em que serão salvos as dimensões das matrizes
    int m,n;

    //declara a variável que corresponderá à operação desejada
    int number;

    //declara o possível número de vezes que as matrizes serão multiplicadas

    //pede ao usuário as dimensôes das matrizes
    printf("Insira as dimensões da matriz A:\n");
    scanf("%d %d",&m,&n);
    Matriz A = create(m,n);
    printf("Insira os valores da matriz A:\n");
    preenche(A);

    printf("Insira as dimensões da matriz B:\n");
    scanf("%d %d",&m,&n);
    Matriz B = create(m,n);
    printf("Insira os valores da matriz B:\n");
    preenche(B);

    //pede ao usuário qual operação deve ser executada
    printf("Escolha um número correspondete à operação você deseja fazer\n(1)A+B\n(2)B+A\n(3)A-B\n(4)B-A\n(5)(A*B)^n\n(6)(B*A)^n\n");
    scanf("%d",&number);

    //cria a matriz em que será salvo o resultado
    Matriz resultado = create(m,n);

    //executa a operação desejada
    if(number>4){
        //declara a variável para a N-éssima multiplicação
        int num;

        printf("Quantas vezes você deseja multiplicar a matriz?\n");
        scanf("%d",&num);

        //(a*b)^n = (b*a)^n
        resultado = mult_mat(A,B,n);

    }else if(number>2){
        if(number==3){
            resultado = sub_mat(A,B);
        }else{
            resultado = sub_mat(B,A);
        }
    }else{

        //a+b = b+a
        resultado = sum_mat(A,B);

    }

    //imprimi o resultado na tela
    imprimir(resultado);

    freematriz(A);
    freematriz(B);
    freematriz(resultado);

}