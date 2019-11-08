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
   
    int remain_turn = 10;
    //Check for file success
    if(in_file)
    {
        //Read in the first three questions and answers
        in_file.get(question_1, BUFFER, delimiter);
        in_file.ignore(100, delimiter);
        in_file.get(answer_1, BUFFER, delimiter);
        in_file.ignore(100, delimiter);
        in_file.get(question_2, BUFFER, delimiter);
        in_file.ignore(100, delimiter);
        in_file.get(answer_2, BUFFER, delimiter);
        in_file.ignore(100, delimiter);
        in_file.get(question_3, BUFFER, delimiter);
        in_file.ignore(100, delimiter);
        in_file.get(answer_3, BUFFER, delimiter);
        in_file.ignore(100, delimiter);


        
        //Update to where t_p obj passes to stack obj
        play_game.get_txt(question_1, answer_1, question_2, answer_2, question_3, answer_3);

        in_file.get(question_1, BUFFER, delimiter);
        in_file.ignore(100, delimiter);
        in_file.get(answer_1, BUFFER, delimiter);
        in_file.ignore(100, delimiter);

        //Push 4 more cards to the stack and enqueue
        while(in_file && !in_file.eof())
        {
            in_file.get(question_2, BUFFER, delimiter);
            in_file.ignore(100, delimiter);
            in_file.get(answer_2, BUFFER, delimiter);
            in_file.ignore(100, delimiter);
            in_file.get(question_3, BUFFER, delimiter);
            in_file.ignore(100, delimiter);
            in_file.get(answer_3, BUFFER, delimiter);
            in_file.ignore(100, delimiter);
            
            //Update to where t_p obj passes to stack obj
            play_game.get_txt(question_1, answer_1, question_2, answer_2, question_3, answer_3);

            //Prime the pump
            in_file.get(question_1, BUFFER, delimiter);
            in_file.ignore(100, delimiter);
            in_file.get(answer_1, BUFFER, delimiter);
            in_file.ignore(100, delimiter);
        }
    }
    

    //pop from the stack 1 card to answer and along dequeue'ing the first question
    while(remain_turn > 9)
    {
        play_game.get_answer(); 
        --remain_turn;
        cout << "Now Switch players!\n";
    }

    return 0;
}
