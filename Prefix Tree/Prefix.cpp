/*
   Trie (Prefix) class for storing and retrieving strings.
   Paul Talaga
   November 2015
 */
#include <iostream>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "Prefix.h"

using namespace std;

// fill me in!

Prefix::Prefix(){
  root = new Node_t;
  total_words = 0;
  total_nodes = 1;
  height =0;
}

Prefix::Prefix(const Prefix& copy){
  root = new Node_t;
  total_words = 0;
  total_nodes = 1;
  height =0;
  vector<string> a = copy.getAllStored();
  for(unsigned int i = 0; i < a.size(); i++){
    insert(a[i]);
  }
}

Prefix& Prefix::operator=(const Prefix &other){
  if(this == &other){
    return *this;
  }
  clearAll();
  root = new Node_t;
  total_words = 0;
  total_nodes = 1;
  height = 0;
  vector<string> a = other.getAllStored();
  for(unsigned int i = 0; i < a.size(); i++){
    insert(a[i]);
  }
  return *this;
}

Prefix::~Prefix(){
  //clearAll();
  //delete root;
}


void empty(Node_t* node){
  for(int i = 0; i < 27; i++){
    if(node->links[i]){
      empty(node->links[i]);
    }
    delete node->links[i];
  }
}

void Prefix::clearAll(){
  empty(root);
  total_words = 0;
  total_nodes = 1;
  height = 0;
}

int getLinksValue(char c){
  if(isalpha(c)){
    return int(tolower(c)-96);
  }
  return 26; //space
}

void nullMyNode(Node_t* node){
  for(unsigned int i = 0; i < 27; i++){
    node->links[i] = NULL;
  }
}


bool Prefix::insert(string thing){
  Node_t* current = root;
  int temp_height = 0;
  if(thing.length() == 0){
    current->word = true;
    return true;
  }

  for(unsigned int i = 0; i < thing.length(); i++){
    if(current->links[getLinksValue(thing[i])] == NULL){
      current->links[getLinksValue(thing[i])]= new Node_t;
      nullMyNode(current->links[getLinksValue(thing[i])]);
      total_nodes++;
    }
    current = current->links[getLinksValue(thing[i])];
    temp_height++;
  }
  if(temp_height > height){
    height = temp_height;
  }
  if(current->word == true){ // already in there?
    return true;
  }
  current->word = true;
  total_words++;
  return true;
}

void transverse( string const& prefix, Node_t* node, vector<string> &vec){
  if(node->word == true){
    vec.push_back(prefix);
  }
  for(unsigned int i =0; i < 27; i++){
    if(node->links[i]){
      int a;
      if(i == 26){
        a = ' ';
      }else{
        a = i + 'a' - 1;
      }
      transverse(prefix+char(a), node->links[i], vec);
    }
  }
}
	
	
int Prefix::getHeight(){
  return height;
}

int Prefix::getNumNodes(){
  return total_nodes;
}

int Prefix::getNumStored(){
  return total_words;
}

vector<string> Prefix::getWPrefix(string thing){
  Node_t* current = root;
  for(unsigned int i = 0; i < thing.length(); i++){
    current = current->links[getLinksValue(thing[i])];
  }
  vector<string> vec;
  string prefix = "";
  transverse(prefix,current,vec);
  for(unsigned int j = 0; j < vec.size(); j++){
    vec[j] = thing + vec[j];
  }
  return vec;
}

vector<string> Prefix::getAllStored() const {
  vector<string> words;
  if(total_words == 0){
    return words;
  }
  string prefix = "";
  transverse(prefix,root,words);
  return words;
}

int Prefix::getNumWPrefix(string thing){
  Node_t* current = root;
  for(unsigned int i =0 ; i < thing.length(); i++){
    if(current->links[getLinksValue(thing[i])]){
      current = current->links[getLinksValue(thing[i])];
    }else{
      return 0;
    }
  }
  vector<string> vec;
  string prefix = "";
  transverse(prefix,current,vec);
  return vec.size();
}
	
bool Prefix::isStored(string thing){
  Node_t* current = root;
  for(unsigned int i = 0; i < thing.length(); i++){
    if(current->links[getLinksValue(thing[i])] == NULL){
      return false;
    }
    current = current->links[getLinksValue(thing[i])];
  }
  if(current->word == true){
    return true;
  }
  return false;
}
