#ifndef BST_H
#define BST_H

/*
   Binary Search Tree claiv.
   Paul Talaga
   October 2015
 */
#include <ostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <stdlib.h> 

using namespace std;

template <class T>
class Node{
  public: 
  Node(Node* left, Node* right, T value)
  :data(value),left(left),right(right){};
  T data;
  Node* left;
  Node* right;
};
template <class T>
class BST {

public:
  BST( int (*f)(const T&, const T&) ){
    cmpfn = f;
    thesize = 0;
    root = NULL;
  }

  ~BST() {
    deleteall(root);
	  root=NULL;
    thesize = 0;
  }

  BST(const BST& other){
    root = NULL;
    thesize = 0;
    cmpfn = other.cmpfn;
    copy(other.root);
    for(int i = 0; i < temp.size();i++){
      insert(temp[i]);
      //cout << temp[i] << ","; 
    }
  }
	
  BST<T>& operator= (const BST& other){  
		if(this != &other){
		  clear();
		  copy(other.root);
		  for(int i = 0; i < temp.size();i++){
        insert(temp[i]);
        //cout << temp[i] << ","; 
      }
		}
		return *this;
	}
  
  void insert(T thing){
    thesize++;
    if(!root){
      root = new Node<T>(NULL,NULL,thing);
      return;
    }
    insert(root, thing);
  }
  
  bool find(const T& thing) const{
    bool found = false;
    find(root, thing, found);
    return found;
  }

  unsigned int size() const{
    return thesize;
  }
  
  T getSmallest() const{
    /*Node<T>* temp = root;
    while(temp->left){
      temp = temp->left;
    }
    return temp->data;*/
    return getSmallest(root);
  }
  
  T getLargest() const{
    /*Node<T>* temp = root;
    while(temp->right){
      temp = temp->right;
    }*/
    return getLargest(root);
  }
  
	void clear(){
	  deleteall(root);
	  root=NULL;
    thesize = 0;
	}
	

	string getInOrder() const{
	  if(thesize==0){
	    return "[]";
	  }
	  stringstream pv;
	  stringstream iv;
	  int count = 0;
	  getInOrder(root, iv);
	  string value;
	  while( iv >> value){
	    if(count == 0){
	      pv << "[";
	    }
	    pv << value;
	    
	    if(count != thesize -1){
	      pv << ",";
	    }
	    if(count == thesize -1){
	      pv << "]";
	    }
	    count++;
	  }
	  return pv.str();
    
  }
  
  string getPreOrder() const{
    if(thesize==0){
	    return "[]";
	  }
    int count = 0;
    stringstream pv;
    stringstream iv;
    getPreOrder(root, iv);
    string value;
	  while( iv >> value){
	    if(count == 0){
	      pv << "[";
	    }
	    pv << value;
	    
	    if(count != thesize -1){
	      pv << ",";
	    }
	    if(count == thesize -1){
	      pv << "]";
	    }
	    count++;
	  }
    return pv.str();
  }
  
  string getPostOrder() const{
    if(thesize==0){
	    return "[]";
	  }
    int count = 0;
    stringstream pv;
    stringstream iv;
    getPostOrder(root, iv);
    string value;
	  while( iv >> value){
	    if(count == 0){
	      pv << "[";
	    }
	    pv << value;
	    
	    if(count != thesize -1){
	      pv << ",";
	    }
	    if(count == thesize -1){
	      pv << "]";
	    }
	    count++;
	  }
    return pv.str();
  }
 
  // End Lab aivignment ---------------------------------------
  
  // Start HW aivignment --------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  //--------------------------------------
  unsigned int getHeight(){
    if(!root){
      return 0;
    }
    return getHeight(root) - 1;
    //return 0;
  }
  
  bool isFull() const{
    if(size() ==0){
      return true;
    }
    if(size() % 2){
      return true;
    }
    return false;
  }
  
