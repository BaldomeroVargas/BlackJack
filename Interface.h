#include <iostream>
#include <cstdlib>
#include "Player.h"

using namespace std;

// //ensures cin gets proper variable type
// template <typename T>
// void get_in(T &t, const string &prompt="") {
//     cout << prompt;
//     cin >> t;
//     cout << endl;
//     while(!cin) {
//         //reset cin
//         cin.clear();
//         //Read the junk into a var
//         string junk;
//         getline(cin, junk);
//         //Try again
//         cout << "BAD INPUT, try again... " << prompt;
//         cin >> t;
//         cout << endl;
//     }
// }


////// PLAYER ///////

// //outputs player and hand total
// void Player::display(){
//     cout << name << "'s hand total is " << handTotal << "." << endl << endl;
// }

// //shows hand to player
// void Player::display_hand(){
//     cout << "Your hand is" << endl;
//     for(int i = 0; i < hand.size(); ++i){
//         hand.at(i).printCard();
//     }
//     cout << endl;
// }