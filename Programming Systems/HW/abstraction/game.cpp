//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Game Abstract Base Class

#include "game.h"

//Helper functions implementations

bool again()
{
    char choice;

    std::cout << "Would you like to go again?(Y/N): ";
    std::cin >> choice;
    std::cin.ignore(MAX, '\n');

    if(toupper(choice) == 'Y')
        return true;
    return false;
}

int Game::play_game()
{
    return 0;
}

Game::Game()
{
}

Game::~Game(){}

//Work on later
NumberSequence::NumberSequence()
{
    difficulty = 0;
    num1 = 0;
    num2 = 0;
    num3 = 0;
    user_guess_a = 0;
    user_guess_b = 0;
    user_guess_c = 0;
    sum_of_seq = 0;
    prod_of_seq = 0;
}

//Game explanation
void NumberSequence::print_introduction()
{
    std::cout << "This game is guess the three-number sequence based by provided hints.\n";
}

void NumberSequence::gen_num()
{

    //Use time for number sequence
    srand(time(NULL)); 
    difficulty = rand() % 5 + 1; // [1-5]

    //number seq. can be guess the either: (1) sum of three integers (2) product of three integers
    //num1 = rand() % difficulty + difficulty;
    //num2 = rand() % difficulty + difficulty;
    //num3 = rand() % difficulty + difficulty;

    num1 = rand() % 5 + 1;
    num2 = rand() % 5 + 1;
    num3 = rand() % 5 + 1;

    sum_of_seq = num1 + num2 + num3;
    prod_of_seq = num1 * num2 * num3;
}

void NumberSequence::read_in()
{

    std::cin >> user_guess_a >> user_guess_b >> user_guess_c;
    std::cin.ignore(MAX, '\n');
}

//Number sequence guesser
int NumberSequence::play_game()
{
    print_introduction();
    gen_num();

    // Display sume and produxt of the three integers 
    std::cout << "+ There are 3 numbers in this sequence";
    std::cout << "\n+ The sequnce adds up to: " << sum_of_seq;
    std::cout << "\n+ The sequence when multiplied gives: " << prod_of_seq << std::endl;

    read_in();

    //Create sum and product from user's three, supplied integers
    int user_guess_sum = user_guess_a + user_guess_b + user_guess_c;
    int user_guess_product = user_guess_a * user_guess_b * user_guess_c;

    // Compare user's sum and product and between randomly generated sum and product
    if (user_guess_sum == sum_of_seq && user_guess_product == prod_of_seq)
    {
        std::cout << "\n*** Well done player! You have extracted a file! Keep going! ***";
        return 1;
    }
    else
    {
        std::cout << "\n*** You entered the sequence! Try again! ***";
        return 0;
    }
}

GuessNumber::GuessNumber()
{
    rand_num = 0;
    max_rand_num = 10;
    max_tries = 3;
    user_guess = 0;
    num_of_tries = 0;
}

void GuessNumber::print_introduction()
{
    std::cout << "This is the Guess the Number game\n";
}

void GuessNumber::gen_num()
{

    srand(time(NULL));
    max_rand_num = 10;
    rand_num = rand() % max_rand_num + 1;
}

void GuessNumber::read_in()
{
    std::cin >> user_guess;
    std::cin.ignore(MAX, '\n');
}

int GuessNumber::play_game()
{
    print_introduction();
    gen_num();

    int score = 0;

    std::cout << "You have " << (max_tries + 1) << " tries to guess right and if you don't exceed, then you score a point!" << std::endl;

    do 
    {
        std::cout << "Find the number between 1 and " << max_rand_num << ": " << std::endl;
        read_in();
        ++num_of_tries;

        if(user_guess < rand_num)
        {
            std::cout << (rand_num - user_guess) << " away from random number. " << std::endl;
            std::cout << num_of_tries << " tries left!" << std::endl;
        }
        else if(user_guess > rand_num)
        {
            std::cout << (user_guess - rand_num) << " away from random number. " << std::endl;
            std::cout << num_of_tries << " tries left!" << std::endl;
        }

    } while(num_of_tries < max_tries && user_guess != rand_num);

    if(num_of_tries >= max_tries)
    {
        std::cout << "Success! The number was " << rand_num << std::endl;
        ++score;
    }
    else
        std::cout << "Game over! Random number was:" << rand_num << std::endl;

    return score;
}

WhackANumber::WhackANumber()
{
    number_to_whack = 0;
    user_guess = 0;
    max_number = 100;
    fail = false;
    sucesses = 0;
    max_time_seconds = 15;
}

void WhackANumber::print_introduction()
{
    std::cout << "This is a timed-number game. The more you guess, the less time the next number will be displayed. This will test how fast you remeber the displayed number.\n";
}

void WhackANumber::gen_num()
{
    number_to_whack = rand() % max_number + 1;
}

void WhackANumber::read_in()
{
    std::cin >> user_guess;
    std::cin.ignore(MAX, '\n');
}

int WhackANumber::play_game()
{
    print_introduction();

    int technical_win = 10;
    std::cout << "If you get more thatn 10 rounds, you will score a win!" << std::endl;

    //For the microsecond conversion
    long multiplier = 1000000;
    long pause = multiplier * 5;

    do
    {
        gen_num();
        std::cout << "The number is between 1 and 100. Generating Number. Wait for it!\n";

        //Delay function call
        usleep(pause);
        std::cout << "Number to whack (Memorize): " << number_to_whack << std::endl;
        usleep( (multiplier * max_time_seconds) );
        std::system("clear"); // Only did linux
        std::cout << "What was the number?(1 - 100): ";
        std::cin >> user_guess;
        std::cin.ignore(MAX, '\n');
        if(user_guess != number_to_whack)
        {
            std::cout << "Sorry, that's incorrect! Game over!" << std::endl;
            fail = true;
        }
        else if(max_time_seconds > 1)
        {
            std::cout << "Nice! Faster!" << std::endl;
            --max_time_seconds;
            ++score;
        }
        else
        {
            std::cout << "Nice! Keep Going!" << std::endl;
            ++score;
        }

        
    } while(!fail);

    if(score > technical_win)
        return 0;
    return 1;
}

