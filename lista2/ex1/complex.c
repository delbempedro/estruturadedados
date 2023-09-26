#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

double sqrt(double x) {
  // calculates square root of a nummber using newton's approximation.
  // basically: let y = x^2 - r , where r is the number you want to find the square root of.
  // the goal is to find the root of y.
  // Guess a number initially. calculate y(x) and the derivative/slope at that point.
  // find new x1 position that is closer to the root of the function.
  // repeat for a bit (quadratic convergence)..
  double x0, y0, x1;
  x1 = x0 = x; // initial guess
  for (int i = 0; i < 10; i++) {
  y0 = x0 * x0 - x; 
  x1 = x1 - y0/(2.0*x1);
  x0 = x1;
  }
  return x0;
}

Complex create(double a, double b) {
  Complex res;
  res.real = a;
  res.imag = b;
  return res;
}

Complex add(Complex a, Complex b) {
  return create(a.real + b.real, a.imag + b.imag);
}

Complex sub(Complex a, Complex b) {
   return create(a.real - b.real, a.imag - b.imag);
}

Complex mult(Complex a, Complex b) {
  double x, y;
  x = a.real * b.real - a.imag * b.imag;
  y = a.real * b.imag + a.imag * b.real;
  return create(x,y);
}

Complex divide(Complex a, Complex b) {
  double x, y;
  x = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
  y = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
  return create(x,y);
}

double real_part(Complex a) {
  return a.real;
}

double imag_part(Complex a) {
  return a.imag;
}

double absolute(Complex a) {
  return sqrt(a.real * a.real + a.imag * a.imag);
}