#ifndef SMARTARRAY_H
#define SMARTARRAY_H
/*
	A smart array that can resize up to 1000 elements.
	Paul Talaga  
	September 2015
*/

#include <string>
#include <ostream>
#include <stdexcept>
#include <iostream>
#include <cmath>

using namespace std;

unsigned int SMART_ARRAY_CAPACITY = 1000;

// Fill in your SmartArray class here!
template <class T>
class SmartArray{
public:
  SmartArray(){
    the_size = 0;
    array = new T[SMART_ARRAY_CAPACITY];
  }
  
  SmartArray(unsigned int i, T thing){
    the_size = 0;
    array = new T[SMART_ARRAY_CAPACITY];
    for(unsigned int j = 0; j < i; j++){
      push_back(thing);
    }
  }
  
  SmartArray(const SmartArray<T>& right){
    the_size = 0;
    array = new T[SMART_ARRAY_CAPACITY];
    for(int i = 0; i < right.size(); i++){
      push_back(right[i]);
    }
  }
  
  void operator=(const SmartArray<T>& right){
    for(int i = 0; i < right.size(); i++){
      array[i] = right[i];
    }
    the_size = right.size();
  }
  
  ~SmartArray(){
    delete[] array;
  }
  
  void push_back(T thing){
    if(the_size >= SMART_ARRAY_CAPACITY){
      SMART_ARRAY_CAPACITY++;
      T* newarray = new T[SMART_ARRAY_CAPACITY];
      for(unsigned int i = 0; i < the_size; i++){
        newarray[i] = array[i];
      }
      delete[] array;
      array = newarray;
    }
    array[the_size] = thing;
    the_size++;
  }
  
  int size()const{
    return the_size;
  }
  
  T back(){
    if(the_size == 0){
      throw logic_error("Array is bad");
    }
    else{
      return array[the_size-1];
    }
  }
  
  void pop_back(){
    if(the_size == 0){
      throw logic_error("Array is bad");
    }
    else{
      the_size--;
    }
  }
  
  T at(int i)const {
    if(i >= the_size){
      throw logic_error("Index outside of bounds");
    }
    if(i < -the_size){
      throw logic_error("Index outside of bounds");
    }
    if(i < 0){
       return array[the_size + i];
    }
    return array[i];
  }
  
  T operator[] (int index)const{ 
    if(abs(index) > the_size){
      throw logic_error("Index outside of bounds");
    }
    if(index < 0){
      return array[the_size + index];
    }
    return array[index];
  }
  
  void clear(){
    delete[] array;
    the_size = 0;
    array = new T[SMART_ARRAY_CAPACITY];
  }
  
  SmartArray<T> reverse(){
    SmartArray<T> rev_array;
    for(int i = 0; i < the_size; i++){ 
      rev_array.push_back(array[the_size - i - 1]);
    }
    return rev_array;
  }
  
  SmartArray<T> operator+(const SmartArray<T>& right){
    SmartArray<T> a;
    if(the_size + right.size() > 1000){
      throw logic_error("You're bad"); 
    }
    for(int i = 0; i < the_size; i++){
      a.push_back(array[i]);
    }
    for(int i = 0; i < right.size(); i++){
      a.push_back(right[i]);
    }
    return a;
  }
  
  bool operator== (const SmartArray<T>& right){
    if(the_size == right.size()){
      for(int i = 0; i < the_size; i++){
        if(array[i] != right[i]){
          return false;
        }
      } 
    }
    if(the_size != right.size()){
      return false; 
    }
    return true;
  }
  
  bool operator!= (const SmartArray<T>& right){
    if(the_size != right.size()){
      return true; 
    }
    if(the_size == right.size()){
      for(int i = 0; i < the_size; i++){
        if(array[i] != right[i]){
          return true;
        }
      } 
     return false;
    }
  }
  
  
  private:
  T* array;
  int the_size;
  
};

template <class T>
  ostream& operator<< (ostream& out, const SmartArray<T>& number){
    out << "[";
    for(int i = 0; i < number.size(); i++){
      out << number[i];
      if(i != number.size() - 1){
        out << ",";
      }
    }
    out << "]";
    return out;
  }

#endif
