#include <fstream>
#include <cctype>
#include <iostream>

const int SIZE = 20;
const int BIO = 180;
const int DESC = 200;
const int MAX = 10;

using namespace std;

struct hero_type
{
    char name[SIZE];
    char identity[SIZE];
    char power[SIZE];
    char lover[SIZE];
    char origin[BIO];
    char opinion[DESC];
};

void greet();
void read_txt_file(hero_type new_hero[], int & counter);
int menu_response(int & choice);
void create_enter(hero_type new_hero[], int & counter);
void create_message();
void write_to_file( hero_type new_hero[], int counter);
void pick_hero_display(hero_type new_hero[]);
void search_picked_hero(hero_type new_hero[]);
void display_heroes(hero_type new_hero[]);
bool ask_again(bool & again);
bool quit(bool & response);

int main()
{
    hero_type new_hero[MAX];
    int choice = 0, counter = 0;
    bool decision = true; 
    read_txt_file(new_hero, counter);
    greet();
    menu_response(choice);
    do
    {
        switch (choice)
        {
            case 1:
                create_enter(new_hero, counter);
                write_to_file(new_hero, counter);
                break;
            case 2:
                pick_hero_display(new_hero);
                break;
            case 3:
                quit(decision);
                break;
            default:
                cout << "wrong choice!";
        }
        choice = 0;
        if(decision == true)
            menu_response(choice);
    }
    while(counter < MAX && decision == true);

    return 0;
}

void greet()  //Add newline after each line?
{
    cout << "                                   T\\ T\\\n"
         << "                                   |\\| \\\n"
         << "                                   |  |  :\n"
         << "                              _____I__I  |\n"
         << "                            .'            '.\n"
         << "                          .'                '\n"
         << "                          |   ..             '\n"
         << "                          |  /__.            |\n"
         << "                          :.' -'             |\n"
         << "                         /__.                |\n"
         << "                        /__, \\              |\n"
         << "                           |_\\        _|    |\n"
         << "                           :  '\\     .'|    |\n"
         << "                           |___|_,,,/  |     |    _..--.\n"
         << "                        ,--_-   |     /'      \\../ /  /\\\\\n"
         << "                       ,'|_ I---|    7    ,,,_/ / ,  / _\\\\\n"
         << "                     ,-- 7 \\|  / ___..,,/   /  ,  ,_/   '-----.\n"
         << "                    /   ,   \\  |/  ,____,,,__,,__/            '\\\n"
         << "                   ,   ,     \\__,,/                             |\n"
         << "                   | '.       _..---.._                          !.\n"
         << "                   ! |      .' A_C__T. '.                        |\n"
         << "                   .:'      | (-_ _--')  :          L            !\n"
         << "                   .'.       '.  Y    _.'             \\,         :\n"
         << "                    .          '-----'                 !          .\n"
         << "                   .           /  \\                   .          .\n"
         << "Welcom to the Super-hero Repo! \nThis program is used for store information in regards to super-heroes!"
         << "\nThere are some pre-made." << endl;
}

void read_txt_file(hero_type new_hero[], int & counter)
{
    ifstream in_file;
    in_file.open("super_hero.txt");
    char delimiter = ':';
    int index = 0;
    if(in_file)
    {

       in_file.get(new_hero[index].name, SIZE, delimiter);       
       in_file.ignore();
        for(;in_file && !in_file.eof(); ++index)
        {
           in_file.get(new_hero[index].identity, SIZE, delimiter);       
           in_file.ignore();
           in_file.get(new_hero[index].power, SIZE, delimiter);       
           in_file.ignore();
           in_file.get(new_hero[index].lover, SIZE, delimiter);       
           in_file.ignore();
           in_file.get(new_hero[index].origin, BIO, delimiter);       
           in_file.ignore();
           in_file.get(new_hero[index].opinion, DESC, '\n');       
           in_file.ignore();
           ++counter;
           in_file.get(new_hero[index+1].name, SIZE, delimiter);       
           in_file.ignore();
        }
       in_file.close();
       in_file.clear();
    }
}

int menu_response(int & choice)
{
    cout << "Please enter a number for the choices listed below:\n"
         << "(1) Create/Enter New Super hero\n"
         << "(2) Display Heroes\n"
         << "(3) Quit Program\n"
         << "Enter choice(1-3): ";
    cin >> choice;
    cin.ignore(100,'\n');
    return choice;
} 

