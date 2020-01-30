#include <iostream>

using namespace std;


struct node
{
    int data;
    node * next;
};

int main()
{

    node * head = new node;


    head -> data = 99;

    cout <<  "(*head).data results in: " << (*head).data << endl;

    return 0;
}

