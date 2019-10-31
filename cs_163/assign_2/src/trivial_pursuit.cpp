//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "trivial_pursuit.h"

trivial_pursuit::trivial_pursuit()
{
    not_answered = NULL;
    correct = NULL;
    wrong = NULL;
}

trivial_pursuit::~trivial_pursuit()
{

    if(not_answered)
        not_answered = NULL;
    if(correct)
        correct = NULL;
    if(wrong)
        wrong = NULL;

}

int get_char(answer & player_ans)
{

    //Stub
    
    return 0;
}

int get_menu_choice(int & choice)
{

    //Stub

    return 0;

}

//UPdate to class function
bool readin_txt_file()
{
    //Create ifstrem obj
    ifstream in_file;
    in_file.open("questions_answers.txt");
    char delimiter = ";";
    
    if(in_file)
    {

        in_file.get(question, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(answer, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        stack.push(question, answer);

        //for(;in_file && !in_file.eof();)
        //{
    }

    return true;
    
    
}
