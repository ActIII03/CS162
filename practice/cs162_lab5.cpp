//Put your header comments here with your name, class
//and purpose of the program

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//golbal constant
const int SIZE_NAME = 30;
//Place your structure definition here (globally):
struct course
{
    int crn[7];
    char course_desig[7];
    int section[3];
};

struct student
{
    char first_name[SIZE_NAME];
    char middle_name[SIZE_NAME];
    char last_name[SIZE_NAME];
};

//Place any prototypes that use the structure here:
void read_char(char prompt[], int max_size, char result[]);
void read_int(char prompt[], int max_size, int result[]);
void read_student(student &);
void read_course (course &);
void display(student & person, course & the_course);

int main()
{
     //Create a variable of the struct here:
    course c[10];
    student s[10];
     //Call the functions here:
    read_student(s);
    read_course(c);
    display(s, c);

    return 0;
}

//Implement the body of the functions here:
void read_char(char prompt[], int max_size, char result[])
{
    cout << prompt;
    cin.get(result, max_size, '\n');
    cin.ignore(100, '\n');
}


void read_int(char prompt[], int max_size, int result[])
{
    cout << prompt;
    for (int index = 0; index < max_size; ++index)
    {
        cin >> result[index];
        cin.ignore(100, '\n');
    }
}

void read_student(student & full_name)
{
    read_char("Please enter your first name : ", SIZE_NAME, full_name.first_name);
    read_char("Please enter your middle name : ", SIZE_NAME, full_name.middle_name);
    read_char("Please enter your last name : ", SIZE_NAME, full_name.last_name);
}

void read_course (course & a_course)
{
    read_int("Please enter the CRN: ", 7, a_course.crn);
    read_char("Please enter the Course Designator: ", 7, a_course.course_desig);
    read_int("Please enter Section Number: ", 4, a_course.section);
}


void display(student & person, course & the_course)
{
    cout << "First name: " << person.first_name << endl;
    cout << "Middle name: " << person.middle_name << endl;
    cout << "Last name: " << person.last_name << endl;

    for (int index = 0; index < 8; ++index)
        cout << "CRN: " << the_course.crn[index] << endl;
    cout << "Course designation: " << the_course.course_desig << endl;
    for(int index = 0; index < 4; ++index)
        cout << "Section: " << the_course.section[index] << endl;
}
