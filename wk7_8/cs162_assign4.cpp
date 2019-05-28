#include "cs162_list.h"

int main()
{
    activity_type temp_act;
    list list_mgmt;
    int count = 0;
    greetings();
    
    //Place Menu foo here
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
                list_mgmt.search();
                break;
        }
    }
    while(are_you_sure());

    return 0;
}

