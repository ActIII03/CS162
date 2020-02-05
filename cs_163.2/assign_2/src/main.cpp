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

    bool quit_app = false; 
    int route_choice = 0, result = 0, quit_adding = 0;

    cout << "Welcome to Plan-Your-Route application which is where you store info in regards to your trip" << endl;

    do
    {
        switch(menu())
        {
            case 1:
                 //Add route
                do
                {
                    cout << "Please enter a name of the street: " << endl;
                    cin.get(buffer.street, 50, '\n');
                    cin.ignore(100, '\n');
                    route_choice = new_routes.create_route(buffer);
                    result = route_list.enqueue(new_routes, route_choice);
                    if(!result)
                        cout << "\nRoute was added!" << endl;
                    else
                        cout << "\nSomething went wrong" << endl;
                    cout << "Want to keep adding routes?( 0 = No & 1 = Yes):";
                    cin >> quit_adding;
                }while(!quit_adding);
                break;

            case 2:
                //Start trip either: (1) Peek at primary and alternatve (2) Then ask user to pick either one and dequeue to stack for pop

                break;

            case 3:
                //Start Return Trip

                break;

            case 4:
                //Quit Application
                quit_app = true;
            };

    }while(!quit_app);

    return 0;

}
