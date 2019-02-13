#ifndef DECK_H
#define DECK_H
/*
  The Deck class implements a random deck of 52 cards.
*/
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <stack>
#include <vector>
#include "card.h"
#include <stdlib.h> 

using namespace std;

class Deck{
  public:
  Deck(){
    // Set up the instance so getTopCard can give out random cards from a deck.
    the_size = 52;
    vector<Card> deck;
    
    suit_t suits[4];
    suits[0] = DIAMONDS;
    suits[1] = CLUBS;
    suits[2] = SPADES;
    suits[3] = HEARTS;
    
    for(unsigned int i = 0; i< 52; i++){
      deck.push_back(Card(suits[i / 13], i % 13 +1) );
    }
    
    for(int i = 0; i <52; i++){
      int j = rand()%52;
      Card old = deck[i];
      Card newcard = deck[j];
      deck[i] = newcard;
      deck[j] = old;
    }
    
    for(int i = 0; i < 52; i++){
      d.push(deck[i]);
    }
  }
  
  Card getTopCard(){
    if(d.size() == 0){
      throw logic_error("Deck empty");
    }
    the_size = the_size - 1; 
    Card a = d.top();
    d.pop();
    return a;
  }
  
  unsigned int size() const{
    return the_size;
  }
  
  
  private:
  stack<Card> d;    // Hint hint!
  //unsigned int num_cards;
  int capacity;
  unsigned int the_size;
  

};

#endif
