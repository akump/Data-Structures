#ifndef PREFIX_TEST_H
#define PREFIX_TEST_H

#include "Prefix.h"
#include <string>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>
#include <ctime>

using namespace std;


// Fill me in!
class isStored : public CxxTest::TestSuite {
public:
  void testisStored(){
    Prefix a;
    a.insert("a");
    TS_ASSERT_EQUALS(a.isStored("a"), 1);

  }
  void testisStored1(){
    Prefix b;
    b.insert("abc");
    TS_ASSERT_EQUALS(b.isStored("abc"), 1);

  }
  void testisStored2(){
    Prefix c;
    c.insert("a b c");
    TS_ASSERT_EQUALS(c.isStored("a b c"), 1);

  }
  void testisStored3(){
    Prefix d;
    d.insert("a");
    TS_ASSERT_EQUALS(d.getNumNodes(), 2);

  }
  void testisStored4(){
    Prefix a;
    a.insert("a b");
    TS_ASSERT_EQUALS(a.getNumNodes(), 4);

  }
  void testisStored5(){
    Prefix f;
    f.insert("a");
    Prefix a(f);
    TS_ASSERT_EQUALS(a.isStored("a"), 1);

  }
  void testisStored6(){
    Prefix g;
    g.insert("a b");
    Prefix a(g);
    TS_ASSERT_EQUALS(a.isStored("a b"), 1);

  }
  void testisStored7(){
    Prefix h;
    h.insert("a b c");
    Prefix a(h);
    TS_ASSERT_EQUALS(h.isStored("a b c"), 1);

  }
   void testisStore8(){
    Prefix i;
    i.insert("a");
    i.insert("and");
    i.insert("andrew");
    TS_ASSERT_EQUALS(i.isStored("a"), 1);
    TS_ASSERT_EQUALS(i.isStored("and"), 1);
    TS_ASSERT_EQUALS(i.isStored("andrew"), 1);

  }
  void testisStored9(){
    Prefix j;
    j.insert("a");
    TS_ASSERT_EQUALS(j.getHeight(), 1);

  }
  void testisStored10(){
    Prefix k;
    k.insert("abcbc");
    TS_ASSERT_EQUALS(k.getHeight(), 5);

  }
  void testisStored11(){
    Prefix l;
    l.insert("ab");
    TS_ASSERT_EQUALS(l.getHeight(), 2);

  } 
  void testisStored12(){
    Prefix a;
    a.insert("a");
    TS_ASSERT_EQUALS(a.getNumStored(), 1);

  }
  void testisStored13(){
    Prefix b;
    b.insert("a");
    b.insert("c");
    TS_ASSERT_EQUALS(b.getNumStored(), 2);

  }
  void testisStored14(){
    Prefix c;
    c.insert("a");
    c.insert("and");
    c.insert("andrew");
    TS_ASSERT_EQUALS(c.getNumStored(), 3);

  }
  void testisStored15(){
    Prefix d;
    d.insert("a");
    d.insert("arew");
    d.insert("auyeerw");
    TS_ASSERT_EQUALS(d.getNumStored(), 3);

  }
  void testisStored16(){
    Prefix e;
    e.insert("a");
    TS_ASSERT_EQUALS(e.getNumWPrefix("a"), 1);

  }
  void testisStored17(){
    Prefix f;
    f.insert("a");
    f.insert("and");
    TS_ASSERT_EQUALS(f.getNumWPrefix("a"), 2);

  }
  void testisStored18(){
    Prefix g;
    g.insert("a");
    g.insert("and");
    g.insert("andrew");
    TS_ASSERT_EQUALS(g.getNumWPrefix("and"), 2);

  }
  void testisStored19(){
    Prefix h;
    h.insert("a");
    h = h;
    TS_ASSERT_EQUALS(h.getNumWPrefix("a"), 1);

  }
   void testisStore20(){
    Prefix i;
    i.insert("a");
    Prefix a;
    a = i;
    TS_ASSERT_EQUALS(a.isStored("a"), 1);

  }
  void testisStored21(){
    Prefix j;
    j.insert("and");
    j.insert("and teh");
    Prefix a;
    a = j;
    TS_ASSERT_EQUALS(a.isStored("and"), 1);

  }
  void testisStored22(){
    Prefix k;
    k.insert("a");
    k.insert("and");
    k.insert("and teh");
    Prefix a;
    a = k;
    TS_ASSERT_EQUALS(k.isStored("and teh"), 1);

  }
 
};

#endif
