#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
  double real;
  double imag;
} Complex;

double sqrt(double x);

Complex create(double a, double b);

Complex add(Complex a, Complex b);

Complex sub(Complex a, Complex b);

Complex mult(Complex a, Complex b);

Complex divide(Complex a, Complex b);

double real_part(Complex a);

double imag_part(Complex a);

double absolute(Complex a);

