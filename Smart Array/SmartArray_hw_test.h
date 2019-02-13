#ifndef SMARTARRAY_HW_TEST_H
#define SMARTARRAY_HW_TEST_H

#include "SmartArray.h"

#include <iostream>
#include <cxxtest/TestSuite.h>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

class SmartArrayAT : public CxxTest::TestSuite {  
public:
  void testAT1(){
    SmartArray<int> a(1,5);
    TS_ASSERT_EQUALS(a.at(0), 5);
  }
  
  void testAT2(){
    SmartArray<int> a(10,3);
    TS_ASSERT_EQUALS(a.at(7), 3);
  }
  
  void testAT3(){
    SmartArray<int> a(8,5);
    TS_ASSERT_EQUALS(a.at(5), 5);
  }
  
  void testAT4(){
    SmartArray<int> a(10,5);
    TS_ASSERT_EQUALS(a.at(5), 5);
  }
  
  void testAT5(){
    SmartArray<int> a(3,6);
    TS_ASSERT_EQUALS(a.at(2), 6);
  }
  
  void testBracket1(){
    SmartArray<int> a(5,5);
    TS_ASSERT_EQUALS(a[3], 5);
  }
  
  void testBracket2(){
    SmartArray<int> a(8,8);
    TS_ASSERT_EQUALS(a[3], 8);
  }
  
  void testBracket3(){
    SmartArray<int> a(3,4);
    TS_ASSERT_EQUALS(a[2], 4);
  }
};

class SmartArrayClear : public CxxTest::TestSuite {  
public:
  void testClear1(){
    SmartArray<int> a(10,3);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear2(){
    SmartArray<int> a(10,8);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear3(){
    SmartArray<int> a(5,3);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
};

class SmartArrayAdd : public CxxTest::TestSuite {  
public: 
  void testAdd1(){
    SmartArray<int> a(5,5);
    SmartArray<int> b(5,5);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c[7],5);
  }
  
  void testAdd2(){
    SmartArray<int> a(6,5);
    SmartArray<int> b(5,5);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c[8],5);
  }
  
  void testAdd3(){
    SmartArray<int> a(5,7);
    SmartArray<int> b(5,7);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c[7],7);
  }
  
   void testAdd4(){
    SmartArray<int> a(5,5);
    SmartArray<int> b(6,5);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c[7],5);
  }
  void testAdd5(){
    SmartArray<int> a(5,5);
    SmartArray<int> b(6,5);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c[9],5);
  }
};

class SmartArrayReverse : public CxxTest::TestSuite {  
public:
  void testReverse1(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(2);
    TS_ASSERT_EQUALS(a.reverse()[0],2);
  }
  
  void testReverse2(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(6);
    TS_ASSERT_EQUALS(a.reverse()[0],6);
  }
  
  void testReverse3(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(10);
    TS_ASSERT_EQUALS(a.reverse()[0],10);
  }
  
   void testReverse4(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(5);
    TS_ASSERT_EQUALS(a.reverse()[0],5);
  }
  
   void testReverse5(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(9);
    TS_ASSERT_EQUALS(a.reverse()[0],9);
  }
};

class SmartArrayEquality : public CxxTest::TestSuite {  
public:
   void testEqual1(){
    SmartArray<int> a(5,3);
    SmartArray<int> b(5,3);
    TS_ASSERT(a == b);
  }
  
  void testEqual2(){
    SmartArray<int> a(8,8);
    SmartArray<int> b(8,8);
    TS_ASSERT(a == b);
  }
  
  void testEqual3(){
    SmartArray<int> a(9,9);
    SmartArray<int> b(9,9);
    TS_ASSERT(a == b);
  }
  
  void testEqual4(){
    SmartArray<int> a(4,4);
    SmartArray<int> b(4,4);
    TS_ASSERT(a == b);
  }
  
  void testEqual5(){
    SmartArray<int> a(4,4);
    SmartArray<int> b(5,5);
    TS_ASSERT(a != b);
  }
  
  void testEqual6(){
    SmartArray<int> a(7,7);
    SmartArray<int> b(5,5);
    TS_ASSERT(a != b);
  }
  
  void testEqual7(){
    SmartArray<int> a(8,8);
    SmartArray<int> b(5,5);
    TS_ASSERT(a != b);
  }
  
  void testEqual8(){
    SmartArray<int> a(10,10);
    SmartArray<int> b(5,5);
    TS_ASSERT(a != b);
  }
};

class SmartArrayCopyAssignment : public CxxTest::TestSuite {  
public:
  void testCopy1(){
    SmartArray<int> a(5,10);
    SmartArray<int> b(a);
    a.push_back(10);
    TS_ASSERT_EQUALS(b.size(), 5);
  }
  
  void testCopy2(){
    SmartArray<int> a(10,10);
    SmartArray<int> b(a);
    a.push_back(10);
    TS_ASSERT_EQUALS(b.size(), 10);
  }
  
  void testCopy3(){
    SmartArray<int> a(15,10);
    SmartArray<int> b(a);
    a.push_back(10);
    TS_ASSERT_EQUALS(b.size(), 15);
  }
  
  void testCopy4(){
    SmartArray<int> a(9,5);
    SmartArray<int> b(a);
    a.push_back(10);
    TS_ASSERT_EQUALS(b.size(), 9);
  }
  
  void testCopy5(){
    SmartArray<int> a(20,10);
    SmartArray<int> b(a);
    a.push_back(10);
    TS_ASSERT_EQUALS(b.size(), 20);
  }
  
};

class SmartArrayStream : public CxxTest::TestSuite {  
public:
  // << tests
  void testStream1(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(6);
    // To test we stream to a stringstream, retrieve as a string,
    // remove spaces, then test the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6]");
  }
  
  void testStream2(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(8);
    // To test we stream to a stringstream, retrieve as a string,
    // remove spaces, then test the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,8]");
  }
  
  void testStream3(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(6);
    // To test we stream to a stringstream, retrieve as a string,
    // remove spaces, then test the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,6]");
  }
  
  void testStream4(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(9);
    // To test we stream to a stringstream, retrieve as a string,
    // remove spaces, then test the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,9]");
  }
  void testStream5(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(3);
    // To test we stream to a stringstream, retrieve as a string,
    // remove spaces, then test the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,3]");
  }
};

#endif
