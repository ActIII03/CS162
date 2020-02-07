//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "stack.h"
#include "queue.h"
#include "routes.h"

int main()
{

    //ADT's
    queue route_list;
    stack return_trip_list;

    //Client
    routes new_routes, pri_route, alt_route;
    a_route in_route; //struct to hold buffer and stuff

    //open input.txt for input
    freopen("input.txt","r",stdin);

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
                    //Assuming that this assignment requires the user to input two routes
                    cout << "You need to supply two routes: (1) Primary & (2) Back-up Route" << endl;

                    //Add 1st route
                    cout << "Please enter a name of the street: " << endl;
                    cin.get(in_route.street, 50, '\n');
                    cin.ignore(100, '\n');
                    cout << "Please enter distance to travel (miles): " << endl;
                    cin >> in_route.length;
                    cin.ignore(100, '\n');
                    cout << "Please enter status of traffic: " << endl;
                    cin.get(in_route.traffic_stat, 50, '\n');
                    cin.ignore(100, '\n');
                    cout << "Please enter short description: " << endl;
                    cin.get(in_route.notes, 50, '\n');
                    cin.ignore(100, '\n');
                    cout << "If you have know the source of info, you can put that. Otherwise, you can put none: " << endl;
                    cin.get(in_route.source, 50, '\n');
                    cin.ignore(100, '\n');
                    route_choice = new_routes.create_route(in_route);
                    result = route_list.enqueue(new_routes, route_choice);
                    if(!result)
                        cout << "\nRoute was added!" << endl;
                    else
                        cout << "\nSomething went wrong" << endl;

                    //Add 2nd route
                    cout << "Please enter a name of the street: " << endl;
                    cin.get(in_route.street, 50, '\n');
                    cin.ignore(100, '\n');
                    cout << "Please enter distance to travel (miles): " << endl;
                    cin >> in_route.length;
                    cin.ignore(100, '\n');
                    cout << "Please enter status of traffic: " << endl;
                    cin.get(in_route.traffic_stat, 50, '\n');
                    cin.ignore(100, '\n');
                    cout << "Please enter short description: " << endl;
                    cin.get(in_route.notes, 50, '\n');
                    cin.ignore(100, '\n');
                    cout << "If you have know the source of info, you can put that. Otherwise, you can put none: " << endl;
                    cin.get(in_route.source, 50, '\n');
                    cin.ignore(100, '\n');
                    route_choice = new_routes.create_route(in_route);
                    result = route_list.enqueue(new_routes, route_choice);
                    if(!result)
                        cout << "\nRoute was added!" << endl;
                    else
                        cout << "\nSomething went wrong" << endl;

                    //Ask user if they want to keep adding routes
                    cout << "Want to keep adding routes?( 0 = No & 1 = Yes):";
                    cin >> quit_adding;
                    cin.ignore(100, '\n');

                }while(!quit_adding);
                //Maybe delete dynamic memory used for: (i) new_routes
                break;

            case 2:

                //Start trip: (1) Peek at primary and alternatve (2) Then ask user to pick either one and dequeue to stack for pop
                cout << "\nNow that routes are added, you will be asked to pick the routes based off your preferences. Then if you decide to return"
                     << "\nfrom your destination, the same route you took to you destination will be the same one's you take back to your origin." << endl;

                //Keep doing until user is done going through CLL, either primary or the alternative list
                do
                {
                  //Display both routes and let user pick one
                  route_list.peek(pri_route, alt_route);

                  cout  << "(1) ";
                  pri_route.display();
                 
                  cout  << "(2) ";
                  alt_route.display();

                  cout << "\n Which route looks good? (1-2): ";
                  cin >> route_choice;
                  cin.ignore(100, '\n');

                  if(route_choice == 1)
                      result = route_list.dequeue(pri_route, route_choice);
                  else                
                      result = route_list.dequeue(pri_route, route_choice);

                  cout << "\nStreet: " << new_routes.street
                       << "\nDistance (miles:) " << new_routes.length
                       << "\nTraffic Status: " << new_routes.traffic_stat
                       << "\nNotes: " << new_routes.notes
                       << "\nSource of information: " << new_routes.source << endl;
                  return_trip_list.push(new_routes);

                }while(!result);
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
