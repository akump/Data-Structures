/*
	Implementation for Book class.
	Andrew Kump
	2015
*/

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Book.h"

using namespace std;

Book::Book(string filename){
  file = string("") ;
  book_print = string("");
  title = string("");
  title_print = string("");
  first = string("");
   first_print = string("");
  last = string("");
  last_print = string("");
  text = string("");
  text_print = string("");
  full_name = string("");
  first_print_space = string("");
  last_file = string("");
  first_file = string("");
  title_file = string("");
  new_title_print = string("");
  file = filename; 
  char character;
  int count = 1;
  text_print = '\n';
  string line;
  ifstream instream;
  instream.open(file.c_str());
  if(instream.is_open()){
    while(getline(instream, line)){ 
      character = line[0]; 
      if(character == '!'){
        if(count == 1){
          title_print = line;
          count++;
        }
        else if(count == 2){
          first_print = line;
          count++;
        }
        else if(count == 3){
          last_print = line;
          count++;
        }  
        
      }
      else if(count == 4){
        //string temp = " ";
        //temp[0] = character;
        text_print = text_print + line;
      }
    }
  }
  instream.close();
  //title_print = title_print.substr(6,9);
  //first_print = first_print.substr(13,6);
  //last_print = last_print.substr(12,8);
  int colon = 0;
  for(unsigned int m = 1; m<title_print.size(); m++){
    if(title_print[m] == ':'){
      colon = 1;
    }
    else if(title_print[m] == '!'){
      break;
    }
    else if(colon == 1){
      new_title_print = new_title_print + title_print[m];
    }
  }
  first_print_space = first_print + ' ';
  full_name = first_print_space  + last_print;

}
  
Book::Book(string title, string first, string last, string text){
  new_title_print = title;
  first_print = first;
  first_print_space = first + ' ';
  last_print = last;
  text_print = text;
  full_name = first_print_space  + last_print;
}
  
// Getters
string Book::getTitle(){
  return new_title_print;
}
  
string Book::getFullAuthor(){
  return full_name;
}
  
string Book::getAuthorFirst(){
  return first_print;
}
  
string Book::getAuthorLast(){
  return last_print;
}
  
unsigned int Book::getCharacterCount(){
  int char_count_text = text_print.size();
  return char_count_text;
}
  
unsigned int Book::getLineCount(){
  int line_count = 1;
  for (unsigned int i = 0; i<=text_print.size(); i++){
    if(text_print[i] == '\n'){
      line_count++;
    }
  }
  return line_count;
}
  
unsigned int Book::getWordCount(string word){
  int count = 0;
  word = " " + word + " ";
  for(unsigned int p = 0; p<=text_print.length(); p++){
    string short_text = text_print.substr(p, word.length());
    if(short_text.compare(word) == 0){
      count++;
    }
  }
  return count;
}


vector<float> Book::letterPercent(){
  vector<float> letters;
  int alpha_num = 0;
  int char_count = 0;
  for(unsigned int p = 0; p <= 25; p++){
    letters.push_back(0);
  }
  for(unsigned int i =0; i <= text_print.size(); i++){
    if(text_print[i] >= 'a' && text_print[i] <= 'z'){
      alpha_num = text_print[i] - 'a';
      letters[alpha_num] = letters[alpha_num] + 1;
      char_count++;
    }
    if(text_print[i] >= 'A' && text_print[i] <= 'Z'){
      alpha_num = text_print[i] - 'A';
      letters[alpha_num] = letters[alpha_num] + 1;
      char_count++;
    }
  }
  for(unsigned int j = 0; j<=25;j++){
    letters[j] = letters[j]/char_count;
  }
  return letters;
}
  
string Book::getText(){

  return text_print;
  
}


