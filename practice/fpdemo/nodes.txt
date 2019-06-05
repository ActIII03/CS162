//list.h
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;


//The data structure is a linear linked list of integers
struct node
{
    int data;
    node * next;
};

//These functions are already written and used by main
void build(node * & head);      //supplied
void display_all(node * head);  //supplied
void destroy(node * &head);     //supplied


/* *****************YOUR TURN! ******************************** */
/* PLACE YOUR PROTOTYPE HERE */
int count_nodes(node * head);
int count_even(node * head);
void display_last_node(node * head);
void display_middle_node(node * head, int count);
void is_last_node_odd(node * head, int count);
void display_last_two(node * head, int count);
void display_every_other(node * head);

int count_nodes(node * head)
{
    if(!head)
        return 0;
    else
        return count_nodes(head -> next) + 1;
}

int count_even(node * head)
{
    if(!head)
        return 0;
    else
    {
        if((head -> data) % 2 == 0)
            return count_even(head -> next) + 1;
        else
            return count_even(head -> next);
    }
}

void display_last_node(node * head)
{
    if(!head)
        return;
    else
    {
       if(!head->next)
           cout << "Last node: " << head -> data << endl;
       return display_last_node(head -> next);
    }
}

void display_middle_node(node * head, int count)
{
    if(!head)
        return;
    else
    {
        count = count / 2;
        while( count != 0)
        {
            head = head -> next;
            --count;
        }
        cout << "Middle node: " << head -> data << endl;
    }
}

void is_last_node_odd(node * head, int count)
{
    if(!head)
        return;
    else
    {
        while( count - 1 != 0 )
        {
            head = head -> next;
            --count;
        }
        if(head -> data % 2 == 1)
            cout << "Last node is odd and is: " << head -> data << endl;
        else
            cout << "Last node isn't odd and is: " << head -> data << endl;
    }
}

void display_last_two(node * head, int count)
{
    if(!head)
        return;
    else
    {
        count = count - 2;
        while (count != 0)
        {
            head = head -> next;
            --count;
        }

        cout << "2nd to last node: " << head -> data << endl;
        cout << "Last node: " << head -> next -> data << endl;
    }
}

void display_every_other(node * head)
{
    if(!head)
        return;
    else
    {
        cout << "Data: " << head -> data << endl;

        if (head -> next  == NULL)
            return;
        else if(head -> next -> next != NULL)
            display_every_other(head -> next -> next);
    }
}
