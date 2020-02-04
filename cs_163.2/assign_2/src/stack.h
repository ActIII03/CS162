//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

struct node
{
    routes * route_entries;
    node * next;
};

class stack
{
    public:

        int push(const routes & new_route);
        int pop(void);
        int peek(routes & found_route) const;

    private:

        node * head;
        int top_index;
};
