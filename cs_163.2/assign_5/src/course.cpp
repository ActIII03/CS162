//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: Client Program implementation

#include "course.h"


Course::Course()
{
    class_name = NULL;
}

Course::~Course()
{
    if(class_name)
    {
        delete [] class_name;
        class_name = NULL;
    }

}

int Course::get_input(char * get_class)
{

    if(!get_class)
        return -99;

    class_name = new char[strlen(get_class) + 1];
    strcpy(class_name, get_class);

    return 0;
}

int Course::copy_entry(Course & to_copy)
{
    if(!to_copy.class_name)
        return -99;
    else if(class_name)
    {
        delete [] class_name;
    }

    class_name = new char[strlen(to_copy.class_name) + 1];
    strcpy(class_name, to_copy.class_name);

    return 0;

}

int Course::delete_class()
{
    delete [] class_name;
    class_name = NULL;
    return 0;
}


int Course::compare(char * is_match)
{
    int result = 0;

    if(strcmp(class_name, is_match) == 0)
        return result;
    return result + 1;

}

void Course::display()
{
    cout << "\nClass name: " << class_name << endl;
}

int menu()
{
    int choice = 0;

    cout << "Please select an option\n(1) Add a course\n(2) Add a pre-req to course\n(3) Display Pre-req to a class\n(4) Quit"
         << "\nChoice: ";
    cin >> choice;
    cin.ignore(100, '\n');
    return choice;
}
