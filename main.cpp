#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Player.h"
#include "Deck.h"
#include "Interface.h"
using namespace std;

template <typename T>
void get_in(T &t, const string &prompt="");
void get_players(string &response, int &players);
void obtain_players_name(vector<Player> & p,int &players);
void get_command(string& command);
void game_start(vector<Player> & p, int players, Deck game_deck, int & totalDrawn);
void turn(Player& current, string & command, int& number_drawn, Deck game_deck);
void dealer_turn(Player& current, int& number_drawn, Deck game_deck, int max);
void sort_display(vector<Player> & final, vector<Player> & p, int players);



int main(int argc, char* argv[]){
    
    //checks command line arguements
    if(argc != 2){
        cout << "Program usage: ./black.out rules.txt" << endl;
        return 1;        
    }
    
    string response; int players;
    get_in(response, "Want to play black jack? ");
    
    //secures response to play or not
    //and gets players
    get_players(response, players);
    
    //rules to the players
    ifstream inFS;
    
    cout << "Opening rules file " << argv[1] << endl << endl;
    //checks if input file is already open
    inFS.open(argv[1]); // opening file
    if(!inFS.is_open()){
        cout << "Could not open file " << argv[1] << "." << endl;
        return 1;
    }
    
    //calls rules file and outputs
    do{
        string rules;        
        getline(inFS, rules); 
        cout << rules << endl;
    }while(inFS.good());
    cout << endl;
    
    vector<Player> p; 
    
    //stores players of <Player> type in a vector
    obtain_players_name(p, players);
    
    //creates and shuffles the deck
    Deck game_deck; 
    game_deck.shuffle_deck();
    
    //keeps track of number of cards drawn
    int number_drawn = 0;
    
    // does initial 2 draws for players
    game_start(p,players,game_deck,number_drawn);  
        
    for(int i = 0; i < players; ++i){
        //players other than dealer
        if(i < players - 1){
            while(p.at(i).player_status() == false){
                string command;    
                turn(p.at(i), command, number_drawn, game_deck);  
                //checks is player holds
                bool choice; choice = p.at(i).command_check(command); 
                //if player draws
                if(choice == false){
                    //checks hand total                
                    p.at(i).player_check();    
                }            
            }            
        }
        //for dealer does entire turn for dealer
        else{
            int max = 0;
            for(int i = 0; i < players - 1; ++i){
                if(p.at(i).get_hand() <= 21 && p.at(i).get_hand() >= max){
                    max = p.at(i).get_hand();
                }
            }
            dealer_turn(p.at(players - 1), number_drawn, game_deck, max);
        }
        
    }
    
    //stores players in rank of game
    vector<Player> final;

    //sorts and displays in proper fashion
    sort_display(final, p, players);
    
    
    return 0;
}

//ensures cin gets proper variable type
template <typename T>
void get_in(T &t, const string &prompt="") {
    cout << prompt;
    cin >> t;
    cout << endl;
    while(!cin) {
        //reset cin
        cin.clear();
        //Read the junk into a var
        string junk;
        getline(cin, junk);
        //Try again
        cout << "BAD INPUT, try again... " << prompt;
        cin >> t;
        cout << endl;
    }
}

//function sorts in order of placing
void sort_display(vector<Player> & final, vector<Player> & p, int players){
    //organizes players from low to high
    for(int x = 0; x < players; ++x){
        for(int i = 0; i < players; ++i){
            if(i == players - 1){
                break;
            }
            else{
                int min = p.at(i).get_hand();              
                int temp = p.at(i + 1).get_hand();
                if(temp < min){
                    min = temp;
                    //swaps players if met
                    Player store = p.at(i);
                    p.at(i) = p.at(i + 1);
                    p.at(i + 1) = store;
                }
            }
        }        
    }
    
    //organizes properlly
    //organizes players from low to high
    for(int x = 0; x < players; ++x){
        for(int i = 0; i < players; ++i){
            if(i == players - 1){
                // cout << "WELP" << endl;
                break;
            }
            else{
                int min = p.at(i).get_hand();              
                int temp = p.at(i + 1).get_hand();
                if(temp <= 21 && temp > min){
                    min = temp;
                    //swaps players if met
                    Player store = p.at(i);
                    p.at(i) = p.at(i + 1);
                    p.at(i + 1) = store;
                }
            }
        }        
    }    

    for(int i = 0; i < players; ++i){
        if(i > 0){
            if(p.at(i).get_hand() == p.at(i - 1).get_hand()){
                final.push_back(p.at(i));          
                cout << i << ". ";
                final.at(i).display();    
            }
            else{
                final.push_back(p.at(i));          
                cout << i + 1 << ". ";
                final.at(i).display();
            }
        }
        else{
            final.push_back(p.at(i));          
            cout << i + 1 << ". ";
            final.at(i).display();    
        }
    }    
}

