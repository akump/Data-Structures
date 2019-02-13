/*
	Dictionary lookup program.
	Paul Talaga
	October 2015
*/

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"

using namespace std;

// Good hash function for strings
unsigned int hash(const string& thing){
  unsigned int ret = 7;
  for(unsigned int i = 0; i < thing.length(); i++){
    ret = ret * 31 * thing[i];
    // 31 is the next prime above 26
  }
  return ret;
}

unsigned int hash(const int& number){
  return abs(number);
}


int main(int argc, char* argv[]){
  // Change me!
  // Example of how to pass a function to a function.
  // This will pass the above hash function to the class.
  char* file_name = argv[1];
  HashTable<string> test(hash, 200000);
  string line;
  string input;
  
  ifstream file; // file stuff
  file.open(file_name);

  if(file.is_open()){
    while(file){
      getline(file,line); // put words into hash table;
      test.insert(line);
    }
  }
  else{
    cout << "coulnt open" << endl;
  }
  
  file.close(); //close

  cout << "Words Loaded: " << test.size() << endl; // # of words
  while(input != "q"){
  cout << "Enter word: ";
  cin >> input; // input your word
  if(input == "q"){
    return 0;
  }
  if(test.find(input) == 1){ // looks for your word
    cout << "FOUND!" << endl;
  }
  else{
    cout << "Not Found." << endl;
  }
  
  string orig_word = input;
  
  cout << "Similiar words: ";
  for(unsigned int i = 0; i < input.length();i++){ //Transpose
    char orig_char = input[i];
    for(unsigned int a = 97; a <=122; a++){
      input[i] = a;
      if(input == orig_word){
        continue;
      }
      else if(test.find(input) == 1){ 
        cout << input << " ";
      }
    }
    input[i] = orig_char;
  }
  
  for(unsigned int i = 0; i < input.length();i++){ // Delete
    input.erase(i,1); 
    if(test.find(input) == 1){
      cout << input << " ";
    }
    input = orig_word;
  }
  const char* letters[] = {"a","b","c","d","e","f","g","h",
  "i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","y","x","z"};
  for(unsigned int i = 0; i <= input.length(); i++){
    for(unsigned int a = 0; a <26; a++){
      //const char* temp = letters[a];
      input.insert(i,letters[a]);
      //cout << input << endl;
      if(test.find(input) == 1){
        cout << input << " ";
      }
      input = orig_word;
    }
  }
  cout << endl;
  }
  //string testone = "andre";
  //testone.insert(5,"w");
  //cout << testone << endl;
  
  /*HashTable<string> test(hash, 10);
  test.insert("bob");
  cout << "bob? " << test.find("bob") << endl;
  cout << "Size: " << test.size() << endl;
  
  HashTable<int> a(hash, 5);
    a.insert(3);
    a.insert(2);
    a.insert(1);
    a.insert(5);
    a.insert(4);
    
    a.remove(5);

    a.remove(3);
    a.remove(2);
    a.remove(1);
    cout << "found? " << a.find(4) << endl;
    cout << "size: " <<a.size() << endl;*/
  
  
  return 0;
}
