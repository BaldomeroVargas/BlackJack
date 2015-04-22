#include "Deck.h"
#include <vector>
#include <iostream>
#include <algorithm> 
#include <chrono>
#include <random>
#include <array>

using namespace std;

const int CARDS_PER_DECK = 52;

//creates a card with a face, suit, and value
Card::Card(string cardFace, string cardSuit, int cardValue){
    face = cardFace;
    suit = cardSuit;
    value = cardValue;
}

//prints card face and suit
void Card::printCard(){
    cout << face << " of " << suit << endl;
} 

//returns card value
int Card::val_return(){
    return value;
}

//alters ace value
void Card::ace(int num){
    value = num;
}

//creates a 52 card deck
Deck::Deck() 
    :shuffle_seed(chrono::system_clock::now().time_since_epoch().count()) {
        
    string faces[] = {"Ace", "Deuce", "Trey", "Four", "Five", "Six", "Seven", 
    "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string suits[] = {"Diamonds", "Hearts", "Clubs", "Spades"};
    for(int i = 0; i < 4; ++i){
        string suitTemp = suits[i];
        for(int j = 0; j < 13; ++ j){
            if(j > 8){
                string faceTemp = faces[j];
                c.push_back(Card(faceTemp, suitTemp, 10));                      
            }
            else{
                string faceTemp = faces[j];
                c.push_back(Card(faceTemp, suitTemp, j + 1));                   
            }
        } 
    }
}

//prints deck
void Deck::printDeck(){
    for(int i = 0; i < CARDS_PER_DECK; ++i){
        c.at(i).printCard();
    }
}

//shuffles deck
void Deck::shuffle_deck(){
    std::shuffle(c.begin(),c.end(), default_random_engine(shuffle_seed));    
}

//draws top card
Card Deck::draw_card(int &totalDrawn){
    int temp = totalDrawn;
    totalDrawn++;
    return c.at(temp);   
}