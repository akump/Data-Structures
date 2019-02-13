#ifndef LLIST_H
#define LLIST_H

/*
	Templated Linked List class.
	Paul Talaga
	September 2015
*/
#include <ostream>
#include <stdexcept>
#include <iostream>

using namespace std;

// This is a templated struct.  You don't need to change this.
template <class T>
struct node_t{
  T value;
  node_t<T>* next;
};


// Change this class!
template <class T>
class LList{

  public:
  LList(){
    head = NULL;
  }
  
  ~LList(){
    node_t<T>* temp = head;
    while(temp){
      node_t<T>* to_delete = temp;
      temp = temp->next;
      delete to_delete;
    }
    head = NULL;
  }
	
  LList(const LList& other){
    head = NULL;
    node_t<T>* temp = other.head;
    while(temp){
      push_back(temp->value);
      temp = temp->next;
    }
  }
	
  LList<T>& operator= (const LList& other){
    if(this == &other){
      return *this;
    }
    clear();
    node_t<T>* temp = other.head;
    while(temp){
      push_back(temp->value);
      temp = temp->next;
    }
    return *this;
  }
     
  T getAt(int pos) const{
    node_t<T>* temp = head;
    int i = 0;
    if(pos < 0){
      pos = size() + pos;
    }
    if(pos < 0){
      throw logic_error("Position outside of bounds!");
    }
	  if(pos >= size()){
      throw logic_error("Position outside of bounds!");
    }
    while(temp){
      if(i == pos){
        return temp->value;
      }
      temp = temp->next;
      i++;
    }
    return 0;
  }

  int size() const{
    node_t<T>* temp = head;
    unsigned int i = 0;
    while(temp){
      i++;
      temp = temp->next;
    }
    return i;
  }
 
  void push_back(T thing){
    if(head == NULL){
      push_front(thing); 
      return;
    }
    node_t<T>* temp = head;
    while(temp->next){
      temp = temp->next;
    }
    node_t<T>* new_node = new node_t<T>;
    new_node->value = thing;
    new_node->next = NULL;
    temp->next = new_node;
  }
  
  void push_front(T thing){
    node_t<T>* temp = new node_t<T>;
    temp->next = head;
    temp->value = thing;
    head = temp;
  }
	
	void setAt(T value, int pos){
	  node_t<T>* temp = head;
	  if(pos < 0){
      pos = size() + pos;
    }
    if(pos < 0){
      throw logic_error("Position outside of bounds!");
    }
	  if(pos >= size()){
      throw logic_error("Position outside of bounds!");
    }
    unsigned int i = 0;
    while(temp){
      if(i == pos){
        temp->value = value;
        return;
      }
      i++;
      temp = temp->next;
    }
	}
	
	void remove(int pos){
	  if(pos < 0){
      pos = size() + pos;
    }
	  if(pos >= size()){
      throw logic_error("Position outside of bounds!");
    }
    if(size() == 0){
      throw logic_error("Empty");
    }
    if(pos == 0){ 
      node_t<T>* temp = head;
      head = head->next;
      delete temp;
      return;
    }
    node_t<T>* temp = head;
    while(temp && pos > 1){
      pos--;
      temp = temp->next;
    }
    if(!temp){
      cout << "Bad index!\n";
      return;
    }
    node_t<T>* to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
	}
	
	LList<T> reverse() const{ 
	  LList<T> ret;
	  node_t<T>* temp = head;
	  while(temp){
	    ret.push_front(temp->value);
	    temp = temp->next;
	  }
	  return ret;
	}
	
	LList<T> operator+(const LList<T>& other) const{
	  LList<T> ret;
	  node_t<T>* temp = head;
	  while(temp){
	    ret.push_back(temp->value);
	    temp = temp->next;
	  }
	  temp = other.head;
	  while(temp){
	    ret.push_back(temp->value);
	    temp = temp->next;
	  }
	  return ret;
	}
	
	bool operator==(const LList<T>& other) const{
	  node_t<T>* temp = head;
	  node_t<T>* temp_other = other.head;
	  if(size() != other.size()){
	    return false;
	  }
	  while(temp){
	    if(temp->value != temp_other->value){
	      return false;
	    }
	    temp = temp->next;
	    temp_other = temp_other->next;
	  }
	  return true;
	}
	
	bool operator!=(const LList<T>& other) const{
	  node_t<T>* temp = head;
	  node_t<T>* temp_other = other.head;
	  if(size() != other.size()){
	    return true;
	  }
	  while(temp){
	    if(temp->value != temp_other->value){
	      return true;
	    }
	    temp = temp->next;
	    temp_other = temp_other->next;
	  }
	  return false;
	}
	
	void clear(){
	  node_t<T>* temp = head;
    while(temp){
      node_t<T>* to_delete = temp;
      temp = temp->next;
      delete to_delete;
    }
    head = NULL;
	}
	
  void print(){
    cout << "[";
    node_t<T>* temp = head;
    while(temp){
      cout << temp->value;
      temp = temp->next;
      if(temp == NULL){
        break;
      }
      cout << ",";
    }
    cout << "]\n";
  }
  
  private:
  node_t<T>* head;
};

template <class T>
ostream& operator<<(ostream& out, const LList<T> other){
    out << "[";
    for(int i = 0; i < other.size(); i++){
      out << other.getAt(i);
      if(i + 1 == other.size()){
        break;
      }
      out << ",";
    }
    
    
    out << "]";
	return out;
}


#endif
