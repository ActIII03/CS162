//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant

//Typcial Libraries
#include <iostream>
#include <cctype>
#include <cstring> 
#include <ctime>
#include <typeinfo>
#include <cstddef>
#include <cstdlib>
#include <unistd.h>
//#include <chrono> //Karla approved these for the delay function call in WhackANumber
//#include <thread> //Karla approved these for the delay function call in WhackANumber
//#include <future> //Karla approved these for the delay function call in WhackANUmber
 

#ifndef GAME
#define GAME

const int MAX = 100;

//Abstract Base Class 
class Game
{
    public:
        Game();
        virtual ~Game(); 
        //Explain game to player
        virtual void print_introduction()=0;
        //Generate number sequnce, sum of sequence, and product of sequence
        virtual void gen_num()=0;
        //RTTI function for ABC
        virtual void read_in()=0;
        //Prompt uesr with game and return a boolean value if they gues right
        virtual int play_game();

};
    
class NumberSequence: public Game
{
    public:
        NumberSequence();
        //Explain game to player
        void print_introduction();
        //Generate number sequnce, sum of sequence, and product of sequence
        void gen_num();
        //RTTI function for ABC
        void read_in();
        //Prompt uesr with game and return a boolean value if they gues right
        int play_game();

    protected:
        int difficulty;
        int num1;
        int num2;
        int num3;
        int user_guess_a;
        int user_guess_b;
        int user_guess_c;
        int sum_of_seq;
        int prod_of_seq;

};

class GuessNumber: public Game
{
    public:
        GuessNumber();
        //Explain game rules to user
        void print_introduction();
        //Generate Number for user to guess
        void gen_num();
        //Read in from user RTTI
        void read_in();
        //Prompt uesr with game and return a boolean value if they gues right
        int play_game();

    protected:
        int rand_num;
        int max_rand_num;
        int max_tries;
        int user_guess;
        int num_of_tries;
        


};

class WhackANumber: public Game
{
    public:
        WhackANumber();
        //Explain game rules to user
        void print_introduction();
        //Generate Number for user to guess
        void gen_num();
        //Read in from user RTTI
        void read_in();
        //Prompt uesr with game and return a boolean value if they gues right
        int play_game();

    protected:

        int number_to_whack;
        int user_guess;
        bool fail;
        int sucesses;
        int max_number;
        int max_time_seconds;
};
#endif

//Helper function
bool again();
