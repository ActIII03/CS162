//Name: Armant Touche
//Class: CS202
//Program: FishBowl 
#include "message.h"

//User of the Chat system
class user
{

    public:

        user();
        user(char * copy_name, char * copy_passwd);
        user(user & to_copy);
        ~user();
        //Read in user info
        friend istream &operator>>(istream & in, user & read_in);
        //Display user
        friend ostream &operator<<(ostream & out, user & read_out);
        //Get passwd
        char * get_passwd();
        //Get next
        user *& get_next();
        //Set next
        void set_next(user *& current);
        //Compare user
        bool is_match(char * compare_passwd, char * compare_name);
        //Logged in 
        int user_choice();
        //Inbox method for: (i) Sending (ii) reading
        message * create_message();
        //Recieve messaege
        void receive(message * add_message);
        //Read messages
        void read_messages(); 
        //Get username
        char * get_username();
        //Pick thread action
        int forum_choice();
        //Post to forum
        forum * create_post();
        
    private:
        user * next;
        char * name;
        char * passwd;
        //Inbox (Root)
        Chat * Inbox;
};

//User system that has a Thread for users to post to like a Slack
class UserTable
{
    public:
        UserTable();
        ~UserTable();
        //Add a user
        void create_user();
        //Login
        void login();
        //Find user (hash password)
        int find_user(char * key);
        //Message user
        void message_user(message * send_message);
        //Add post
        void add_post(forum & add_post);
        //Read posts
        void read_post();

    protected:
        //size of table
        int size;
        //table of users
        user ** table_of_users;
        //Traverse at current index
        user * traverse(user * current, char * passwd, char * name);
        void message_user(user *& current, char * receiver, message * sent_message);
        //Thread
        Thread * FishBowl;

};

