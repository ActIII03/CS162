//Name: Armant Touche
//Class: CS202
//Program: FishBowl 
#include "users.h"

int main(void)
{
    //Table of users that contains array of users and a thread (bst) to post to
    UserTable ut1;

    do
    {

        //Let users pick between creating an account or logging into an existing one
        switch(choice())
        {
            //Create user
            case 1:
                ut1.create_user();
                break;
            //Login
            case 2:
                ut1.login();
                break;
        }

    }while(again()); //Ask user(s) to go again

    return 0;
}