void create_enter(hero_type new_hero[], int & counter)
{
    create_message();
    cout << "Name: ";
    cin.get(new_hero[counter].name, SIZE, '\n');
    cin.ignore(100, '\n');
    cout << "Identity: ";
    cin.get(new_hero[counter].identity, SIZE, '\n');
    cin.ignore();
    cout << "Powers: ";
    cin.get(new_hero[counter].power, SIZE, '\n');
    cin.ignore(100,'\n');
    cout << "Lover: ";
    cin.get(new_hero[counter].lover, SIZE, '\n');
    cin.ignore(100,'\n');
    cout << "Origin: ";
    cin.get(new_hero[counter].origin, BIO, '\n');
    cin.ignore(100,'\n');
    cout << "Youre Opinion: ";
    cin.get(new_hero[counter].opinion, DESC, '\n');
    cin.ignore(100,'\n');

    ++counter;

}

void create_message()
{
    cout << "Okay, So you want to create a new entry for hero!\n"
         << "Items this program keeps track of is:\n"
         << "(1) Name\n(2)Identity\n(3)Super-Powers\n(4)Lover\n(5)Origin\n(6)Your Description\n";
}


void write_to_file( hero_type new_hero[], int counter)
{
    ofstream out_file;
    bool loop = true;
    counter = counter - 1;
    char delimiter = ':', separator = '\n';
    out_file.open("super_hero.txt", ios::app);

    if(out_file)
    {
        while(loop)
        {
            out_file << new_hero[counter].name << delimiter
                     << new_hero[counter].identity << delimiter
                     << new_hero[counter].power << delimiter
                     << new_hero[counter].lover << delimiter
                     << new_hero[counter].origin << delimiter
                     << new_hero[counter].opinion << separator;
            out_file.close();
            out_file.clear();
            loop = false;
        }
    }
}


void display_heroes(hero_type new_hero[])
{
    bool stop_display = false;
    for(int struct_index = 0; struct_index <= MAX && stop_display == false; ++struct_index)
    {
        if(new_hero[struct_index].name[0] == '\0')
            stop_display = true;
        else
            cout << "(" << struct_index+1 << "): " << new_hero[struct_index].name << endl;
    }
    cout << "From the list above, please pick a hero to display information about them.\n"
         << "Choice(Name): ";
}


void search_picked_hero(hero_type new_hero[])
{
    int struct_index = -1;
    bool flag = false;
    char user_pick[SIZE];
    cin.get(user_pick, SIZE, '\n');
    cin.ignore();
    do
    {
        ++struct_index; 
        if(strcmp(new_hero[struct_index].name, user_pick) == 0)
           flag = true;
    }
    while(flag == false);

    cout << "Name: " << new_hero[struct_index].name << endl;
    cout << "Identity: " << new_hero[struct_index].identity << endl;
    cout << "Power: " << new_hero[struct_index].power << endl;
    cout << "Lover: " << new_hero[struct_index].lover << endl;
    cout << "Origin: " << new_hero[struct_index].origin << endl;
    cout << "Opinion: " << new_hero[struct_index].opinion << endl;
}

bool ask_again(bool & again)
{
    char input = 'Y';
    again = true;
    cout << "Would you like to search another profile?\n"
         << "Choice(Y/N): ";
    cin >> input;
    cin.ignore();
    if(toupper(input) == 'Y')
    {
        again = true; 
    }
    else if(toupper(input) == 'N')
        again = false;
    else 
        again = false;
    cout << "input: " << input << endl;
    return again;
}

void pick_hero_display(hero_type new_hero[])
{
    bool answer = true;   
    do 
    {
        display_heroes(new_hero);
        search_picked_hero(new_hero);
        ask_again(answer);
    }
    while(answer == true);
}

bool quit(bool & response)
{
    char decision = 'Y';
    cout << "Would you like to re-visit the previous modules?\n"
         << "Response(Y/N): ";
    cin >> decision;
    cin.ignore();
    if(toupper(decision) == 'Y')
        response = true;
    else if(toupper(decision) == 'N')
        response = false;
    return response;
}
