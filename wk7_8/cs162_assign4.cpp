#include "cs162_list.h"

int main()
{
    activity_type temp_act;
    list list_mgmt;
    int decision = 0;
    bool quit = false;
    greetings();
    
    //Place Menu foo here
    menu(decision);
    do
    {
        switch(decision)
        {
            case 1:
                list_mgmt.read_in();
                break;
            case 2:
                list_mgmt.display();
                break;
            case 3:
                //list_mgmt.search();
                break;
            case 4:
                quit = true;
                break;
            default:
                menu(decision);
        }
    }
    while(!quit);

    return 0;
}

