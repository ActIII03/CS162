//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <cstdlib>

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
        int enqueue(question & add_question, answer & add_answer); 
        int dequeue();
        int isempty();
        int isfull();
        int display();
        int copy_to(question & copy_q, answer & copy_a, 1_node * & n_qa_node); //Add argument for ptr

    private:

        q_node * rear;


};


