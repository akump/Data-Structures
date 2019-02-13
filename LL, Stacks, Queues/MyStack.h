#ifndef MySTACK_H
#define MYSTACK_H

/*
	Stack implementation using a LList.
	Andrew KUmp
	September 2015
*/
#include <ostream>
#include <stdexcept>
#include <stack>

#include "LList.h"

using namespace std;


template <class T>
class MyStack{

  public:
  MyStack(){
    the_size = 0;
  }
  
  MyStack(const LList<T>& list){
    the_size = 0;
    for(int i = 0; i < list.size(); i++){
      the_size++;
      s.push(list.getAt(i));
    }
  }
  
  void enqueue(T value){ 
    the_size++;
    s.push(value);
  }
  
  void dequeue(){
    if(the_size == 0){
      return;
    }
    s.pop();
    the_size--;
  }
  
  void push(T value){
    the_size++;
    s.push(value);
  }
  
  void pop(){
    if(the_size == 0){
      return;
    }
    s.pop();
    the_size--;
  }
  
  
  T top(){
    if(the_size == 0){
      throw logic_error("Empty");
    }
    T ret;
    ret = s.top();
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
  stack<T> s;
  unsigned int the_size;
  
  

};

#endif
