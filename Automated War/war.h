#ifndef WAR_H
#define WAR_H
/*
  This runWar function runs a game of war between 2 automated players
  and returns the number of rounds (both put a card down 
  once per round) until someone won.  An integer is given 
  as an upper limit to how many rounds a game can go on for.
*/
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <stack>
#include <queue>
#include "deck.h"

using namespace std;

int runWar(unsigned int limit){
  queue<Card> playerone;
  queue<Card> playertwo;
  stack<Card> table;  
  Deck d;
  
  for(unsigned int i =0; i < 26; i++){
    playerone.push(d.getTopCard());
  }
  for(unsigned int i = 0; i < 26; i++){
    playertwo.push(d.getTopCard());
  }
  
  for(unsigned int count = 0; count < limit; count++){
    if(playerone.size() == 0 || playertwo.size() == 0){
      return count;
    }
    Card cardDraw1 = playerone.front(); 
    Card cardDraw2 = playertwo.front();
    
    table.push(cardDraw1);
    table.push(cardDraw2);
    
    playerone.pop();
    playertwo.pop();
    
    if(cardDraw1.getRank() > cardDraw2.getRank()){
      while(table.empty()==0){
        playerone.push(table.top());
        table.pop();
      }
    }
    else if(cardDraw1.getRank() < cardDraw2.getRank()){
       while(table.empty()==0){
        playertwo.push(table.top());
        table.pop();
      }
    }
    else{
     for(int i =0; i < 3; i++){
      if(playerone.size() == 0 || playertwo.size() == 0){
        return count;
      }
      table.push(playerone.front());
      table.push(playertwo.front());
      playerone.pop();
      playertwo.pop();
    }
   }
  }
return limit;
}

#endif
