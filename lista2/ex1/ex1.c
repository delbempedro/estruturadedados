#include <stdio.h>
#include "complex.c"

int main() {
  // menu...
  double x1,y1,x2,y2;
  int number;
  printf("Enter coordinates for a complex number (e.g. '2 3' for 2+3i):\na = ");
  scanf("%lf %lf", &x1, &y1);//5 7
  printf("Enter coordinates for another complex number (e.g. '1 -2' for 1-2i):\nb = ");
  scanf("%lf %lf", &x2, &y2);//8 -9
  printf("Now enter a number to choose which operation to perform (e.g. 1 to add a and b, 2 to subtract b from a,...):\n1)a + b \n2)a - b\n3)b - a\n4)a * b\n5)a / b\n6)b / a\n7)absolute value of a\n8)absolute value of b\n\nEnter: ");
  scanf("%d",&number);
  printf("\n");

  Complex a = create(x1,y1);
  Complex b = create(x2,y2);

  if (number == 1) {
  Complex c = add(a,b);
  printf("a + b = %lf + %lfi\n",real_part(c),imag_part(c));//a + b = 13.000000 - 2.000000 i
  } 
  else if (number == 2) {
  Complex c = sub(a,b);
  printf("a - b = %lf + %lfi\n",real_part(c),imag_part(c));//a - b = -3.000000 + 16.000000 i
 
  } 
  else if (number == 3) {
  Complex c = sub(b,a);
  printf("b - a = %lf + %lfi\n",real_part(c),imag_part(c));//b - a = 3.000000  - 16.000000 i
 
  } 
  else if (number == 4) {
  Complex c = mult(a,b);
  printf("a * b = %lf + %lfi\n",real_part(c),imag_part(c));//a * b = 103.000000 + 11.000000i
 
  } 
  else if (number == 5) {
  Complex c = divide(a,b);
  printf("a / b = %lf + %lfi\n",real_part(c),imag_part(c));//a / b = -0.158621 + 0.696552i
 
  } 
  else if (number == 6) {
  Complex c = divide(b,a);
  printf("b / a = %lf + %lfi\n",real_part(c),imag_part(c));//b / a = -0.310811 + -1.364865i
 
  } 
  else if (number == 7) {
  printf("Absolute value of a: %lf\n",absolute(a));//Absolute value of a: 8.602325
  } 
  else if (number == 8) {
  printf("Absolute value of b: %lf\n",absolute(b));//Absolute value of b: 12.041595
  } 
  else {
    printf("INVALID ENTRY\n");
    return 0;
  }

  return 0;
}

/*
o código foi escrito por:
Pedro Calligaris Delbem
N°USP: 5255417
e
Tony Maciel Alexander
N°USP: 12624850
no  editor vscode e utilizando a simulação de terminal
do mesmo, compilou-se o código com o comando ' gcc -o ex1.exe ex1.c ' e
executou-se o código com o comando ' ./ex1.exe ' o que inicializa o código
*/
