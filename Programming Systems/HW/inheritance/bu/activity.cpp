//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System
#include "activity.h"

void read_activity(activity & read_in)
{
    read_in.read();
}

void display_activity(activity * one_activity[])
{
    for(int index = 0; index < 2; ++index)
        one_activity[index] -> display();
}

void copy_activity(activity & to_copy)
{
}

bool again()
{
    char choice;

    cout << "Would you like to go again?(Y/N): ";
    cin >> choice;
    cin.ignore(MAX, '\n');

    if(toupper(choice) == 'Y')
        return true;
    return false;
}

activity::activity()
{
    name_of_activity = NULL;
    category = NULL;
}

activity::activity(char * act_name, char * act_type, struct act_time & new_time)
{
    name_of_activity = new char[strlen(act_name) + 1];
    strcpy(name_of_activity, act_name);
    category = new char[strlen(act_type) + 1];
    strcpy(category, act_type);
    new_time.length_hour = new_act_time.length_hour;
    new_time.length_minute = new_act_time.length_minute;
    new_time. hour = new_act_time.hour;
    new_time.minute = new_act_time.minute;
    new_time.midday = new_act_time.midday;
}

activity::activity(activity & to_copy)
{
    name_of_activity = new char[strlen(to_copy.name_of_activity) + 1];
    strcpy(name_of_activity, to_copy.name_of_activity);
    category = new char[strlen(to_copy.category) + 1];
    strcpy(category, to_copy.category);
    //length = to_copy.length;
}

void activity::read()
{
    char temp[MAX];
    char check[] = {"WORK"};
    char choice;
    int number;
    bool midday = true, require = false;

    cout << "Please enter name of activity: ";
    cin.get(temp, MAX, '\n');
    cin.ignore(MAX, '\n');
    name_of_activity = new char[strlen(temp) + 1];
    strcpy(name_of_activity, temp);
    cout << "Please enter category of activity(Hobby, Work, or School): ";
    cin.get(temp, MAX, '\n');
    cin.ignore(MAX, '\n');
    category = new char[strlen(temp) + 1];
    strcpy(category, temp);

    do
    {
        cout << "Please enter length of activity(Hour): ";
        cin >> number;
        cin.ignore(MAX, '\n');

        for(int i=0; category[i] != '\0'; i++)
        {
            category[i] = toupper(category[i]);
        }
        //If work, then length has to be between 6 - 8 hrs
        if( strcmp(category, check) == 0)
        {
            if(number < 6 || number > 8)
            {
                cout << "Sorry, you work has to be between 6 hours and 8 hours in length!"
                     << "\nPlease input correct apporiate time!";
                require = true;
            }
            else
                require = false;
        }

    }while(require);

    new_act_time.length_hour = number;
    cout << "Please enter length of activity(Minutes): ";
    cin >> number;
    cin.ignore(MAX, '\n');
    new_act_time.length_minute = number;
    cout << "Please enter time of day(1-12): ";
    cin >> number;
    cin.ignore(MAX, '\n');
    new_act_time.hour = number;
    cout << "Please enter time of day(1-59): ";
    cin >> number;
    cin.ignore(MAX, '\n');
    new_act_time.minute = number;
    cout << "A.M. or P.M.?(Y = A.M./ N = P.M.): ";
    cin >> choice;
    cin.ignore(MAX, '\n');
    if( toupper(choice) != 'Y')
        midday = false;
    new_act_time.midday = midday;

}

void activity::display()
{
    cout << "\nName of activity: " << name_of_activity
         << "\nCategory of activity: " << category
         << "\nTime: " << new_act_time.hour << ":"
         << new_act_time.minute << " ";
    if(new_act_time.midday)
        cout << "a.m." << endl;
    else
        cout << "p.m." << endl;

}

int activity::compare(const activity & to_compare)
{
    bool match = false;

    if(strcmp(name_of_activity, to_compare.name_of_activity) == 0)
        match = true;
    if(strcmp(category, to_compare.category) != 0)
        match = false;
    return match;

}

