#ifndef HASHTABLE_H
#define HASHTABLE_H

/*
	String Hash Table class.
	Uses open addressing - linear probing.
	Andrew Kump
	October 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;
template <class T>
struct item{
  T value;
  int isUsed;
  //0 = false
  //1 = true
  //2 = deleted
};

template <class T>
class HashTable{

  public:
  HashTable( unsigned int (*f)(const T&), unsigned int capacity){
    the_size = 0;
    table_capacity = capacity;
    hashfn = f;
    array = new item<T>[table_capacity];
    for(unsigned int i = 0; i < table_capacity; i++){
       array[i].isUsed = 0; // just set everything to 0
    }
  }

  ~HashTable() {
    delete[] array;
  }

  HashTable(const HashTable& other){
    table_capacity = other.table_capacity;
    hashfn = other.hashfn;
    array = new item<T>[table_capacity];
    for(int i = 0; i < other.table_capacity; i++){
      array[i] = other.array[i];
    }
    the_size = other.size();
  }
	
  HashTable<T>& operator= (const HashTable& other){  
		if(this == &other){
      return *this;
    }
    clear();
    for(int i = 0; i < other.table_capacity; i++){
      array[i] = other.array[i];
    }
    the_size = other.size();
	}
    
     
  bool find(T thing) const{
    unsigned int location = (*hashfn)(thing)%table_capacity; 
    unsigned int orig_location = location;
    if(the_size == 0){ // empty? ofc its not in there
      return false;
    }
    if(array[location].isUsed == 0){ // is its location empty? ofc its empty
      return false;
    }
		else{
		  while(array[location].isUsed > 0){ // find it. skip over 2
		    if(array[location].value == thing && array[location].isUsed == 1){
		      return true; // in order to find it, it must be 1 and there
		    }
		    location++;
		    location = location%table_capacity;
		    if(location == orig_location){
		      return false; //did you loop through it once already?
		    }
		  }
		}	
		return false;
  }
  

  unsigned int size() const{
    return the_size;
  }
  
  unsigned int capacity() const{
    return table_capacity;
  }
  
  bool isFull() const{
    if(the_size == table_capacity){
      return true;
    }
    else{
      return false;
    }  
  }
  
 
  void insert(T thing){
    unsigned int location = (*hashfn)(thing)%table_capacity;
   
    if(the_size == table_capacity){  // full?
      throw logic_error("table full");
    }
    
    if(find(thing) == 1){//already in there?
      return;
    }
    
    if(array[location].isUsed == 1){ // If somethings there do linear probing
      while(array[location].isUsed ==1){ // can insert in 0 or 2 position
          location++;
          location = location%table_capacity;
      }
    }
    array[location].value = thing;// now change at this location
    array[location].isUsed = 1;
    the_size++;
  }
  
  
  void remove(T thing){
    unsigned int location = (*hashfn)(thing)%table_capacity;
    unsigned int orig_location = location; //if full and loops through
    if(the_size == 0){ // is hash talbe empty?
      return;
    }
    if(find(thing)==0){ // not in there?
      return;
    }
    
    if(array[location].isUsed == 0){ // is it there?
      return;
    }
    else{
      while(array[location].isUsed > 0){
          if(array[location].value == thing && array[location].isUsed == 1){
            array[location].isUsed = 2;
            the_size--; //This removes
            return;
          }
          if(array[location].value == thing && array[location].isUsed == 2){
            return; // Is it there but was deleted earlier?
          }
          location++;
          location = location%table_capacity;
          if(location == orig_location){
		        return; // did you loop around already?
		      }
        }
      }
    }
  
	
	void clear(){
		the_size = 0;
		for(unsigned int i = 0; i < table_capacity; i++){
        array[i].isUsed = 0;
    }
	}
	
 
  
  private:
  item<T>* array;
  unsigned int table_capacity;
  unsigned int the_size;
  unsigned int (*hashfn)(const T& thing);
  
};

#endif
