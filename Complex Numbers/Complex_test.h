#ifndef COMPLEX_TEST_H
#define COMPLEX_TEST_H

#include <Complex.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

const double delta = 0.0001;
// Multiple test classes are used so groups of functions can be tested
// independently.
class ComplexGetters : public CxxTest::TestSuite {  
public:
  void testGetReal1(){
    TS_ASSERT_DELTA(Complex(5,5).getReal(), 5, delta);
  }
  void testGetReal2(){
    TS_ASSERT_DELTA(Complex(6,5).getReal(), 6, delta);
  }
  void testGetReal3(){
    TS_ASSERT_DELTA(Complex(2,5).getReal(), 2, delta);
  }
  void testGetComplex1(){
    TS_ASSERT_DELTA(Complex(5,5).getImaginary(), 5, delta);
  }
  void testGetComplex2(){
    TS_ASSERT_DELTA(Complex(6,2).getImaginary(), 2, delta);
  }
  void testGetComplex3(){
    TS_ASSERT_DELTA(Complex(2,3).getImaginary(), 3, delta);
  }
  
};

class ComplexAdd : public CxxTest::TestSuite {  
public:
  void testAdd1() {
    TS_ASSERT_EQUALS(Complex(2,3) + Complex(2,3), Complex(4,6));
  }
  void testAdd2() {
    TS_ASSERT_EQUALS(Complex(1,1) + Complex(1,1), Complex(2,2));
  }
  void testAdd3() {
    TS_ASSERT_EQUALS(Complex(0,0) + Complex(0,1), Complex(0,1));
  }
  
  
};

class ComplexSub : public CxxTest::TestSuite {  
public:
  
  void testSub1() {
    TS_ASSERT_EQUALS(Complex(1,1) - Complex(0,1), Complex(1,0));
  }
  void testSub2() {
    TS_ASSERT_EQUALS(Complex(2,2) - Complex(1,1), Complex(1,1));
  }
  void testSub3() {
    TS_ASSERT_EQUALS(Complex(6,3) - Complex(1,1), Complex(5,2));
  }
  
};

class ComplexMult : public CxxTest::TestSuite {  
public:
  
  void testMult() {
    TS_ASSERT_EQUALS(Complex(1,1) * Complex(0,1), Complex(0,1));
  }
  void testMult2() {
    TS_ASSERT_EQUALS(Complex(2,2) * Complex(2,1), Complex(4,2));
  }
  void testMult3() {
    TS_ASSERT_EQUALS(Complex(6,3) * Complex(1,1), Complex(6,3));
  }
   void testMult4() {
    TS_ASSERT_EQUALS(Complex(1,1) * Complex(1,1), Complex(1,1));
  }
  void testMult5() {
    TS_ASSERT_EQUALS(Complex(2,2) * Complex(2,2), Complex(4,4));
  }
  void testMult6() {
    TS_ASSERT_EQUALS(Complex(6,3) * Complex(1,3), Complex(6,9));
  }
  
};

class ComplexEquality : public CxxTest::TestSuite {  
public:
  
  void testEqual1(){
    TS_ASSERT(Complex(6,7) == Complex(6,7));
  }
  void testEqual2(){
    TS_ASSERT(Complex(5,5) == Complex(5,5));
  }
  void testEqual3(){
    TS_ASSERT(Complex(1,1) == Complex(1,1));
  }
  void testnonEqual4(){
    TS_ASSERT(! (Complex(1,5) != Complex(2,6)));
  }
  void testnonEqual5(){
    TS_ASSERT(! (Complex(3,5) != Complex(2,6)));
  }
  void testEqual6(){
    TS_ASSERT(! (Complex(7,5) != Complex(2,6)));
  }
   
  
};

class ComplexConjugate : public CxxTest::TestSuite {  
public:
  void testequal1(){
    TS_ASSERT_EQUALS(Complex(5,5).conjugate(), Complex(5,-5));
  }
  void testequal2(){
    TS_ASSERT_EQUALS(Complex(5,1).conjugate(), Complex(5,-1));
  }
  void testequal3(){
    TS_ASSERT_EQUALS(Complex(5,3).conjugate(), Complex(5,-3));
  }
  
   
 
  
};

#endif
