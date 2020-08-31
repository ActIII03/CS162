//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System

#include "activity.h"
#include "person.h"

//Steps:
// (1) Work on "is-a" relationship and do unit-testing
// (2) Then create Node 

int main(void)
{

    person new_user;

    int number_of_days = 0 , buffer = 0, entries = 0;
    char temp[MAX];
    activity * new_act;
    hobby * fun;
    work * job;
    school * ed;

    cout << "What's your first name?(John): ";
    cin.get(temp, MAX, '\n');
    cin.ignore(MAX, '\n');

    person * user = new person(temp);

    //Generate table of days <--- come back after doing activity hiearchy
    cout << "How many days are planning for? ( 1 day - n days):";
    cin >> number_of_days;
    cin.ignore(MAX, '\n');
    user -> create_day_planner(number_of_days);

    //Add activity to activity planner
    do
    {
        //Create Entry and increment entries
        do
        {
            new_act = new activity();
            read_activity(*new_act);
            cout << "What type of activity are planning?:\n"
                 << "(1) Hobby\n"
                 << "(2) Work\n"
                 << "(3) School\n"
                 << "Choice (1-3): ";
            cin >> buffer;
            cin.ignore(MAX, '\n');

                switch(buffer)
                {
                    case 1:
                        fun = new hobby();
                        read_activity(*fun);
                        break;
                    case 2:
                        job = new work();
                        read_activity(*job);
                        break;
                    case 3:
                        ed = new school();
                        read_activity(*ed);
                        break;
                }
                switch(buffer)
                {
                    case 1:
                        delete fun;
                        break;
                    case 2:
                        delete job;
                        break;
                    case 3:
                        delete ed;
                        break;
                }
                delete new_act;

            ++entries;
        }while(again() && entries < number_of_days);


        //Display entry
        user -> display();

    } while(again());// Display or Add entruy if already not full


    return 0;
}
