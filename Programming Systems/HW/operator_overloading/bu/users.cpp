//Name: Armant Touche
//Class: CS202
//Program: FishBowl 
#include "users.h"

user::user()
{
    next = NULL;
    name = NULL;
    passwd = NULL;
    Inbox = NULL;
}

user::user(char * copy_name, char * copy_passwd)
{
    name = new char[strlen(copy_name) + 1];
    strcpy(name, copy_name);
    passwd = new char[strlen(copy_passwd) + 1];
    strcpy(passwd, copy_passwd);
    Inbox = NULL;
}

user::user(user & to_copy)
{
    name = new char[strlen(to_copy.name) + 1];
    strcpy(name, to_copy.name);
    passwd = new char[strlen(to_copy.passwd) + 1];
    strcpy(passwd, to_copy.passwd);
    Inbox = NULL;
}

istream &operator>>(istream & in, user & read_in)
{
    char buffer[MAX];
    int length = 0;
    cout << "Please input a name for Username: ";
    in >> buffer;
    in.ignore(MAX, '\n');
    length = (strlen(buffer) + 1);
    read_in.name = new char[length];
    strcpy(read_in.name, buffer);
    do
    {
        cout << "Please input a name for Password ( 8 - 10 numerals): ";
        cin >> buffer;
        cin.ignore(MAX, '\n');
        length = (strlen(buffer) + 1);

    }while(length < 9 || length > 12);
    read_in.passwd = new char[length];
    strcpy(read_in.passwd, buffer);

    return in;
}

ostream &operator<<(ostream & out, user & read_out)
{
    system("clear");
    out << "Username: "  << read_out.name << endl;
    return out;
}

char * user::get_passwd()
{
    return passwd;
}

user *& user::get_next()
{
    return next;
}

void user::set_next(user *& current)
{
    next = current;
}

bool user::is_match(char * compare_passwd, char * compare_name)
{
    if(strcmp(name, compare_name) == 0)
    {
        if(strcmp(passwd, compare_passwd) == 0)
            return true;
        else
            cout << "Wrong password! Try again.\n";
    }
    return false;
}

int user::user_choice()
{

    //Ask user for choices: (1) Individual chat (2) Forum
    int choice;
    //system("clear");
    cout << "Logged in\n*********************\n"
         << "What would you like to do?( 1 = send message  2 = read message 3 = forum): ";
    cin >> choice;
    cin.ignore(MAX, '\n');
    return choice;

}

message * user::create_message()
{

    message * mess_out = new message;
    cin >> mess_out;
    *mess_out += name; //Add sender's username

    return mess_out;
}

void user::receive(message * add_message)
{
    //Check if Inbox is empty
    if(!Inbox)
    {
        Inbox = new Chat(*add_message);
        //Add name
        *Inbox += *add_message;
        return;
    }
    //Otherwise traverse Inbox(BST) for insertion
    return Inbox -> add_message(Inbox, *add_message);
}

void user::read_messages()
{
    //Check if inbox is there
    if(!Inbox)
    {
        cout << "Inbox is empty!" << endl;
        return;
    }

    char search_name[MAX];
    cout << "Which person?: ";
    cin.get(search_name, MAX, '\n');
    cin.ignore(MAX, '\n');

    return Inbox -> read_messages(Inbox, search_name);
}

char * user::get_username()
{
    return name;
}

int user::forum_choice()
{

    int choice = 0;
    cout << "Would you like to post to a forum or read a thread? (1 = post 2 = read): ";
    cin >> choice;
    cin.ignore(MAX, '\n');
    return choice;
}

forum * user::create_post()
{
    forum * post_out = new forum;
    cin >> post_out;

    return post_out;
}

user::~user()
{
    if(name)
    {
        delete name;
        name = NULL;
    }
    if(Inbox)
    {
        Inbox -> destory(Inbox);
        Inbox = NULL;
    }
}

UserTable::UserTable()
{
    size = 7;
    table_of_users = new user * [size];
    for(int index = 0; index < size; ++index)
       table_of_users[index] = NULL;
    FishBowl = NULL;
}

void UserTable::create_user()
{
    cout << "Create A User"
         << "\n***********************\n";

    user new_user;
    cin >> new_user;
    char * key = new_user.get_passwd();
    int index = find_user(key);

    user * add_user = new user(new_user);

    //Add to table of users 
    add_user -> set_next(table_of_users[index]);
    table_of_users[index] = add_user;

}

void UserTable::login()
{
        user * login_user = NULL;
        int choice = 0;

        do
        {
            char buffer[MAX];
            char buffer2[MAX];
            system("clear");
            cout << "Please enter your name: ";
            cin.get(buffer2, MAX, '\n');
            cin.ignore(MAX, '\n');
            cout << "Please enter your password: ";
            cin.get(buffer, MAX, '\n');
            cin.ignore(MAX, '\n');
            int index = find_user(buffer);
            login_user = traverse(table_of_users[index], buffer, buffer2);


            //Succesful login
            if(login_user)
                choice = login_user -> user_choice();//Let user pick: (i) Inbox (ii) Forum
            else
                cout << "No user was found!" << endl;

            switch(choice)
            {
                case 1:
                {
                    //Send message
                    message * send_mess = login_user ->  create_message();
                    //Check for message to send to other user in the table
                    message_user(send_mess);
                    delete send_mess;
                    break;
                }
                case 2:
                    login_user -> read_messages();  
                    break;
                case 3:
                {
                    choice = login_user -> forum_choice();
                    //Read forum
                    if(choice == 1)
                        read_post();

                    //Post to forum
                    else
                    {
                        forum * new_post = login_user -> create_post();
                        add_post(*new_post);
                    }

                    break;
                }
            }
        }while(!again() && login_user);
}

void UserTable::message_user(user *& current, char * receiver, message * sent_message)
{
    //Recipient wasn't found
    if(!current)
        return;
    //Check if current is the intended recipient
    if(strcmp(current -> get_username(), receiver) == 0)
    {
        current -> receive(sent_message);
        return;
    }

    //Otherwise keep searching
    return message_user(current -> get_next(), receiver, sent_message);
}

void UserTable::message_user(message * send_message)
{
    //Traverse each index for the intended recipient
    for(int index = 0; index < size; ++index)
        message_user(table_of_users[index], send_message -> get_recipient(), send_message);

}

void UserTable::add_post(forum & add_post)
{

    if(!FishBowl)
    {
        FishBowl = new Thread(add_post);
        return;
    }
    return FishBowl -> add_post(FishBowl, add_post);

}

void UserTable::read_post()
{

    if(!FishBowl)
    {
        cout << "No thread/groups have been made!" << endl;
        return;
    }
    char buffer[MAX];
    cout << "What group?: ";
    cin.get(buffer, MAX, '\n');
    cin.ignore(MAX, '\n');
    //Traverse BST of thread to read


}

int UserTable::find_user(char * key)
{
    int length, value = 0;
    length = strlen(key);
    for(int index = 0; index < length; ++index)
        value += key[index];
    return value % size;

}

user * UserTable::traverse(user * current, char * passwd, char * name)
{
    if(!current)
        return NULL;

    if(current -> is_match(passwd, name))
            return current;

    return traverse(current -> get_next(), passwd, name);

}

UserTable::~UserTable()
{
    if(table_of_users)
    {
        for(int index = 0; index < size; ++index)
        {
            if(table_of_users[index])
                delete table_of_users[index];
        }
        delete [] table_of_users;
        table_of_users = NULL;
    }

    if(FishBowl)
    {
        FishBowl -> destory(FishBowl);
        FishBowl = NULL;
    }

}

