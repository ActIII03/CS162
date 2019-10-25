//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 


struct q_node
{
    q_node();
    ~q_node();
    queue q_obj;
    q_node * next;

}

class queue
{

    public:

        queue();
        ~queue();
        int enqueue();
        int dequeue();
        int isempty();
        int isfull();
        int display();

    private:

        char * question_1;
        char * question_2;
        char * question_3;
        char * answer_1;
        char * answer_2;
        char * answer_3;

};


