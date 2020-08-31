//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Game Abstract Base Class

#include "list.h"

//helper functions

GameNode::GameNode()
{
    next = NULL;
    new_game = NULL;
}

GameNode::GameNode(int choice)
{
    switch(choice)
    {
        case 1:
            new_game = new NumberSequence;
            break;
        case 2:
            new_game = new GuessNumber;
            break;
        case 3:
            new_game = new WhackANumber;
            break;
    }
}

GameNode::GameNode(Game *& add_game)
{
     
    //RTTI (1)
    NumberSequence * numseq_ptr= dynamic_cast< NumberSequence *> (&*add_game);
    if(numseq_ptr)
        new_game = new NumberSequence;
    //RTTI (2)
    GuessNumber * guessnum_ptr = dynamic_cast< GuessNumber *> (&*add_game);
    if(guessnum_ptr)
        new_game = new GuessNumber;
    //RTTI (3)
    WhackANumber * whacknum_ptr = dynamic_cast< WhackANumber *> (&*add_game);
    if(whacknum_ptr)
        new_game = new WhackANumber;
}

GameNode *& GameNode::get_next()
{
    return next;
}

void GameNode::set_next(GameNode * current)
{
    next = current;
}

int GameNode::play_game()
{
    int result = 0;
    //RTTI
    if(typeid(*new_game) == typeid(NumberSequence))
        result = new_game -> play_game();
    if(typeid(*new_game) == typeid(GuessNumber))
        result = new_game -> play_game();
    if(typeid(*new_game) == typeid(WhackANumber))
        result = new_game -> play_game();
    return result;
}

GameNode::~GameNode()
{
    delete new_game;
    new_game = NULL;
}

GameList::GameList()
{
    num_of_games = 0;
    played_games = 0;
    new_game_rear = NULL;
    game_to_play = NULL;
}

void GameList::add_game()
{

    int choice = 0;

    //Keep adding games till player is finished picking
    do
    {
        std::cout << "First, here is list of games to play from:"
                  << "\n(1) Number Sequence"
                  << "\n(2) Guess Number"
                  << "\n(3) Whack a Number" 
                  << "\nPick (1 - 3) : ";
        std::cin >> choice;
        std::cin.ignore(MAX, '\n');
        
        //Temp 
        Game * temp;

        switch(choice)
        {
            // Allocate derived object based off choice and pass to the GameNode
            case 1:
                temp = new NumberSequence;
                break;
            case 2:
                temp = new GuessNumber;
                break;
            case 3:
                temp = new WhackANumber;
                break;
        }

        GameNode * current = new_game_rear;
        num_of_games += insert(current, temp);
        delete temp;

    } while(again());

}

int GameList::insert(GameNode *& current, Game *& add_game)
{

    //Check CLL
    //CLL is empty
    if(!current)
    {
        new_game_rear = new GameNode(add_game);
        new_game_rear -> set_next(new_game_rear);
        game_to_play = new_game_rear;
        return 1;
    }
    //Come back to later
    else if(num_of_games != 0 && played_games == num_of_games)
    {
        //List has more than one item
        GameNode * temp = new GameNode(add_game);  
        game_to_play = temp;
        temp -> set_next(new_game_rear -> get_next());
        new_game_rear -> set_next(temp); 
    }
    else
    {
      GameNode * temp = new GameNode(add_game);  
      temp -> set_next(new_game_rear -> get_next());
      new_game_rear -> set_next(temp); 
    }
    return 1;
}

int GameList::play_game()
{
    int score = 0;
    if(played_games == num_of_games)
    {
        std::cout << "Sorry, no more games to play (One play through list of game(s) you've created at the beginning). Try adding more game!" << std::endl;
        return 0;
    }
    else
    {
        score += game_to_play -> play_game();
        ++played_games;
        std::cout << "Played games: " << played_games << std::endl;
        game_to_play = game_to_play -> get_next();
    }
    return score;
}

GameList::~GameList()
{
    destroy(new_game_rear -> get_next());
}

void GameList::destroy(GameNode *& current)
{
    if(!new_game_rear)
        return;
    else if(current == new_game_rear)
    {
        delete current;
        current = NULL;
        new_game_rear = NULL;
        game_to_play = NULL;
    }
    GameNode * temp = current;
    delete temp;
    temp = NULL;
    destroy(current -> get_next());
}

