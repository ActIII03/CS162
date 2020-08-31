//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Game Abstract Base Class

#include "list.h"

#ifndef PLAYER
#define PLAYER

class player: public GameList
{
    public:
        //Default constructor
        player();
        //User supplied name
        player(char * new_name);
        //Copy constructor
        player(const player & new_player);
        ~player();
        //Read in player's name
        void read_in();
        //Add game to player's CLL
        void add_games();
        //Play game and score game
        int play_game();
        //Display
        void display();
        //Compare
        bool is_match(char * match);
        //Rid of dyn. memory from read in
        void delete_read();

    protected:
        //Variables
        char * name;
        int score;
};

//Using node to encapsulate player in the LLL
class PlayerNode
{
    public:
        PlayerNode();
        //Add player
        PlayerNode(const player & add_player);
        ~PlayerNode();
        //get next pointer
        PlayerNode *& get_next();
        //set next pointer
        void set_next(PlayerNode * current);
        //Play one game
        void play_turn();
        //Display
        void display();
        //Return score
        int get_score();
        //Compare
        bool is_match(char * match);
        //Add game
        void add_game();
        
    protected:
        //Variables
        int score;
        PlayerNode * next;
        player * a_player;

};

class PlayerList
{
    public:
        //Default constructor
        PlayerList();
        //Destructor
        ~PlayerList();
        //Add player to player LLL
        void add_player(const player & new_player);
        //Player's turn <--- Work on: (i) Display
        void play_games();
        //Display Scoreboard
        void display_players();
        //Add games
        void add_game();

    protected:

        //Variables
        int num_of_players;
        PlayerNode * head;

        //Recursively add player to end of LLL
        int add_player(PlayerNode *& current, const player & new_player);
        //Display Scoreboard
        void display_players(PlayerNode * head);
        //Compare score and return, while score isn't equal, boolean to display
        PlayerNode * find_player(PlayerNode *& current, char * match);
        //Recursive ordered-insert 
        void sorted_insert(PlayerNode *& current, PlayerNode * to_insert);
        //Destructor helper
        void destroy(PlayerNode *& head);

};
#endif

