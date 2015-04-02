#ifndef __DECK__
#define __DECK__

#include <iostream>
#include <vector>
using namespace std;

struct Card{
    private:    
        string face;
        string suit;
        int value;
    
    public:
        //Card constructor
        Card(string cardFace, string cardSuit, int cardValue);
        //prints card
        void printCard(); 
        //returns card value
        int val_return();
        //alters ace value
        void ace(int num);      
};

class Deck
{
    private:
        vector<Card> c;
    
    public:
        //Deck default constructor
        Deck();
        //prints deck
        void printDeck();
        //shuffles deck
        void shuffle();
        //draws a card
        Card draw_card(int &totDrawn);
    
};

#endif