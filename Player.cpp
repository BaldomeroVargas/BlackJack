#include "Player.h"
#include "Deck.h"
#include <iostream>
#include <vector>

using namespace std;

string measuringStick(40, '-');

//Player constructor
Player::Player(string user){
    name = user;
    handTotal = 0;
    status = false;
}

//obtains name of player
string Player::get_name() const{
    return name;
}

//obtains hand of player
int Player::get_hand(){
    return handTotal;
}

//outputs player and hand total
void Player::display(){
    cout << name << "'s hand total is " << handTotal << "." << endl << endl;
}

//shows hand to player
void Player::display_hand(){
    cout << "Your hand is:" << endl;
    for(int i = 0; i < hand.size(); ++i){
        hand.at(i).printCard();
    }
    cout << endl;
}

//updates players hand fully by putting 
//card in hand and updating hand total
void Player::player_hand(Card current, int & prompt_check){
    //work on this!
    if(handTotal == 0){
        if(current.val_return() == 0){
            cout << "You have drawn "; current.printCard(); cout << endl;           
            int num;   
            prompt_check = 1;
            do{
                cout << get_name(); cout << ", would you like the ace to be worth 1 or 11? ";
                cin >> num; 
                cout << endl;
            }while(num != 1 && num != 11);
            current.ace(num);
        }
        hand.push_back(current);
        update_player_hand(current);        
    }
    else{
        if(current.val_return() == 0){
            cout << "You have drawn "; current.printCard(); cout << endl;           
            int num; 
            prompt_check = 1;            
            display_hand();
            do{
                cout << get_name(); cout << ", would you like the ace to be worth 1 or 11? ";
                cin >> num; 
                cout << endl;
            }while(num != 1 && num != 11);
            current.ace(num);
        }
        hand.push_back(current);
        update_player_hand(current);         
    }
}

//updates players hand by updating hand total
void Player::update_player_hand(Card current){
    handTotal += current.val_return();
}

//checks if player has valid hand
bool Player::player_check(){
    return status = (handTotal > 21);
}

//checks player command
bool Player::command_check(string command){
    return status = (command == "H" || command == "h");
}

//simulates single turn
void Player::single_turn_display(int &number_drawn, string command, Deck game_deck){
    command_check(command);
    int test_value = 0;
    if(!command_check(command)){
        player_hand(game_deck.draw_card(number_drawn), test_value);
        if(test_value == 0){
            display(); display_hand();        
        }
        if(player_check()){
            cout << "You are eliminated from contention." << endl;
        }
    }
    else{
        cout << name << " has held at " << handTotal << "." << endl << endl;
        display_hand();
    }
}

bool Player::player_status(){
    return status;
}