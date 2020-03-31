//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: Client Program

#include "course.h"
#include "graph.h"

int main()
{

    Course add_course;
    table my_courses;

    int result = 0;
    bool quit = false;

    char course[30], related_course[30];

    do
    {
        switch(menu())
        {
            case 1:
                //Add a course
                cout << "Please enter a course you like to add to the list: ";
                cin.get(course, 30, '\n');
                cin.ignore(100, '\n');
                add_course.get_input(course);
                result = my_courses.insert_vertex(add_course);
                if(!result)
                    cout << "\nSomething went wrong, try again!" << endl;
                else
                    cout << "\nSuccessful add!" << endl;
                add_course.delete_class();

                break;
                
            case 2:
                //Add to pre-req list
                cout << "\nPlease enter the course you want to add a pre-req for: ";
                cin.get(related_course, 30, '\n');
                cin.ignore(100, '\n');
                cout << "\nPlease enter the pre-req course: ";
                cin.get(course, 100, '\n');
                cin.ignore(100, '\n');
                result = my_courses.insert_edge(related_course, course);
                if(result)
                    cout << "\nSomething went wrong, try again!" << endl;
                else
                    cout << "\nSuccessful add!" << endl;

                break;

            case 3:
                //Display pre-req list
                cout << "\nPlease enter a course you would like to see the pre-req's for: ";
                cin.get(course, 30, '\n');
                cin.ignore(100, '\n');
                result = my_courses.display_adj(course);
                if(result)
                    cout << "\nSomething went wrong, try again!" << endl;
                else
                    cout << "\nSuccessful display!" << endl;

                break;

            case 4:
                //Quit
                quit = true;

                break;

        };
    }while(!quit);

    return 0;
}
