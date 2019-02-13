#ifndef DLIST_H
#define DLIST_H

/*
	Templated Doubly Linked List class.
	Paul Talaga
	October 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct node_t {
  T value;
  node_t<T>* prev;
  node_t<T>* next;
};

// This implementation will use a head and tail pointers,
// allowing O(1) insertion on the front and end.
template <class T>
class DList{

  public:
  DList(){
   head = NULL;
   tail = NULL;
  }
  
  ~DList(){
		node_t<T>* temp = head;
    while(temp){
      node_t<T>* to_delete = temp;
      temp = temp->next;
      delete to_delete;
    }
    head = NULL;
    tail = NULL;
	}
	
  DList(const DList& other){
    head = NULL;
    node_t<T>* temp = other.head;
    while(temp){
      push_back(temp->value);
      temp = temp->next;
    }
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  DList<T>& operator= (const DList& other){  
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
    int the_size = size();
		if(pos < 0){
      pos = the_size + pos;
    }
    if(pos < 0){
      throw logic_error("Position outside of bounds!");
    }
	  if(pos >= the_size){
      throw logic_error("Position outside of bounds!");
    }
    
    int half_size = the_size/2;
    if(pos < half_size){ // For head start
      node_t<T>* temp = head;
       int i = 0;
       while(temp){
         if(i == pos){
          return temp->value; 
         }
         i++;
         temp = temp->next;
      }
    }
    
    else{ // For Tail start
      int j = the_size-1;
      node_t<T>* temp = tail;
      while(temp){
        if(j == pos){
          return temp->value;
        }
        j--;
        temp = temp->prev; 
      }
    }
		return T();
  }

  unsigned int size() const{
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
    else{
      node_t<T>* temp = tail;
      node_t<T>* new_node = new node_t<T>;
      new_node->value = thing;
      new_node->next = NULL;
      temp->next = new_node;
      tail = new_node;
      new_node->prev = temp;
    }
  }
  
  void push_front(T thing){
    if(size() == 0){
      node_t<T>* temp = new node_t<T>;
      temp->next = NULL;
      temp->value = thing;
      temp->prev = NULL;
      head = temp;
      tail = temp;
    }
    else{
      node_t<T>* temp = new node_t<T>;
      temp->next = head;
      temp->value = thing;
      temp->prev = NULL;
      head->prev = temp;
      head = temp;
    }
  }
	
	void setAt(T value, int pos){
	  int the_size = size();
	  if(pos < 0){
      pos = the_size + pos;
    }
    if(pos < 0){
      throw logic_error("Position outside of bounds!");
    }
	  if(pos >= the_size){
      throw logic_error("Position outside of bounds!");
    }
    
    int half_size = the_size/2;
    
    if(pos < half_size){ // For head start
      node_t<T>* temp = head;
       int i = 0;
       while(temp){
         if(i == pos){
          temp->value = value;
          return;
         }
         i++;
         temp = temp->next;
      }
    }
    
    else{ // For Tail start
      int j = the_size-1;
      node_t<T>* temp = tail;
       while(temp){
         if(j == pos){
           temp->value = value;
           return;
         }
         j--;
         temp = temp->prev; 
       }
    }
	}
	
	void remove(int pos){
	  int the_size = size();
	  if(pos < 0){
      pos = the_size + pos;
    }
	  if(pos >= the_size){
      throw logic_error("Position outside of bounds!");
    }
    if(the_size == 0){
      throw logic_error("Empty");
    }
    if(pos == 0){ 
      node_t<T>* temp = head;
      head = head->next;
      delete temp;
      return;
    }
    else if(pos == the_size - 1){
      node_t<T>* temp = tail;
      tail = tail->prev;
      tail->next = NULL;
      delete temp;
      return;
    }
    int half_size = the_size/2;
    if(pos < half_size){ // For head start
      node_t<T>* temp = head;
      unsigned int i = 0;
      while(temp){
         if(i == pos){
           node_t<T>* to_delete = temp;
           temp->prev->next = temp->next;
           temp->next->prev = temp->prev;
           delete to_delete;
           return;
         }
         i++;
         temp = temp->next; 
      }
    }
    // tail start
    else{
      node_t<T>* temp = tail;
      unsigned int j = the_size - 1;
      while(temp){
         if(j == pos){
           node_t<T>* to_delete = temp;
           temp->prev->next = temp->next;
           temp->next->prev = temp->prev;
           delete to_delete;
           return;
         }
         j--;
         temp = temp->prev; 
      }
      if(!temp){
        cout << "Bad index!\n";
        return;
      }
    }
	}
	
	DList<T> reverse() const{ 
	  DList<T> ret;
	  node_t<T>* temp = head;
	  while(temp){
	    ret.push_front(temp->value);
	    temp = temp->next;
	  }
	  return ret;
	}
	
	DList<T> operator+(const DList<T>& other) const{
		DList<T> ret;
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
	
	bool operator==(const DList<T>& other) const{
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
	
	bool operator!=(const DList<T>& other) const{
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
	
	// HW additions.
	unsigned int count(T thing){
	  unsigned int the_count = 0;
	  node_t<T>* temp = head;
    while(temp){
      if(temp->value == thing){
        the_count++;
      }
      temp = temp->next;
    }
		return the_count;
	}
	
	void splitHalf(DList<T>& a, DList<T>& b){
	  int the_size = size();
	  int half_size = the_size/2;
	  int i = 0;
	  node_t<T>* temp = head;
	  while(temp && i < half_size){
	    node_t<T>* to_delete = temp;
	    i++;
	    a.push_back(temp->value);
	    temp = temp->next;
	    delete to_delete;
	  }
	  while(temp){
	    node_t<T>* to_delete = temp;
	    b.push_back(temp->value);
	    temp = temp->next;
	    delete to_delete;
	  }
	  head = NULL;
	}
	
	void splitEveryOther(DList<T>& a, DList<T>& b){
	  //int the_size = size();
	  //&& i < the_size-1
	  int i = 0;
	  node_t<T>* temp = head;
	  while(temp){
	    if(i%2 == 0){ // a
	      node_t<T>* to_delete = temp;
	      a.push_back(temp->value);
	      temp = temp->next;
	      i++;
	      delete to_delete;
	    } // b
	    else{
	      node_t<T>* to_delete = temp;
	      b.push_back(temp->value);
	      temp = temp->next;
	      i++;
	      delete to_delete;
	    }
	  }
	  head = NULL;
	}
	
	void reverseThis(){
	  node_t<T>* current = head;
	  node_t<T>* next;
	  node_t<T>* previous = NULL;
	  tail = head;
	  while(current){
	    next = current->next;
	    current->next = previous;
	    current->prev = next;
	    previous = current;
	    current = next;
	  }
	  tail = head;
	  head = previous;
	}
	
	void doubleThis(){
	  node_t<T>* temp = head;
	  while(temp){
	    if(temp == NULL){
	      return;
	    }
	    node_t<T>* new_node = new node_t<T>;
	    new_node->next = temp->next;
	    new_node->value = temp->value;
	    temp->next = new_node;
	    new_node->prev = temp;
	    temp = temp->next->next;
	    if(temp == NULL){
	      tail = new_node;
	      return;
	    }
	    else{
	      temp->prev = new_node;
	    }
	  }
	}
	
	bool setEq(const DList<T>& other){
	  // Fill me in
	  int the_size = size();
	  int other_size = other.size();
	  if(the_size != other_size){
	    //cout << "sizes not eq" << endl;
	    return false;
	  }
	  int count = 0;
	  node_t<T>* temp = head;
	  node_t<T>* temp_other = other.head;
	  
	  while(temp){
	    while(temp_other){
	      if(temp->value == temp_other->value){
	        //cout << temp_other->value << endl;
	        count++;
	        temp_other = other.head;
	        break;
	      }
	      else{
	        temp_other = temp_other->next;
	      }
	    }
	    temp = temp->next;
	  }
	  if(count == the_size){
	    return true;
	  }
	  else{
	    return false;
	  }
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
  
  void printTail(){
    cout << "[";
    node_t<T>* temp = tail;
    while(temp){
      cout << temp->value;
      if(temp == head){
        break;
      }
      temp = temp->prev;
      cout << ",";
    }
    cout << "]\n";
  }
 
  
  private:
  node_t<T>* head;
  node_t<T>* tail;
  
};

// Note this function is O(n^2) because getAt is O(n) and we are
// doing it n times.
template <class T>
ostream& operator<<(ostream& out, const DList<T> other){
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
