//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <cstdlib>
#include <cstring>

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
        int isempty();
        int isfull();
        int display();

    private:

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
        int push(char q_1[], char q_2[], char q_3[], char a_1[], char a_2[], char a_3[]);   //UPdate argument with struct q & a to push them
        int pop(int card);
        int peek();
        int is_empty();
        int is_full();

    private:

        node * head;
        int top_index;   //Keep index here to track and manage

};
