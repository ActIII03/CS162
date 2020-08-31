//Name: Armant Touche
//Class: CS202
//Program: FishBowl 
#include "message.h"

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

int choice()
{
    int choice = 0;
    cout << "Would you like to create a user or login?( 1 = create  2 = login): ";
    cin >> choice;
    cin.ignore(MAX, '\n');
    return choice;
}

MessageApp::MessageApp()
{

}

MessageApp::~MessageApp()
{

}

message::message(): MessageApp()
{
    next = NULL;
    sender = NULL;
    receiver = NULL;
    topic = NULL;
}

message::message(message & to_copy)
{
    receiver = new char[strlen(to_copy.receiver) + 1];
    strcpy(receiver, to_copy.receiver);
    sender = new char[strlen(to_copy.sender) + 1];
    strcpy(sender, to_copy.sender);
    topic = new char[strlen(to_copy.topic) + 1];
    strcpy(topic, to_copy.topic);
    message_body = new char[strlen(to_copy.message_body) + 1];
    strcpy(message_body, to_copy.message_body);
}

message::~message()
{
    if(topic)
    {
        delete topic;
        topic = NULL;
    }

}

istream &operator>>(istream & in, message *& read_in)
{
    char buffer[MAX];
    int length = 0;

    cout << "Receiver: ";
    in >> buffer;
    in.ignore(MAX, '\n');
    length = (strlen(buffer) + 1);
    read_in -> receiver = new char[length];
    strcpy(read_in -> receiver, buffer);
    cout << "Topic: ";
    in >> buffer;
    in.ignore(MAX, '\n');
    length = (strlen(buffer) + 1);
    read_in -> topic = new char[length];
    strcpy(read_in -> topic, buffer);
    cout << "Body: ";
    in >> buffer;
    in.ignore(MAX, '\n');
    length = (strlen(buffer) + 1);
    read_in -> message_body = new char[length];
    strcpy(read_in -> message_body, buffer);

    return in;
}

message & message::operator+=(char * n_sender)
{
    this -> sender = new char[strlen(n_sender) + 1];
    strcpy(this -> sender, n_sender);
    return *this;
}

ostream &operator<<(ostream & out, message *& read_out)
{
    system("clear"); //Only did Linux
    out << "Topic: " << read_out -> topic 
        << "\nBody:\n" << read_out -> message_body << endl;
    return out;
}

message *& message::get_next()
{
    return next;
}

void message::set_next(message *& current)
{
    next = current;
}

char * message::get_sender()
{
    return this -> sender;
}

char * message::get_recipient()
{
    return this -> receiver;
}

void message::display()
{

}

forum::forum()
{
    next = NULL;
    post = NULL;
    group = NULL;
}

forum::forum(forum & copy)
{
    if(post)
        delete post;
    post = new char[strlen(copy.post) + 1];
    strcpy(post, copy.post);
    if(group)
        delete group;
    group = new char[strlen(copy.group) + 1];
    strcpy(group, copy.group);
    next = NULL;
}

forum::~forum()
{
    if(post)
    {
        delete post;
        post = NULL;
    }
    if(group)
    {
        delete group;
        group = NULL;
    }


}

istream &operator>>(istream & in, forum *& read_in)
{
    char buffer[MAX];
    int length = 0;

    //Check for contents?
    cout << "Group: ";
    in >> buffer;
    in.ignore(MAX, '\n');
    length = (strlen(buffer) + 1);
    read_in -> group = new char[length];
    strcpy(read_in -> group, buffer);
    cout << "Post: ";
    in >> buffer;
    in.ignore(MAX, '\n');
    length = (strlen(buffer) + 1);
    read_in -> post = new char[length];
    strcpy(read_in -> post, buffer);
    
    return in;
}

ostream &operator<<(ostream & out, forum *& read_out)
{
    out << "Post: " << read_out -> post;
    return out;
}

forum *& forum::get_next()
{
    return next;
}

void forum::set_next(forum *& current)
{
    next = current;
}

void forum::display()
{

}

char * forum::get_group()
{
    return group;
}

Chat::Chat()
{
    head = NULL;
    right_root = NULL;
    left_root = NULL;
    sender = NULL;
}

