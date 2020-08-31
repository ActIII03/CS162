//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Game Abstract Base Class

#include "game.h"

#ifndef GAME_LIST
#define GAME_LIST

class GameNode
{ public:
        //Default constructor
        GameNode();
        //User supplies what game to play
        GameNode(int choice);
        //Create and set equalities 
        GameNode(Game *& add_game);
        //Default destructor
        ~GameNode();
        //Get next
        GameNode *& get_next();
        //Set next
        void set_next(GameNode * current);
        //Play game
        int play_game();

    protected:
        GameNode * next;
        Game * new_game;
};

//Game system that "has a" list of players (LLL)
class GameList
{
    public:
        //Default constructor
        GameList();
        //Default destructor
        ~GameList();
        //Add games to front of CLL 
        void add_game(); 
        //Play game and return win or lost with an integer
        int play_game();

    protected:

        int num_of_games;
        int played_games;

        //Rear pointer
        GameNode * new_game_rear;
        //Keep track and stop playing after one iteration over LLL of games
        GameNode * game_to_play;
        //Insert to GameList
        int insert(GameNode *& current, Game *& add_game);
        //Destructor helper
        void destroy(GameNode *& current);

};
#endif

