//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "trivial_pursuit.h"

int main(void)
{
    trivial_pursuit play_game;

    char question_1[BUFFER];
    char question_2[BUFFER];
    char question_3[BUFFER];

    char answer_1[BUFFER];
    char answer_2[BUFFER];
    char answer_3[BUFFER];

    ifstream in_file;
    in_file.open("questions_answers.txt");
    char delimiter = ';';
    
    //Check for file success
    if(in_file)
    {
        //Read in the first three questions and answers
        in_file.get(question_1, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(answer_1, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(question_2, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(answer_2, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(question_3, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        in_file.get(answer_3, BUFFER, delimiter);
        in_file.ignore(100, '\n');
        
        //Update to where t_p obj passes to stack obj
        play_game.get_txt(question_1, answer_1, question_2, answer_2, question_3, answer_3);

        //Push 4 more cards to the stack and enqueue
        for(;in_file && !in_file.eof();)
        {
            in_file.get(question_1, BUFFER, delimiter);
            in_file.ignore(100, '\n');
            in_file.get(answer_1, BUFFER, delimiter);
            in_file.ignore(100, '\n');
            in_file.get(question_2, BUFFER, delimiter);
            in_file.ignore(100, '\n');
            in_file.get(answer_2, BUFFER, delimiter);
            in_file.ignore(100, '\n');
            in_file.get(question_3, BUFFER, delimiter);
            in_file.ignore(100, '\n');
            in_file.get(answer_3, BUFFER, delimiter);
            in_file.ignore(100, '\n');
            
            //Update to where t_p obj passes to stack obj
            play_game.get_txt(question_1, answer_1, question_2, answer_2, question_3, answer_3);
        }
    }


    return 0;
}
