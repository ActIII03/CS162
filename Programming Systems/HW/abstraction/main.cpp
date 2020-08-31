//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Game Abstract Base Class

#include "list.h"
#include "game.h"
#include "player.h"

//Client Program
int main(void)
{

    GameList game_sys;
    PlayerList player_list;
    player new_ply;

    char choice;
    bool new_game = false;

    std::cout << "Welcome to my game system!\n";

    do
    {
        //Add more game if new round
        if(new_game)
            player_list.add_game();

        do
        {

            if(!new_game)
            {
                std::cout << "New player:\n";
                new_ply.read_in();
                player_list.add_player(new_ply);
                new_ply.delete_read();
                std::cout << "Add another player?\n";
            }
            else
            {
                std::cout << "Wanna add more players?(Y/N): ";
                std::cin >> choice;
                std::cin.ignore(MAX, '\n');
                if(toupper(choice) == 'Y')
                {
                    new_ply.read_in();
                    player_list.add_player(new_ply);
                    std::cout << "Add another player?\n";
                }
            }

        } while(again());

        player_list.play_games();

        player_list.display_players();

        std::cout << "Wanna do more rounds of games?\n";
        new_game = again();

    } while(new_game); 

    return 0;
}
