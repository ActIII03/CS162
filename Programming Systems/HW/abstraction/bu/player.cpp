//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Game Abstract Base Class

#include "player.h"

player::player()
{
    name = NULL;
    score = 0;
}

player::player(char * new_name)
{
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);
}

player::player(const player & new_player)
{
    name = new char[strlen(new_player.name) + 1];
    strcpy(name, new_player.name);
}

void player::read_in()
{
    char buffer[MAX];

    std::cout << "Please enter your full name: ";
    std::cin.get(buffer, MAX, '\n');
    std::cin.ignore(MAX, '\n');

    name = new char[strlen(buffer) + 1];
    strcpy(name, buffer);
}

void player::delete_read()
{
    if(name)
    {
        delete name;
        name = NULL;
    }
}

void player::add_games()
{
    GameList::add_game();
}

int player::play_game()
{
    std::cout << "Next turn\n";
    display();
    //Catch score for sorting later
    score += GameList::play_game();
    return score;
}

void player::display()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Score: " << score << std::endl;
}

bool player::is_match(char * match)
{
    if(strcmp(name, match) == 0)
        return true;
    return false;
}

void PlayerNode::add_game()
{
    a_player -> add_game();
}

player::~player()
{
    if(name)
    {
        delete name;
        name = NULL;
    }
}

PlayerNode::PlayerNode()
{
    score = 0;
    next = NULL;
    a_player = NULL;
}

PlayerNode::PlayerNode(const player & add_player)
{
    a_player = new player(add_player);
    a_player -> add_games();
}

PlayerNode *& PlayerNode::get_next()
{
    return next;
}

void PlayerNode::set_next(PlayerNode * current)
{
    next = current;
}

void PlayerNode::play_turn()
{
    score += a_player -> play_game();
}

void PlayerNode::display()
{
    a_player -> display();
}

int PlayerNode::get_score()
{
    return score;
}

bool PlayerNode::is_match(char * match)
{
    return a_player -> is_match(match);
}

PlayerNode::~PlayerNode()
{
   if(a_player)
       delete a_player;
}

PlayerList::PlayerList()
{
    num_of_players = 0;
    head = NULL;
}

void PlayerList::add_player(const player & new_player)
{
    //LLL of players is empty
    PlayerNode * new_node = head;
    if(!new_node)
    {
        head = new PlayerNode(new_player);
        ++num_of_players;
    }
    else 
        num_of_players += add_player(new_node -> get_next(), new_player);
}

int PlayerList::add_player(PlayerNode *& current, const player & new_player)
{
    if(!current)
    {
        current = new PlayerNode(new_player);
        return 1;
    }
    return add_player(current -> get_next(), new_player); 
}

void PlayerList::play_games()
{
    //Traverse through list for each player, taking turns to play one game
    if(!head)
        return;

    char buffer[MAX];

    do
    {
        std::cout << "Who wants to play (Ex. Bob): ";
        std::cin.get(buffer, MAX, '\n');
        std::cin.ignore(MAX, '\n');
        //Cut node out of list 
        PlayerNode * temp = find_player(head, buffer);
        if(temp)
        {
            temp -> play_turn();
            sorted_insert(head, temp);
        }
        else
            std::cout << "No matching name, either no name or misspelled\n";

    } while(again());
}

void PlayerList::display_players()
{
   if(!head)
        std::cout << "No players\n";
   display_players(head);
}

void PlayerList::display_players(PlayerNode * head)
{
    if(!head)
        return;
    head -> display();
    display_players(head -> get_next());
}


PlayerNode * PlayerList::find_player(PlayerNode *& current, char * match)
{
    //List is empty
    if(!current)
        return NULL;
    if(current -> is_match(match))
    {
        PlayerNode * temp = current;
        current = current -> get_next();
        temp -> set_next(NULL);
        return temp;
    }
    return find_player(current -> get_next(), match);
}

void PlayerList::sorted_insert(PlayerNode *& current, PlayerNode * to_insert)
{
    //Empty list
    if(!current)
    {
        current = to_insert;
        head = current;
        return;
    }
    
    //If recent node's score is greater or equal to current node, then insert before current
    if( to_insert -> get_score() >= current -> get_score())
    {
        to_insert -> set_next(current);
        current = to_insert;
        return;
    }

    //Traverse till true
    return sorted_insert(current -> get_next(), to_insert);

}

void PlayerList::add_game()
{
    char buffer[MAX];

    if(!head)
    {
        std::cout << "No players\n";
        return;
    }
    
    std::cout << "Which player would like to add games?( Ex. Bob): ";
    std::cin.get(buffer, MAX, '\n');
    std::cin.ignore(MAX, '\n');
    PlayerNode * temp = find_player(head, buffer);
    if(temp)
    {
        temp -> add_game();
        sorted_insert(head, temp);
    }
    else
        std::cout << "No matching name, either no name or misspelled\n";

}

PlayerList::~PlayerList()
{
    destroy(head);
    head = NULL;
}

void PlayerList::destroy(PlayerNode *& head)
{
    if(!head)
        return;
    PlayerNode * temp = head;
    head -> set_next(head -> get_next());
    delete temp;
    return destroy(head -> get_next());
}

