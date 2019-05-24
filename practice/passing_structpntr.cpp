#include <iostream>

using namespace std;

struct number
{
    int data;
    int counter;
};

struct node
{
    number new_n;
    node * next;
};

class list
{
    public:
        list();
        ~list();
        void add(int);
    private:
        node * head;
};

int main()
{
    list l;
    int data = 5;
    l.add(data);

    return 0;
}

list::list()
{
    head = NULL;
}

void list::add(int number)
{
    if(head == NULL)
    {
        head = new node;
        head -> new_n.data = number;
        head -> next = NULL;
    }
}

list::~list()
{
    //Checking head 
    if(head == NULL)
    {
        cout << "List is empty!" << endl;
    }

}
