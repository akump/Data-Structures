#ifndef MYQUEUE_TEST_H
#define MYQUEUE_TEST_H

#include <MyQueue.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

class MyQueueTests : public CxxTest::TestSuite {
   
public:
  
  
// Insert at least 20 unit tests

  void testEnqueue1(){
    LList<int> list;
    list.push_back(1);
    list.push_back(2);
    MyQueue<int> test(list);
    test.enqueue(1);
    TS_ASSERT_EQUALS(test.size(), 3);
  }
  
  void testEnqueue2(){
    LList<int> list;
    list.push_back(1);
    MyQueue<int> test(list);
    test.enqueue(1);
    TS_ASSERT_EQUALS(test.size(), 2);
  }
  void testEnqueue3(){
    LList<int> list;
    list.push_back(1);
    MyQueue<int> test(list);
    test.enqueue(1);
    test.dequeue();
    test.dequeue();
    test.dequeue();
    test.dequeue();
    TS_ASSERT_EQUALS(test.size(), 0);
  }
  
  void testEnqueue4(){
    LList<int> list;
    list.push_back(1);
    list.push_back(2);
    MyQueue<int> test(list);
    test.enqueue(1);
    test.enqueue(1);
    test.enqueue(1);
    test.enqueue(1);
    test.enqueue(1);
    TS_ASSERT_EQUALS(test.size(), 7);
  }
  
  void testEnqueue5(){
    LList<int> list;
    list.push_back(1);
    list.push_back(2);
    MyQueue<int> test(list);
    test.dequeue();
    test.dequeue();
    TS_ASSERT_EQUALS(test.size(), 0);
  }
  
  void testEmpty1(){
    LList<int> list;
    list.push_back(1);
    list.push_back(2);
    MyQueue<int> test(list);
    test.dequeue();
    test.dequeue();
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
  
  void testEmpty2(){
    LList<int> list;
    MyQueue<int> test(list);
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
  
  void testEmpty3(){
    LList<int> list;
    list.push_back(17);
    MyQueue<int> test(list);
    test.dequeue();
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
  
  void testEmpty4(){
    LList<int> list;
    list.push_back(17);
    list.push_back(17);
    list.push_back(17);
    MyQueue<int> test(list);
    test.dequeue();
    test.enqueue(1);
    test.dequeue();
    test.dequeue();
    test.dequeue();
    test.dequeue();
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
  
  void testEmpty5(){
    LList<int> list;
    list.push_back(17);
    MyQueue<int> test(list);
    test.dequeue();
    list.push_back(17);
    test.dequeue();
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
  void testFront1(){
    LList<int> list;
    list.push_back(17);
    MyQueue<int> test(list);
    TS_ASSERT_EQUALS(test.front(), 17);
  }
  void testFront2(){
    LList<int> list;
    list.push_back(17);
    MyQueue<int> test(list);
    test.enqueue(1);
    TS_ASSERT_EQUALS(test.front(), 17);
  }
  void testFront3(){
    LList<int> list;
    list.push_back(17);
    MyQueue<int> test(list);
    test.enqueue(1);
    test.enqueue(1);
    test.enqueue(3);
    TS_ASSERT_EQUALS(test.front(), 17);
  }
  void testFront4(){
    LList<int> list;
    list.push_back(17);
    MyQueue<int> test(list);
    test.enqueue(1);
    test.dequeue();
    TS_ASSERT_EQUALS(test.front(), 1);
  }
  void testFront5(){
    LList<int> list;
    list.push_back(17);
    MyQueue<int> test(list);
    test.enqueue(1);
    test.dequeue();
    test.enqueue(2);
    test.dequeue();
    TS_ASSERT_EQUALS(test.front(), 2);
  }
  
};


#endif