//function handles dealers turn
void dealer_turn(Player& current, int& number_drawn, Deck game_deck, int max){
    string measuringStick(40, '-'); cout << measuringStick << endl;
    string command; get_in(command, "Please enter any key to simulate dealer drawing: "); 
    current.display(); current.display_hand();
    while(current.get_hand() <= 21 && current.get_hand() < max){
        cout << measuringStick << endl;    
        if(current.get_hand() >= max){
            break;
        }
        else{
            current.player_hand(game_deck.draw_card(number_drawn));
            get_in(command, "Please enter any key to simulate dealer drawing: "); 
            current.display(); current.display_hand();            
        }
    }
    if(current.get_hand() > 21){
        cout << "Dealer is eliminated from contention." << endl;
        cout << measuringStick << endl;          
    }
    else{
        cout << measuringStick << endl;          
    }
}


//function for a players single turn
void turn(Player& current, string & command, int& number_drawn, Deck game_deck){
    string measuringStick(40, '-'); cout << measuringStick << endl;
    current.display();
    current.display_hand();
    get_command(command);    
    current.single_turn_display(number_drawn,command,game_deck);    
}

//properlly stars the game
//hands a card to each player
//repeats twice
void game_start(vector<Player> & p, int players, Deck game_deck, int & totalDrawn){
    //hands card to player *repeated twice*
    for(int j = 0; j < 2; ++j){
        //updates for player drawn card 
        //updates hand total and cards in hand
        for(int i = 0; i < players;++i){
            p.at(i).player_hand(game_deck.draw_card(totalDrawn));
        }   
    }
}

//secures a proper response to a move
void get_command(string& command){
    cout << "Hold (H/h) or Draw (D/d)? "; get_in(command);    
    if(command != "D" && command != "d" && command != "h" && command != "H"){
        do{
            cout << "Please enter a valid command for Hold (H/h) or Draw (D/d) ";    
            get_in(command);
        }while(command != "D" && command != "d" && command != "h" && command != "H");
    }
}

//creates the players names
void obtain_players_name(vector<Player> & p, int &players){
    //ask players for names and stores them in an output file
    for(int i = 1; i <= players + 1; ++i){
        //last player is always dealer
        if(i == players + 1){
            cout << "Dealer is known as Dealer.";
            string name = "Dealer"; 
            p.push_back(Player(name));
            cout << endl << endl;
            break;
        }
        else{
            cout << "Player " << i << " please enter your user name: ";
            string name; get_in(name); 
            p.push_back(Player(name));
        }
    }
    
    players++;    
}

//creates the players
void get_players(string &response, int& players){
    //loop securing a proper response
    while(response != "Yes" && response != "yes" && response != "No" && response !="no") {
        get_in(response, "What did you say? ");
    }
    
    //loop securing proper amount of players
    if(response == "Yes" || response == "yes"){
        get_in(players, "How many players? (max 3): ");
        if(players < 1 || players > 3){
            do{
                get_in(players, "Please enter a valid amount of players (1-3): "); 
            }while(players < 1 || players > 3);
        }
    }
    else{
        //ends game if user does not want to play
        cout << "Okay bye :/" << endl;
        exit(0);
    }    
    
    cout << "Okay so there are " << players + 1;
    cout << " players including the Dealer." << endl << endl;
    cout << "Let's begin!" << endl << endl;       
}