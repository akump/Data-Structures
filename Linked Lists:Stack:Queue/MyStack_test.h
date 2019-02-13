#ifndef MYSTACK_TEST_H
#define MYSTACK_TEST_H

#include <MyStack.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

class MyStackTests : public CxxTest::TestSuite {
   
public:
  
		// Insert at least 20 unit tests!
		void testEnqueue1(){
    LList<int> list;
    list.push_back(1);
    list.push_back(2);
    MyStack<int> test(list);
    test.enqueue(1);
    TS_ASSERT_EQUALS(test.size(), 3);
  }
  
  void testEnqueue2(){
    LList<int> list;
    list.push_back(0);
    list.push_back(2);
    MyStack<int> test(list);
    test.enqueue(1);
    test.enqueue(1);
    test.enqueue(1);
    test.enqueue(1);
    test.enqueue(1);
    TS_ASSERT_EQUALS(test.size(), 7);
  }
  
  void testEnqueue3(){
    LList<int> list;
    list.push_back(0);
    list.push_back(2);
    MyStack<int> test(list);
    test.enqueue(1);
    test.enqueue(1);
    TS_ASSERT_EQUALS(test.size(), 4);
  }
  void testEnqueue4(){
    LList<int> list;
    MyStack<int> test(list);
    TS_ASSERT_EQUALS(test.size(), 0);
  }
  void testEnqueue5(){
    LList<int> list;
    list.push_back(0);
    list.push_back(2);
    MyStack<int> test(list);
    test.enqueue(1);
    test.dequeue();
    test.enqueue(1);
    test.dequeue();
    TS_ASSERT_EQUALS(test.size(), 2);
  }
  void testEmpty1(){
    LList<int> list;
    list.push_back(1);
    list.push_back(2);
    MyStack<int> test(list);
    test.dequeue();
    test.dequeue();
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
  
  void testEmpty2(){
    LList<int> list;
    MyStack<int> test(list);
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
  
  void testEmpty3(){
    LList<int> list;
    list.push_back(17);
    MyStack<int> test(list);
    test.dequeue();
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
  void testEmpty4(){
    LList<int> list;
    MyStack<int> test(list);
    list.push_back(17);
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
  void testEmpty5(){
    LList<int> list;
    list.push_back(17);
    MyStack<int> test(list);
    test.dequeue();
    list.clear();
    TS_ASSERT_EQUALS(test.isEmpty(), 1);
  }
	void testTop1(){
    LList<int> list;
    list.push_back(17);
    list.push_back(1);
    list.push_back(7);
    MyStack<int> test(list);
    TS_ASSERT_EQUALS(test.top(), 7);
  }
  void testTop2(){
    LList<int> list;
    list.push_back(17);
    list.push_back(1);
    list.push_back(7);
    MyStack<int> test(list);
    test.enqueue(1);
    TS_ASSERT_EQUALS(test.top(), 1);
  }
  void testTop3(){
    LList<int> list;
    list.push_back(17);
    list.push_back(1);
    list.push_back(7);
    MyStack<int> test(list);
    test.enqueue(1);
    test.dequeue();
    TS_ASSERT_EQUALS(test.top(), 7);
  }
  void testTop4(){
    LList<int> list;
    list.push_back(17);
    list.push_back(1);
    list.push_back(7);
    MyStack<int> test(list);
    list.clear();
    TS_ASSERT_EQUALS(test.top(), 7);
  }
  void testTop5(){
    LList<int> list;
    list.push_back(17);
    list.push_back(1);
    list.push_back(7);
    MyStack<int> test(list);
    list.reverse();
    test.enqueue(1);
    TS_ASSERT_EQUALS(test.top(), 1);
  }
};


#endif
