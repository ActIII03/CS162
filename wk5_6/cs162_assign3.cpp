#include <fstream>
#include <cctype>
#include <iostream>

const int SIZE = 20;
const int BIO = 100;
const int DESC = 140;
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

//void greet();
void read_txt_file(hero_type new_hero[], int & counter);
//void greet();
int menu_response(int & response);
void create_enter(hero_type new_hero[], int & counter);
void create_message();
void write_to_file( hero_type new_hero[], int counter);
int pick_hero_display(hero_type new_hero[], int & user_pick);
void display_heroes(hero_type new_hero[]);

int main()
{
    hero_type new_hero[MAX];
    int response, counter = 0, user_pick = 0;
    
    read_txt_file(new_hero, counter);
    //greet();
    // do   <----- Add Do-While once done with Menu
    menu_response(response);
    switch (response)
    {
        case 1:
            create_enter(new_hero, counter);
            write_to_file(new_hero, counter);
            break;
        case 2:
            pick_hero_display(new_hero, user_pick);
            break;
        case 3:
            //quit();
            break;
        default:
            cout << "wrong choice!";
    }

    return 0;
}

/*void greet()  //Add newline after each line?
{
    cout << "                                   T\\ T\\                             "
         << "                                   |\\| \\                             "
         << "                                   |  |  :                             "
         << "                              _____I__I  |                             "
         << "                            .'            '.                           "
         << "                          .'                '                          "
         << "                          |   ..             '                         "
         << "                          |  /__.            |                         "
         << "                          :.' -'             |                         "
         << "                         /__.                |                         "
         << "                        /__, \\               |                        "
         << "                           |_\\        _|    |                         "
         << "                           :  '\\     .'|     |                        "
         << "                           |___|_,,,/  |     |    _..--.               "
         << "                        ,--_-   |     /'      \\../ /  /\\\\           "
         << "                       ,'|_ I---|    7    ,,,_/ / ,  / _\\\\           "
         << "                     ,-- 7 \\|  / ___..,,/   /  ,  ,_/   '-----.       "
         << "                    /   ,   \\  |/  ,____,,,__,,__/            '\\     "
         << "                   ,   ,     \\__,,/                             |     "
         << "                   | '.       _..---.._                         !.     "
         << "                   ! |      .' A_C__T. '.                        |     "
         << "                   .:'      | (-_ _--')  :          L            !     "
         << "                   .'.       '.  Y    _.'             \\,         :    "
         << "                    .          '-----'                 !          .    "
         << "                   .           /  \\                   .          .    "
         << "Welcom to the Super-hero Repo! \nThis program is used for store information in regards to super-heroes!"
         << "\nThere are some pre-made." << endl;
}*/

void read_txt_file(hero_type new_hero[], int & counter)
{
    ifstream in_file;
    in_file.open("super_heroes.txt");
    char delimiter = ':';
    if(in_file)
    {
        for(int index = 0;!in_file.eof(); ++index)
        {
           in_file.get(new_hero[index].name, SIZE, delimiter);       
           in_file.ignore();
           in_file.get(new_hero[index].identity, SIZE, delimiter);       
           in_file.ignore();
           in_file.get(new_hero[index].power, SIZE, delimiter);       
           in_file.ignore();
           in_file.get(new_hero[index].lover, SIZE, delimiter);       
           in_file.ignore();
           in_file.get(new_hero[index].origin, BIO, delimiter);       
           in_file.ignore();
           in_file.get(new_hero[index].opinion, DESC, delimiter);       
           in_file.ignore(100, '\n');
           ++counter;
           while(in_file && !in_file.eof())    
           {
                in_file.get(new_hero[index+1].name, SIZE, delimiter);       
                in_file.ignore();
           }
        }
       in_file.close();
       in_file.clear();
    }
}

int menu_response(int & response)
{
    cout << "Please enter a number for the choices listed below:\n"
         << "(1) Create/Enter New Super hero\n"
         << "(2) Display Heroes\n"
         << "(3) Quit Program\n"
         << "Enter choice(1-3): ";
    cin >> response;
    cin.ignore(100,'\n');
    return response;
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
    out_file.open("super_heroes.txt", ios::app);
    out_file << "**********************************New Hero Entry*******************************\n";

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
        if(isspace(new_hero[struct_index].name[0]))
            stop_display = true;
        else
            cout << "(" << struct_index+1 << "): " << new_hero[struct_index].name << endl;
    }
    cout << "From the list above, please pick a hero to display infromation about them.\n"
         << "Choice(1-10): ";
}


void display_picked_hero(hero_type new_hero[], int user_pick)
{
    for(int struct_index = user_pick - 1; stop_display == false;)
    {
        cout << "Name: " << new_hero[struct_index].name << endl;
        cout << "Identity: " << new_hero[struct_index].identity << endl;
        cout << "Name: " << new_hero[struct_index].name << endl;
    }
    cout << "From the list above, please pick a hero to display infromation about them.\n"
         << "Choice(1-10): ";
}

int pick_hero_display(hero_type new_hero[], int & user_pick)
{
    display_heroes(new_hero);
    return 0; 
}