  bool isBalanced() const{
    return isBalanced(root);
  }
  
  
  
private:
  Node<T>* root;
  int thesize;
  int (*cmpfn)(const T& left, const T& right);
  vector<T> temp;
  
  T getSmallest(Node<T>* node) const{
    if(!node){
      throw logic_error("should not have gotten here!");
      //return 0;
    }
    if(node->left == NULL){
      return node->data;
    }
    //else{
     // getSmallest(node->left);
    //}
    return getSmallest(node->left);
  }
  
  T getLargest(Node<T>* node) const{
    if(!node){
      throw logic_error("should not have gotten here!");
      //return 0;
    }
    if(node->right == NULL){
      return node->data;
    }
    //else{
      //getLargest(node->right);
    //}
    return getLargest(node->right);;
  }
  
  
  
  void insert(Node<T>* node, T thing){
    if(!node){
  		throw logic_error("should not have gotten here!");
  	}
    if( (*cmpfn)(thing, node->data) <= 0){
      if(node->left){
        insert(node->left,thing);
      }
      else{
        node->left = new Node<T>(NULL,NULL,thing);
      }
    }
    else{
      if(node->right){
        insert(node->right,thing);
      }
      else{
        node->right = new Node<T>(NULL,NULL,thing);
      }
    }
    return;
  }
  
  
  void find(Node<T>* node, T thing, bool& found) const{
    if(!node){
      found = false;
      return;
    }
    if(node->data == thing){
      found = true;
      return;
    }
    
    if( (*cmpfn)(thing, node->data) <= 0){
      if(!node->left){
        return;
      }
      if(node->left->data == thing){
        found = true;
        return;
      }
      else{
        find(node->left, thing, found);
      }
    }
    else{
      if(!node->right){
        return;
      }
      if(node->right->data == thing){
        found = true;
        return;
      }
      else{
        find(node->right, thing, found);
      }
    }
  }
  
  
  void getInOrder(Node<T>* node, stringstream& iv) const{
    if(!node){
      return;
    }
    else{
      
      
      getInOrder(node->left, iv);
      iv << node->data << " ";
      getInOrder(node->right, iv);
    }
  }
  
  void getPreOrder(Node<T>* node, stringstream& iv) const{
    if(!node){
      return;
    }
    else{
      
      iv<<node->data << " ";
      getPreOrder(node->left, iv);
      getPreOrder(node->right, iv);
    }
  }
  void getPostOrder(Node<T>* node, stringstream& iv) const{
    if(!node){
      return;
    }
    else{
      getPostOrder(node->left, iv);
      getPostOrder(node->right, iv);
      iv<<node->data << " ";
    }
  }
  
  void deleteall(Node<T>* node) const{
    if(!node){
      return;
    }
    if(node->left != NULL){
      deleteall(node->left);
    }
    if(node->right != NULL){
      deleteall(node->right);
    }
    delete node;
  }
  
  void copy(Node<T>* node){
    if(!node){
      return;
    }
    else{
      temp.push_back(node->data);
      copy(node->left);
      copy(node->right); 
    }
  }
  
  unsigned int getHeight(Node<T>* node) const{
	  if(!node){
	    return 0;
	  }
	  return 1 + max(getHeight(node->left), getHeight(node->right));
	}
  
  /*bool isBalanced(Node<T>* node) const{
    if(!node){
      return false;
    }
    int left = getHeight(node->left);
    int right = getHeight(node->right);
    if(abs(left-right) <= 1){
      return true;
    }
    else{
      return false;
    } 
  }*/
  bool isBalanced(Node<T>* node) const{
    if(!node){
      return true; 
    }
    int dif = getHeight(node->left) - getHeight(node->right);;
    if(abs(dif) <= 1){
      return isBalanced(node->left) && isBalanced(node->right);
    }
    else{
      return false;
    }
}
  
  bool isFull(Node<T>* node){
    if(!node){
      return true;
    }
  }
  
  
  
  
  // TODO  Hint, you may have many functions down here!
  
};

#endif
