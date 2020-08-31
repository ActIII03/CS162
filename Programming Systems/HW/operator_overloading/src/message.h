//Name: Armant Touche
//Class: CS202
//Program: FishBowl 
#include <iostream>
#include <cctype>
#include <cstring> 
#include <ctime>
#include <typeinfo>
#include <cstddef>
#include <cstdlib>
#include <unistd.h>

using namespace std;

const int MAX = 400;

//The "glue" of the forum and message
class MessageApp
{
    public:
        MessageApp();
        ~MessageApp();
        //Display
        virtual void display()=0; 
};

//Child of MessageApp
class message: public MessageApp
{
    public:
        message();
        //Copy constructor
        message(message & to_copy);
        ~message();
        //Read in topic and return istream by ref.
        friend istream &operator>>(istream & in, message *& read_in);
        //Add username to message and return message by ref.
        message & operator+=(char * n_sender);
        //Print message
        friend ostream &operator<<(ostream & out, message *& read_out);
        //Get next
        message *& get_next();
        //Set next
        void set_next(message *& current);
        //Create Message
        message *& create_message();
        //Get sender's name
        char * get_sender();
        //Get recipient
        char * get_recipient();
        //Display
        void display(); 

    protected:
        message * next;
        char * receiver;
        char * sender;
        char * topic;
        char * message_body;
        
};

//Child of MessageApp
class forum: public MessageApp
{
    public:
        forum();
        forum(forum & copy);
        ~forum();
        //Read in topic 
        friend istream &operator>>(istream & in, forum *& read_in);
        //Print posts 
        friend ostream &operator<<(ostream & out, forum *& read_out);
        //Get next
        forum *& get_next();
        //Set next
        void set_next(forum *& current);
        //Display
        void display(); 
        //Get group name
        char * get_group();

    protected:
        forum * next;
        char * post;
        char * group;
};

//Each individual chat may or may not contain a list of messages
class Chat
{
    public:
        Chat();
        Chat(message & add_message);
        ~Chat();
        //Go right
        Chat *& go_right();
        //Go left
        Chat *& go_left();
        //Set right
        Chat *& set_right(Chat *& current);
        //Set left
        Chat *& set_left(Chat *& current);
        //Overload addition compound operator
        Chat & operator+=(message & add_name);
        //Add message
        void add_message(Chat *& current, message & add_message);
        //Read messages
        void read_messages(Chat * current, char * search_name);
        //BST destory helper
        void destory(Chat *& current);

    protected:
        //Beginning of LLL message
        message * head;
        Chat * right_root;
        Chat * left_root;
        char * sender;
};

//Each different Thread may have a post or not
class Thread
{
    public:
        Thread();
        Thread(forum & add_post);
        ~Thread();
        //Go right
        Thread *& go_right();
        //Go left
        Thread *& go_left();
        //Set right
        void set_right(Thread *& current);
        //Set left
        void set_left(Thread *& current);
        //Overload addition compound operator
        Thread & operator+=(forum & add_group);
        //Add post 
        void add_post(Thread *& current, forum & add_post);
        //BST destory helper
        void destory(Thread *& current);

    protected:
        //Beginning of LLL forum
        forum * head;
        Thread * right_root;
        Thread * left_root;
        char * group;
        void read_post(Thread * current, char * search_group);
};

//Helper functions
bool again();
int choice();
