#include "complexo.c"

void main(){

    //declara as variáveis necesárias
    int a, b, n;

    //pede o valor dos números complexos ao usuário e cria os números correspondentes
    printf("Insira o primeiro número complexo:\n a = ");
    scanf("%f %f",&a,&b);
    complex A = create(a,b);
    printf("Insira o segundo número complexo:\n b = ");
    scanf("%f %f",&a,&b);
    complex B = create(a,b);

    //pede ao usuário qual operação deve ser executada
    printf("Qual é a operação desejada?\n (1)(a+b)\n(2)(a-b)\n(3)(b-a)\n(4)(a*b)\n(5)(a/b)\n(6)(b/a)(7)mod(a)\n(8)mod(b)\n");
    scanf("%d",&n);

    //realiza a operação de acordo com o número fornecido
    if(n==1){

        printf("O número complexo resultante é:\n");
        complex result = soma(A,B);
        printf("%f %s %f %s",result.real," + ",result.imag,"i");

    }else if(n==2){

        printf("O número complexo resultante é:\n");
        complex result = sub(A,B);
        printf("%f %s %f %s",result.real," + ",result.imag,"i");

    }else if(n==3){

        printf("O número complexo resultante é:\n");
        complex result = sub(B,A);
        printf("%f %s %f %s",result.real," + ",result.imag,"i");
        
    }else if(n==4){

        printf("O número complexo resultante é:\n");
        complex result = mul(A,B);
        printf("%f %s %f %s",result.real," + ",result.imag,"i");
        
    }else if(n==5){
    
        printf("O número complexo resultante é:\n");
        complex result = divi(A,B);
        printf("%f %s %f %s",result.real," + ",result.imag,"i");

    }else if(n==6){

        printf("O número complexo resultante é:\n");
        complex result = divi(B,A);
        printf("%f %s %f %s",result.real," + ",result.imag,"i");
        
    }else if(n==7){

        printf("A norma do número imaginário é:\n");
        printf("%f %s",modo(A),"\n");
        
    }else if(n==8){

        printf("A norma do número imaginário é:\n");
        printf("%f %s",modo(B),"\n");
        
    }


}