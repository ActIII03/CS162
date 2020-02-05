//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "stack.h"
#include "queue.h"
#include "routes.h"

int main()
{

    routes new_routes;
    queue route_list;
    stack return_trip_list;
    dummy_struct buffer;

    bool quit = false;

    cout << "Welcome to Plan-Your-Route application which is where you store info in regards to your trip" << endl;

    do
    {
        switch(menu())
        {
            case 1:
                 //Add route
                cout << "Please enter a name of the street: " << endl;
                cin.get(buffer.street, 50, '\n');
                cin.ignore(100, '\n');
                new_routes.create_route(buffer);
                break;

            case 2:
                //Start trip either: (1) Peek at primary and alternatve (2) Then ask user to pick either one and dequeue to stack for pop

                break;

            case 3:
                //Start Return Trip

                break;

            case 4:
                //Quit Application
                quit = true;
            };

    }while(!quit);

    return 0;

}
