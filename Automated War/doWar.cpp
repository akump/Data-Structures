#include <iostream>

/*
  The file implements main to simulate 100000 games of war.  It should print out
  a histogram of the game lengths from 0 to 1000 rounds (ok to have less detail)
  as well as the average game length.
*/

#include "deck.h"
#include "war.h"

using namespace std;

int main(){
  // Fill in code here!
  vector<unsigned int> numgames;
  float total_avg = 0;
  unsigned int star_count = 0;
  srand(time(NULL));
  unsigned int low = 0;
  unsigned int high = 19;
  
  for(unsigned int i = 0; i < 1000; i++){
    unsigned int length = runWar(1000);
    numgames.push_back(length);
    total_avg = total_avg + length;
  }
  /*for(unsigned int i = 0; i < numgames.size(); i++){
    cout << i << ": " << numgames[i] << endl;
  }*/
  for(unsigned int i = 0; i <1000; i++){
    if(high - i == 0){
      cout << low << "-" << high << ": ";
      if(high == 999){
        high = 1000;
      }
      for(unsigned int j = 0; j < 1000; j++){
        if(numgames[j] >= low && numgames[j] <= high){
          star_count = star_count + 1;
        }
      }
      
      cout << star_count << ": ";
      for(unsigned int k = 0; k < star_count; k++){
        cout << "*";
      }
      
      star_count = 0;
      if(i < 999){
        cout << endl;
      }
      low = low + 20;
      high = high + 20;
    }
  }
  cout << endl;
  /*for(unsigned int p = 0; p <1000; p++){
    if(numgames[p] == 1000){
      cout << "*";
    }
    
  }*/
  cout << "Average: " << total_avg/1000 << endl;
  return 0;
}
