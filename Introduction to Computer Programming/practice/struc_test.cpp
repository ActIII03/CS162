#include <iostream>

using namespace std;

const int NAME = 20;

struct student_type
{
    char first_name[NAME];
    char middle_name[NAME];
    char last_name[NAME];
    char course_grade;
    int test_score;
    int program_score;
    double GPA;
};

void read_char(char prompt[], int max_size, char result[]);
void new_student(student_type&);

int main(void)
{
    student_type new_student;
    student_type student;

    return 0;
}

void read_char(char prompt[], int max_size, char result[])
{
    cout << prompt << endl;
    cin.get(result, max_size, '\n');
    cin.ignore(100, '\n');
}
