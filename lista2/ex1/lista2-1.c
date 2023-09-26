#include <stdio.h>
#include "complex.c"

int main() {
  // menu...
  double x1,y1,x2,y2;
  int number;
  printf("Enter coordinates for a complex number (e.g. '2 3' for 2+3i):\na = ");
  scanf("%lf %lf", &x1, &y1);
  printf("Enter coordinates for another complex number (e.g. '1 -2' for 1-2i):\nb = ");
  scanf("%lf %lf", &x2, &y2);
  printf("Now enter a number to choose which operation to perform (e.g. 1 to add a and b, 2 to subtract b from a,...):\n1)a + b \n2)a - b\n3)b - a\n4)a * b\n5)a / b\n6)b / a\n7)absolute value of a\n8)absolute value of b\n\nEnter: ");
  scanf("%d",&number);
  printf("\n");

  Complex a = create(x1,y1);
  Complex b = create(x2,y2);

  if (number == 1) {
  Complex c = add(a,b);
  printf("a + b = %lf + %lfi\n",real_part(c),imag_part(c));
  } 
  else if (number == 2) {
  Complex c = sub(a,b);
  printf("a - b = %lf + %lfi\n",real_part(c),imag_part(c));
 
  } 
  else if (number == 3) {
  Complex c = sub(b,a);
  printf("b - a = %lf + %lfi\n",real_part(c),imag_part(c));
 
  } 
  else if (number == 4) {
  Complex c = mult(a,b);
  printf("a * b = %lf + %lfi\n",real_part(c),imag_part(c));
 
  } 
  else if (number == 5) {
  Complex c = divide(a,b);
  printf("a / b = %lf + %lfi\n",real_part(c),imag_part(c));
 
  } 
  else if (number == 6) {
  Complex c = divide(b,a);
  printf("b / a = %lf + %lfi\n",real_part(c),imag_part(c));
 
  } 
  else if (number == 7) {
  printf("Absolute value of a: %lf\n",absolute(a));
  } 
  else if (number == 8) {
  printf("Absolute value of b: %lf\n",absolute(b));
  } 
  else {
    printf("INVALID ENTRY\n");
    return 0;
  }

  return 0;
}
