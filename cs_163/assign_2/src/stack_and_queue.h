//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct q_node{

    q_node();
    ~q_node();
    char * question;
    char * answer;
    q_node * next;
};

class queue
{

    public:

        queue();
        ~queue();
        int enqueue(char q_1[], char a_1[], char q_2[], char a_2[], char q_3[], char a_3[]); 
        int dequeue();
        //int peek(char q_arr[], char a_arr[]);
        int get_next_question(char * q, char * a); //return 
        q_node * get_rear();
        int set_rear(q_node * rear);
        //int isempty();
        //int isfull();
        int display_pub(); //Test to display all

    private:

        int display(q_node * rear); //Test to display all
        q_node * rear;
};

struct node {

    node();
    ~node();
    node * next;
    queue * card_arr;  //Pointer to an array of queue objects *Flexible Arrays*
};

class stack
{
    public:

        stack();
        ~stack();
        int push(char q_1[], char q_2[], char q_3[], char a_1[], char a_2[], char a_3[]);   //Update argument with struct q & a to push them
        queue * pop();  //Pop from the newest card obj add a return value of the obj's ptr
        node * peek(); // 
        int display();
        bool is_empty();
        int is_full();

    private:

        node * head;
        int top_index;   //Keep index here to track and manage

};
