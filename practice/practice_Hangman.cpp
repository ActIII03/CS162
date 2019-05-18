#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int ALPHA_SIZE = 26; 
const int SIZE = 21;
int main()
{
    char secret[SIZE];
    char answer[SIZE];
    char guess[ALPHA_SIZE];
    int guess_length = 0, player_1_score = 0 ; player_2_score = 0;

    return 0;
}

//The function gets the user guess
void get_guess(char secret[], char answer[], char guess[], int guess_length)
{
        char c; 
        bool found = true;
       
        //Goes into loop with found =false and turn true if the user already inputted already guessed variable
        do
        {
            found = false;
            cin >> player_guess;
            for(int i =0; i < guess_length; ++i)
            {
                if(guess[i] == player_guess)
                {
                    found = true;
                    cout << "You've already entered the letter" << player_guess << "." << endl;
                }
            }
        } while (found);

        //legit guess
        guess[++guess_length] = player_guess;
        //Check array
        for(int i = 0; i < strlen(secret); ++i)
        {
            if(secret[i] == player_guess)
            {
                answer[i] = player_guess;
            }
        }
        return geuss_length;
}
        

