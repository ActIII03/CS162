//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Game Abstract Base Class

#include "list.h"
#include "game.h"
#include "player.h"


int main()
{

    PlayerList player_list;
    player new_ply;

    new_ply.read_in();
    player_list.add_player(new_ply);
    new_ply.delete_read();
    new_ply.read_in();
    player_list.add_player(new_ply);
    new_ply.delete_read();
    new_ply.read_in();
    player_list.add_player(new_ply);
    new_ply.delete_read();

    return 0;
}
