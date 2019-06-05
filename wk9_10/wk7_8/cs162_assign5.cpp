#include "cs162_list.h"

//Driver
int main()
{
    event_type event_act;  //Activity object created here
    list list_mgmt;  //List object here

    int decision = 0;
    bool quit = false;

    greetings();  //Greet user
    
    //Place Menu foo here
    menu(decision);  //Get menu decision from user
    do
    {
        //Menu for modules
        switch(decision)
        {
            case 1:  //Read-in module 
                list_mgmt.read_in();
                break;
            case 2:  //Display module
                list_mgmt.display();
                break;
            case 3:  //Search module
                list_mgmt.search();
                break;
            case 4:
                list_mgmt.remove();
            case 5:
                quit = true;  //Quit flag
                break;
        }
        if(quit == false)  //Won't trigger unless user still desires to run progra
                menu(decision);
    }
    while(!quit);  //Quit condition

    return 0;
}

