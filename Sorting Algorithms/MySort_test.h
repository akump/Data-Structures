#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "MySort.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cxxtest/TestSuite.h>

using namespace std;

class selectionSortTests : public CxxTest::TestSuite {
public:
  
  void test1() {
      srand(time(0));
    vector<int> a;
    int s = 4;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      selectionSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test2() {
    vector<int> a;
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test3() {
    vector<int> a;
    a.push_back(1);
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test4() {
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test5(){
    vector<int> a;
    a.push_back(14);
    a.push_back(13);
    a.push_back(-4);
    a.push_back(99);
    
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test6(){
      srand(time(0));
    vector<int> a;
    int s = 250;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      selectionSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test7() {
    srand(time(0));
    vector<int> a;
    int s = 10000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      selectionSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test8() {
    srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      selectionSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test9() {
    srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      TS_ASSERT_EQUALS(isSorted(a), 0);
  }
  
  void test10() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    selectionSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }

};

class bubbleSortTests : public CxxTest::TestSuite {
public:
  

  
  void test1() {
      srand(time(0));
    vector<int> a;
    int s = 4;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      bubbleSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test2() {
    vector<int> a;
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test3() {
    vector<int> a;
    a.push_back(1);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test4() {
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test5(){
    vector<int> a;
    a.push_back(14);
    a.push_back(13);
    a.push_back(-4);
    a.push_back(99);
    
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test6(){
      srand(time(0));
    vector<int> a;
    int s = 250;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      bubbleSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test7() {
      srand(time(0));
    vector<int> a;
    int s = 10000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      bubbleSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test8() {
      srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      bubbleSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test9() {
    srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      TS_ASSERT_EQUALS(isSorted(a), 0);
  }
  
  void test10() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    bubbleSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
};

class mergeSortTests : public CxxTest::TestSuite {
public:
  

  
  void test1() {
      srand(time(0));
    vector<int> a;
    int s = 4;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      mergeSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test2() {
    vector<int> a;
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test3() {
    vector<int> a;
    a.push_back(1);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test4() {
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test5(){
    vector<int> a;
    a.push_back(14);
    a.push_back(13);
    a.push_back(-4);
    a.push_back(99);
    
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test6(){
      srand(time(0));
    vector<int> a;
    int s = 250;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      mergeSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test7() {
      srand(time(0));
    vector<int> a;
    int s = 10000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      mergeSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test8() {
      srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      mergeSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test9() {
    srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      TS_ASSERT_EQUALS(isSorted(a), 0);
  }
  
  void test10() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }

};

class quickSortTests : public CxxTest::TestSuite {
public:
  

  
  void test1() {
      srand(time(0));
    vector<int> a;
    int s = 4;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      quickSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test2() {
    vector<int> a;
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test3() {
    vector<int> a;
    a.push_back(1);
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test4() {
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test5(){
    vector<int> a;
    a.push_back(14);
    a.push_back(13);
    a.push_back(-4);
    a.push_back(99);
    
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test6(){
      srand(time(0));
    vector<int> a;
    int s = 250;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      quickSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test7() {
      srand(time(0));
    vector<int> a;
    int s = 10000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      quickSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test8() {
      srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      quickSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test9() {
    srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      TS_ASSERT_EQUALS(isSorted(a), 0);
  }
  
  void test10() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    quickSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }

};


class heapSortTests : public CxxTest::TestSuite {
public:
  
  
  void test1() {
      srand(time(0));
    vector<int> a;
    int s = 4;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      heapSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test2() {
    vector<int> a;
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test3() {
    vector<int> a;
    a.push_back(1);
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test4() {
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test5(){
    vector<int> a;
    a.push_back(14);
    a.push_back(13);
    a.push_back(-4);
    a.push_back(99);
    getMax(a);
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test6(){
    srand(time(0));
    vector<int> a;
    int s = 250;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      heapSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test7() {
      srand(time(0));
    vector<int> a;
    int s = 10000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      heapSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test8() {
      srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      heapSort(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test9() {
    srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      TS_ASSERT_EQUALS(isSorted(a), 0);
  }
  
  void test10() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    heapSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }

};



class mergeSort2Tests : public CxxTest::TestSuite {
public:
  

  
  void test1() {
      srand(time(0));
    vector<int> a;
    int s = 4;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      mergeSort2(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test2() {
    vector<int> a;
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test3() {
    vector<int> a;
    a.push_back(1);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test4() {
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test5(){
    vector<int> a;
    a.push_back(14);
    a.push_back(13);
    a.push_back(-4);
    a.push_back(99);
    
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test6(){
      srand(time(0));
    vector<int> a;
    int s = 250;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      mergeSort2(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test7() {
      srand(time(0));
    vector<int> a;
    int s = 10000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      mergeSort2(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test8() {
      srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      mergeSort2(a);
      TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  
  void test9() {
    srand(time(0));
    vector<int> a;
    int s = 20000;
      for(int i = 0; i < s; i++){
          a.push_back(rand() % 20);
      }
      TS_ASSERT_EQUALS(isSorted(a), 0);
  }
  
  void test10() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test11() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test12() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test13() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test14() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test15() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test16() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test17() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test18() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test19() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test20() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    mergeSort2(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
  void test21() {
    vector<int> a;
    a.push_back(12.1);
    a.push_back(12.09999);
    a.push_back(12.11111);
    nonCompareSort(a);
    TS_ASSERT_EQUALS(isSorted(a), 1);
  }
};

#endif
