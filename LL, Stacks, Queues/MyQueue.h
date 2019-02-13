#ifndef MYQUEUE_H
#define MYQUEUE_H

/*
	Queue implementation using a LList.
	Andrew Kump
	September 2015
*/
#include <ostream>
#include <stdexcept>
#include <queue>

#include "LList.h"

using namespace std;


template <class T>
class MyQueue{

  public:
  MyQueue(){
    the_size = 0;
  }
  MyQueue(const LList<T>& list){
    the_size = 0;
    for(int i = 0; i < list.size(); i++){
      the_size++;
      q.push(list.getAt(i));
    }
  }
  
  void enqueue(T value){
    the_size++;
    q.push(value);
  }
  
  void dequeue(){
    if(the_size == 0){
      return;
    }
    q.pop();
    the_size--;
  }
  
  void push(T value){
    the_size++;
    q.push(value);
  }
  
  void pop(){
    if(the_size == 0){
      return;
    }
    q.pop();
    the_size--;
  }
  
  
  
  T front(){
    if(the_size == 0){
      throw logic_error("Empty");
    }
    T ret;
    ret = q.front();
    return ret;
  }
  
  unsigned int size() const{
    return the_size;
  }
  
  bool isEmpty(){
    if(the_size == 0){
      return true;
    }
    else{
      return false;
    }
  }
  private:
  queue<T> q;
  unsigned int the_size;

};

#endif
