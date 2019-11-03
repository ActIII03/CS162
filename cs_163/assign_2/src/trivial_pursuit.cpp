//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "trivial_pursuit.h"

trivial_pursuit::trivial_pursuit()
{
    new_q_a = NULL;
    player_stack = NULL;
    discard_stack = NULL;
}

trivial_pursuit::~trivial_pursuit()
{

    if(new_q_a)
        new_q_a = NULL;
    if(player_stack)
        player_stack = NULL;
    if(discard_stack)
        discard_stack = NULL;

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

bool trivial_pursuit::readin_txt_file()
{
    //Create ifstrem obj
    questions n_questions, answer n_answers;
    ifstream in_file;
    in_file.open("questions_answers.txt");
    char delimiter = ";";
    
    //Check for file success
    if(in_file)
    {
        //Read in the first three questions and answers
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

        //Push 4 more cards to the stack and enqueue
        for(;in_file && !in_file.eof();)
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
            new_q_a.push(n_question, n_answer);
        }
    }

    return true;
}