Chat::Chat(message & add_message)
{
    head = new message(add_message);
    sender = new char[strlen(add_message.get_sender()) + 1];
    strcpy(sender, add_message.get_sender());
}

Chat *& Chat::go_right()
{
    return right_root;
}

Chat *& Chat::go_left()
{
    return left_root;
}

Chat *& Chat::set_left(Chat *& current)
{
    current = left_root;
    return current;
}

Chat *& Chat::set_right(Chat *& current)
{
    current = right_root;
    return current;
}

void Chat::add_message(Chat *& current, message & add_message)
{
    //Add new node to BST
    if(!current)
    {
        current = new Chat(add_message);
        *current += add_message;
        return;
    }
    //Go left if less than current
    if(strcmp(current -> head -> get_sender(), add_message.get_sender()) > 0)
        this -> add_message(current -> go_left(), add_message);
    //Add to beginning of list if equal to current
    else if(strcmp(current -> head -> get_sender(), add_message.get_sender()) == 0)
    {
        message * insert_message = new message(add_message);
        insert_message -> set_next(this -> head);
        this -> head = insert_message;
    }
    ////Otherwise, go right
    else 
        this -> add_message(current -> go_right(), add_message);
    return;
}

void Chat::read_messages(Chat * current, char * search_name)
{
    if(!current)
        return;

    //Go left 
    if(strcmp(current -> head -> get_sender(), search_name) > 0)
        this -> read_messages(current -> go_left(), search_name);
    //Check if current node is the intended one to read from
    else if(strcmp(current -> head -> get_sender(), search_name) == 0)
        current -> head -> display();
    //Otherwise, go right
    else
        this -> read_messages(current -> go_right(), search_name);
    return ;
}

Chat & Chat::operator+=(message & add_name)
{
    this -> sender = new char[strlen(add_name.get_sender())];
    strcpy(this -> sender, add_name.get_sender());
    return *this;
}

Chat::~Chat()
{

}

void Chat::destory(Chat *& current)
{
    if(!current)
        return;

    //Head recursion for destory all
    destory(current -> go_left());
    destory(current -> go_right());
    delete current;
    current = NULL;
    return;
}

Thread::Thread()
{
    head = NULL;
    right_root = NULL;
    left_root = NULL;
    group = NULL;
}

Thread::Thread(forum & add_post)
{
    head = new forum(add_post);
    group = new char[strlen(add_post.get_group()) + 1];
    strcpy(group, add_post.get_group());
}

Thread *& Thread::go_right()
{
    return right_root;
}

Thread *& Thread::go_left()
{
    return left_root;
}

void Thread::set_right(Thread *& current)
{
    right_root = current;
}

void Thread::set_left(Thread *& current)
{
    left_root = current;
}

Thread & Thread::operator+=(forum & add_group)
{
    this -> group = new char[strlen(add_group.get_group())];
    strcpy(this -> group, add_group.get_group());
    return *this;
}

void Thread::add_post(Thread *& current, forum & add_post)
{
    if(!current)
    {
        current = new Thread(add_post);
        *current += add_post;
        return;
    }
    //Go left if less than current
    if(strcmp(current -> head -> get_group(), add_post.get_group()) > 0)
        this -> add_post(current -> go_left(), add_post);
    //Add to beginning of list if equal to current
    else if(strcmp(current -> head -> get_group(), add_post.get_group()) == 0)
    {
        forum * insert_forum = new forum(add_post);
        insert_forum -> set_next(this -> head);
        this -> head = insert_forum;
    }
    ////Otherwise, go right
    else 
        this -> add_post(current -> go_right(), add_post);
    return;
}

void Thread::read_post(Thread * current, char * search_group)
{
    //Thread wasn't found
    if(!current)
    {
        cout << "Group wasn't found!" << endl;
        return;
    }
    //Is current the intended thread?

    //If not, then go left if less than
    //else if(strcmp

    //Otherwise, go right
    return read_post(current -> go_right(), search_group);

}

Thread::~Thread()
{
}

void Thread::destory(Thread *& current)
{
    if(!current)
        return;
    //Head recursion for destory all
    destory(current -> go_left());
    destory(current -> go_right());
    delete current;
    current = NULL;
    return;
}

