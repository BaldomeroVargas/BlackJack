#ifndef __PLAYER__
#define __PLAYER__

#include <vector>
#include <iostream>
#include "Deck.h"
using namespace std;

class Player
{
    private:    
        string name;
        int handTotal;
        vector<Card> hand;
        //checks if the player is playing        
        bool status;
    
    public:
    
        Player(string user);
        void display();
        string get_name() const;
        int get_hand();
        //adds to player hand
        void player_hand(Card current);
        void display_hand();     
        //adds to player total
        void update_player_hand(Card current);
        //checks if player is still in the game
        bool player_check();
        bool command_check(string command);
        //simulates a single turn for player
        void single_turn_display(int &number_drawn, string command, Deck game_deck);
        bool player_status();
    
};

#endif