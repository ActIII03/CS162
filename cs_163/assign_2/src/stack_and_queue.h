//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: This is the interface for my stack and queue classes which manages my Data Structures: (i) Stack(Flexible Array of Queue objects) (ii) Queue(CLL) 
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//Used in my CLL of questions and answers
struct q_node{

    q_node();
    ~q_node();
    char * question;
    char * answer;
    q_node * next;
};

//Queue function with q_node rear pointer that points to the CLL of questions and answers
class queue
{

    public:

        queue();
        ~queue();
        int enqueue(char q_1[], char a_1[], char q_2[], char a_2[], char q_3[], char a_3[]); //Enqueue is called within my push function
        int dequeue();  //Never implemented it
        int get_next_question(char * q, char * a); //Copies questio for string comparison
        void copy(char q_1[], char a_1[], char q_2[], char a_2[], char q_3[], char a_3[]); 
        int display_pub(int & question, char answer[]); //Test to display all

    private:

        void queue_dest(q_node * & rear);  //Recursive destructor helper function
        int display(q_node * rear, int & question, char answer[]); //Test to display all
        q_node * rear;  //Points to tail end of the queue
};

//Linear Linked node that holds the array of queue pointers
struct node {

    node();
    ~node();
    node * next;
    queue ** card_arr;  //Array of pointers to an array of queue objects *Flexible Arrays*
};

//Manages my queue objects accordingly
class stack
{
    public:

        stack();
        ~stack();
        int push(char q_1[], char q_2[], char q_3[], char a_1[], char a_2[], char a_3[]);   //Push then I enqueue within my push function
        queue * pop();  //Pop from the newest card obj add a return value of the obj's ptr in despite not "dequeue'n" like we are supposed. Just a deep copy of the queue obj pointing to the CLL of questions and answers

    private:

        node * head;
        int top_index;   //Keep index here to track and manage

};
