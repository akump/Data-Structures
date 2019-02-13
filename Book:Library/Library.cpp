/*
	Library implementation.
	Andrew Kump
	sept 2015
*/

#include <string>
#include <string.h>
#include <dirent.h>
#include <iostream>
#include <cmath>
#include <vector>
#include "Library.h"
#include <fstream>

using namespace std;

Library::Library(string folder){
  // Open a directory and read the contents
  DIR* directory = opendir(folder.c_str());
  dirent* ent = readdir(directory);
  while(ent){
    if(strlen(ent->d_name) > 2){ 
      string file_name = folder + ent->d_name;
      books.push_back(new Book(file_name));
    }
    ent = readdir(directory);
  }
  closedir(directory);
}
/*
Library::~Library(){
  for(unsigned int i = 0; i <= books.size(); i++){
   delete books[i];
  }
}
*/
int Library::getBookCount(){ 
  return books.size();
}

vector<string> Library::getBookTitles(){
  vector<string> ret;
  for(unsigned int i = 0; i < books.size(); i++){
    string title_print = books[i]->getTitle();
    ret.push_back(title_print);
  }
  return ret;
}
  
Book* Library::getBook(unsigned int i){
  if(i < 0 || i > books.size()){
    return (Book*)NULL;
  }
  return books[i];
}

Book* Library::getBook(string title){
  for(unsigned int i = 0; i <= books.size(); i++){
   return books[i];
  }
  return (Book*)NULL;
}

float Library::getSimilarity(Book* one, Book* two){
  vector<float> vector_one = one->letterPercent();
  vector<float> vector_two = two->letterPercent();
  float difference = 0;
  float difference2 = 0;
  for(unsigned int i = 0; i <= 25; i++){
    difference = difference +abs(vector_two[i] - vector_one[i]);
  }
  difference2 = difference/26;
  return difference2;
}
