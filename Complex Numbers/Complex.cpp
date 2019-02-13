/*
	Simple complex number class.
	Paul Talaga
	August 2015
*/
#include <ostream>
#include <cmath>

#include "Complex.h"

using namespace std;

// Fill in the class implementation here!

Complex::Complex(const double& real){
  this->real = real;
}

Complex::Complex(const double& real, const double& complex){
  this->real = real;
  this->complex = complex;
}

double Complex::getReal() const{
  return this->real;
}

double Complex::getImaginary() const {
  return this->complex;
}

Complex Complex::operator+(const Complex& right){
  Complex ret(this->getReal() + right.getReal(),this->getImaginary() + right.getImaginary());
   return ret;
}

Complex Complex::operator-(const Complex& right){
  Complex ret(this->getReal() - right.getReal(),this->getImaginary() - right.getImaginary());
  return ret;
}

Complex Complex::operator*(const Complex& right){
  Complex ret(this->getReal() * right.getReal(),this->getImaginary() * right.getImaginary());
  return ret;
}


bool Complex::operator== (const Complex& right){
   double real_equal = this->getReal() - right.getReal();
   double complex_equal = this->getImaginary() - right.getImaginary();
   if((real_equal <= .001 || real_equal >= -.001) && (complex_equal <= .001 || complex_equal >= -.001)){
     return true;
   }
   return 0;
}

bool Complex::operator!= (const Complex& right){
   double real_equal = this->getReal() - right.getReal();
   double complex_equal = this->getImaginary() - right.getImaginary();
  if((real_equal > .001 || real_equal < -.001) && (complex_equal > .001 || complex_equal < -.001)){
     return false;
   }
   return 0;
}




Complex Complex::conjugate(){
  //double real = this->getReal();
  Complex ret(this->getReal(),-(this->getImaginary()));
  return ret;
}



ostream& operator<< (ostream& out, const Complex& number){
  out << "(" << number.getReal() << " + " << number.getImaginary() << "i)"; 
  return out;
}
