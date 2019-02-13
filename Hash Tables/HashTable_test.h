#ifndef HASHTABLE_TEST_H
#define HASHTABLE_TEST_H

#include "HashTable.h"
#include <stdexcept>
#include <string>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>
#include <ctime>

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

const int SIZE = 2000;  // Size of Linked List to test speed.

// Some useful hash functions
unsigned int hash(const int& number){
  return abs(number);
}

unsigned int hash(const string& word){
  unsigned int ret = 0;
  for(unsigned int i = 0; i < word.length(); i++){
    ret += word[i] * i + i * 47;
  }
  return ret;
}

class HashTableInsertSizeCap : public CxxTest::TestSuite {
public:

  void testEmpty() {
    HashTable<int> a(hash, 5);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void testEmpty2() {
    HashTable<int> a(hash, 5);
    a.clear();
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  void testEmpty3() {
    HashTable<int> a(hash, 10);
    a.insert(5);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 10);
  }
  
  void testEmpty4() {
    HashTable<int> a(hash, 10);
    HashTable<int> b(a);
    a.clear();
    TS_ASSERT_EQUALS(b.capacity(), 10);
  }
  
  void testInsert1() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void testInsert2() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  void testInsert3() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(b.size(), 0);
    TS_ASSERT_EQUALS(b.capacity(), 5);
  }
  
  void testInsert4() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  // TODO
};

class HashTableClear : public CxxTest::TestSuite {
public:

  // TODO
  void testclear() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  void testclear2() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  void testclear3() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  void testclear4() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    HashTable<int> b(a);
    a.clear();
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(b.capacity(), 5);
  }
  void testclear5() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(b.capacity(), 5);
  }
  
};

class HashTableConCopyAssign : public CxxTest::TestSuite {
   
public:
  // Copy Constructor
	void testCopy() {
    HashTable<int> a(hash,5);
    a.insert(5);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
  
  void testCopy2() {
    HashTable<int> a(hash,5);
    a.insert(5);
    a.clear();
    a.insert(5);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
  
  void testCopy3() {
    HashTable<int> a(hash,5);
    a.insert(5);
    a.clear();
    a.insert(5);
    a.insert(1);
    a.remove(5);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
  
  void testCopy4() {
    HashTable<int> a(hash,5);
    a.insert(5);
    a.clear();
    a.insert(5);
    a.insert(6);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 2);
  }
  
  void testCopy5() {
    HashTable<int> a(hash,5);
    a.insert(5);
    a.clear();
    a.insert(5);
    a.remove(5);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(b.size(), 0);
  }
  
  void testCopy6() {
    HashTable<int> a(hash,5);
    a.insert(5);
    a.clear();
    a.insert(5);
    a.remove(5);
    a.insert(6);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
// TODO
  
};

class HashTableInsertFind : public CxxTest::TestSuite {
public:
  void testInsertFind1(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
  
  void testInsertFind2(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
  
  void testInsertFind3(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    a.remove(5);
    a.insert(6);
    TS_ASSERT(a.find(6));
  }
  void testInsertFind4(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  void testInsertFind5(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
  void testInsertFind6(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
  
  void testInsertFind7(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testInsertFind8(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    a.insert(5);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  void testInsertFind9(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT(!a.find(4));
  }
  void testInsertFind10(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(205);
    a.remove(5);
    TS_ASSERT(a.find(205));
  }
  
  void testInsertFind11(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(205);
    a.insert(305);
    a.remove(205);
    TS_ASSERT(a.find(305));
  }
  
  void testInsertFind12(){
    HashTable<int> a(hash, 5);
    a.insert(4);
    a.remove(4);
    TS_ASSERT(!a.find(4));
  }
  // TODO
  
};

class HashTableRemove : public CxxTest::TestSuite {
public:

  void testRm1() {
    HashTable<int> a(hash, 5);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  
  void testRm2() {
    HashTable<int> a(hash, 5);
    a.remove(5);
    a.clear();
    a.insert(5);
    
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testrm3() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void tesrm4() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.clear();
    a.insert(5);
    TS_ASSERT(a.find(5));
    a.insert(6);
    a.remove(5);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
    

  }
  void testRm5() {
    HashTable<int> a(hash, 5);
    a.remove(5);
    a.insert(5);
    a.insert(5);
    a.insert(5);
    a.insert(5);
    a.remove(5);
    
    TS_ASSERT(!a.find(5));
  }
  // TODO
};


#endif
