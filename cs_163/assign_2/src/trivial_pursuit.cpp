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
    questions n_questions, answer n_answers;
    ifstream in_file;
    in_file.open("questions_answers.txt");
    char delimiter = ";";
    
    if(in_file)
    {

        in_file.get(n_question.question_1, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(answer_1, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(n_question.question_2, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(answer_2, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(n_question.question_3, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(answer_3, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        
        //Push to Stack and eventually enqueue
        new_q_a.push(n_question, n_answer);

        //for(;in_file && !in_file.eof();)
        //{
    }

    return true;
    
    
}