void activity::copy(activity & to_copy)
{

    name_of_activity = new char[strlen(to_copy.name_of_activity) + 1];
    strcpy(name_of_activity, to_copy.name_of_activity);
    category = new char[strlen(to_copy.category) + 1];
    strcpy(category, to_copy.category);
    new_act_time.length_hour = to_copy.new_act_time.length_hour;
    new_act_time.length_minute = to_copy.new_act_time.length_minute;
    new_act_time.hour = to_copy.new_act_time.hour;
    new_act_time.minute = to_copy.new_act_time.minute;
    new_act_time.midday = to_copy.new_act_time.midday;
}

int activity::check_datatype(){return 0;}

activity::~activity()
{
    if(name_of_activity)
    {
        delete name_of_activity;
        name_of_activity = NULL;
    }
    if(category)
    {
        delete category;
        category = NULL;
    }
}

hobby::hobby()
{
   require_items = NULL;
}

hobby::hobby(bool items)
{
    require_items = items;
}

hobby::hobby(hobby & fun)
{
    require_items = fun.require_items;
}

void hobby::read()
{
    char choice;
    cout << "Are item required?(Y/N) :";
    cin >> choice;
    cin.ignore(MAX, '\n');

    if(toupper(choice) == 'Y')
        require_items = true;
    else
        require_items = false;
}

void hobby::display()
{
    if(require_items)
        cout << "Require items: YES" << endl;
}

void hobby::copy(activity & to_copy)
{

}

int hobby::check_datatype(){return 1;}

hobby::~hobby()
{

}

work::work()
{
    job_name = NULL;
}

work::work(char * j_name)
{
    job_name = new char[strlen(j_name) + 1];
    strcpy(job_name, j_name);
}

work::work(work & job)
{
    job_name = new char[strlen(job.job_name) + 1];
    strcpy(job_name, job.job_name);
}

void work::read()
{
    char temp[MAX];
    cout << "What is the job title: ";
    cin.get(temp, MAX, '\n');
    cin.ignore(MAX, '\n');
    job_name = new char[strlen(temp) + 1];
    strcpy(job_name, temp);
}

void work::display()
{
    cout << "Job Name: " << job_name << endl;
}

void work::copy(work & to_copy)
{
}

int work::check_datatype(){return 2;}

work::~work()
{
    if(job_name)
    {
        delete job_name;
        job_name = NULL;
    }
}

school::school()
{
    assignment = NULL;

}

school::school(char * cl_name, char * assign_name)
{
    assignment = new char[strlen(assign_name) + 1];
    strcpy(assignment, assign_name);
    class_name = new char[strlen(cl_name) + 1];
    strcpy(class_name, cl_name);
}

school::school(school & education)
{
    assignment = new char[strlen(education.assignment) + 1];
    strcpy(assignment, education.assignment);
    class_name = new char[strlen(education.class_name) + 1];
    strcpy(class_name, education.class_name);
}

void school::read()
{
    char temp[MAX];

    cout << "Please enter the name of the class: ";
    cin.get(temp, MAX, '\n');
    cin.ignore(MAX, '\n');
    class_name = new char[strlen(temp) + 1];
    strcpy(class_name, temp);

    cout << "Please enter the name of the class: ";
    cin.get(temp, MAX, '\n');
    cin.ignore(MAX, '\n');
    class_name = new char[strlen(temp) + 1];
    strcpy(class_name, temp);

}

void school::display()
{
    cout << "\nClass Name: " << class_name
         << "\nAssignment: " << assignment << endl;
}

int school::check_datatype(){return 3;}

void school::copy(activity & to_copy){}

school::~school()
{
    if(class_name)
    {
        delete class_name;
        class_name = NULL;
    }
    if(assignment)
    {
        delete assignment;
        assignment = NULL;
    }
}
