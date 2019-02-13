#ifndef BOOK_H
#define BOOK_H

/*
	Inferface for Book class
	Andrew Kump
	August 2015
*/

#include <string>
#include <vector>

using namespace std;

class Book{

  public:
  // Open file to read as book.
  // See instructions for file markup.
  Book(string filename);
  // Provide all parts of book as strings.
  Book(string title, string first, string last, string book);
   
  // Setters
  // No setters.
  
  // Getters
  // Return title
  string getTitle();
  // Return "first last" 
  string getFullAuthor();
  // Return first name of author
  string getAuthorFirst();
  // Return last name of author
  string getAuthorLast();
  
  // Return the number of characters, including all non-printables
  // hint: string length
  unsigned int getCharacterCount();
  // Number of lines in the book - hint: \n
  unsigned int getLineCount();
  // Number of times 'word' is used in the book
  unsigned int getWordCount(string word);
  
  vector<float> letterPercent();  // for HW
  
  // Return the contents of the book
  string getText();

  private:
  string file;
  string book_print;
  string title;
  string title_print;
  string first;
  string first_print;
  string last;
  string last_print;
  string text;
  string text_print;
  string full_name;
  string first_print_space;
  string last_file;
  string first_file;
  string title_file;
  string new_title_print;
};


#endif
