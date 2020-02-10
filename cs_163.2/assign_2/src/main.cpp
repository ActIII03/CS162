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
    //freopen("input.txt","r",stdin);

    bool quit_app = false; 
    int route_choice = 0, result = 0, quit_adding = 0;

    cout << "Welcome to Plan-Your-Route application which is where you store info in regards to your trip." << endl;

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

                    //Delete dyn. allocated memory
                    delete new_routes.street;
                    delete new_routes.traffic_stat;
                    delete new_routes.notes;
                    delete new_routes.source;

                    if(!result)
                        cout << "\nRoute was added!" << endl;
                    else
                        cout << "\nSomething went wrong" << endl;

                    //Add 2nd route
                    cout << "\nNow you need a another route, either primary or alternative\n";
                    cout << "\nPlease enter a name of the street: " << endl;
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

                    //Delete dyn. allocated memory
                    delete new_routes.street;
                    delete new_routes.traffic_stat;
                    delete new_routes.notes;
                    delete new_routes.source;

                    if(!result)
                        cout << "\nRoute was added!" << endl;
                    else
                        cout << "\nSomething went wrong" << endl;

                    //Ask user if they want to keep adding routes
                    cout << "\nWant to keep adding routes?( 0 = No & 1 = Yes): ";
                    cin >> quit_adding;
                    cin.ignore(100, '\n');

                }while(quit_adding);

                //Maybe delete dynamic memory used for: (i) new_routes

                break;

            case 2:

                //Start trip: (1) Peek at primary and alternatve (2) Then ask user to pick either one and dequeue to stack for pop
                cout << "\nNow that routes are added, you will be asked to pick the routes based off your preferences. Then if you decide to return"
                     << "from your destination, the same routes you took to you destination will be the same routes you take back to your origin.\n" << endl;

                //Keep doing until user is done going through CLL, either primary or the alternative list
                do
                {
                  //Display both routes and let user pick one
                  route_list.peek(pri_route, alt_route);

                  cout  << "(1) ";
                  pri_route.display();
                  cout << "\n";

                  cout  << "(2) ";
                  alt_route.display();
                  cout << "\n";

                  cout << "\nWhich route looks good? (1-2): ";
                  cin >> route_choice;
                  cin.ignore(100, '\n');

                  if(route_choice == 1)
                      result = route_list.dequeue(pri_route, route_choice);
                  else                
                      result = route_list.dequeue(alt_route, route_choice);

                  cout << "\nNumber of routes remaining: " << result
                       << "\nYou choose route (" << route_choice << ")\n\n";

                  if(route_choice == 1)
                      pri_route.display();
                  else
                      alt_route.display();

                  cout << "\n";

                  //Push to return_trip stack and comparing which to push
                  if(route_choice == 1)
                      return_trip_list.push(pri_route);          
                  else
                      return_trip_list.push(alt_route);         

                  //Deallocate dyn memory
                  if(pri_route.street)
                  {
                      delete pri_route.street;
                      delete pri_route.traffic_stat;
                      delete pri_route.notes;
                      delete pri_route.source;
                  }

                  if(alt_route.street)
                  {
                      delete alt_route.street;
                      delete alt_route.traffic_stat;
                      delete alt_route.notes;
                      delete alt_route.source;
                  }

                }while(result);
                break;

            case 3:
                //Start Return Trip
                do
                {
                    result = return_trip_list.pop(new_routes);
                    new_routes.display(); 
                    cout << "Keep going?( 0 = No & 1 = Yes): ";
                    cin >> route_choice;
                    cin.ignore(100, '\n');

                }while(!route_choice);

                break;

            case 4:
                //Display routes to destination
                cout << "Which routes do you want displayed? (1 = primary 2 = alternative): ";
                cin >> route_choice;
                cin.ignore(100, '\n');
                result = route_list.display(route_choice);
                if(result)
                    cout << "\nSomething went wrong, try again!\n";
                break;

            case 5:
                //Display return trip
                cout << "\nReturn trip:\n";
                return_trip_list.display();
                break;

            case 6:
                //Quit Application
                quit_app = true;
            };

    }while(!quit_app);

    return 0;
}
