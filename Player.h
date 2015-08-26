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
        int initial_ace_check;
    
    public:
    
        Player(string user);
        void display();
        string get_name() const;
        int get_hand();
        int get_initial_ace_check();       
        //adds to player hand
        void player_hand(Card current, int& prompt_check);
        void display_hand();     
        void update_player_hand(Card current);
        //checks if player is still in the game
        bool player_check();
        bool command_check(string command);
        void single_turn_display(int &number_drawn, string command, Deck game_deck);
        bool player_status();
        void start_draw(Card Current);
        void start_finalize();
    
};

#endif