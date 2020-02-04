//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:


struct prim_route_qnode
{


};

struct alt_route_qnode
{


};


class queue
{
    public:

        int enqueue(); //<-- Add argument
        int dequeue(); //<-- Add argument
        int peek(); //<-- Add argument
        int isEmpty();

    private:

            prim_route_qnode * rear;
            alt_route_qnode * rear;
};

