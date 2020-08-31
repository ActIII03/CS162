#include "dlist.h"

int list::remove_larger_than_first()
{
    if(!head)
        return 0;
    int first_data = head -> data;
    return remove_larger_than_first(head -> next, first_data);
}

int list::remove_larger_than_first(node *& head, int first_data)
{

    int count = 0;
    if(!head -> next)
    {
        if(head-> data > first_data)
        {
            node * temp = head;
            head = head -> previous;
            delete temp;;
            tail = head;
            tail -> next = NULL;
            ++count;
        }
        return count;
    }

    if(head -> data > first_data)
    {
        node * temp = head;;
        head = head -> next;
        head -> previous = temp -> previous;
        head -> previous -> next = head;
        delete temp;
        return count + 1 + remove_larger_than_first(head, first_data);
    }
    else
        return count + remove_larger_than_first(head -> next, first_data);

    return count;
}

int list::display_reverse()
{
    if(!head)
        return 0;
    cout << "List displayed reverse:\n";
    return display_reverse(tail);
}

int list::display_reverse(node * current)
{
    int count = 0;
    if(current == head)
    {
        cout << "Data: " << current -> data << endl;
        return count + 1;
    }
    cout << "Data: " << current -> data << endl;
    return count + 1 + display_reverse(current -> previous);
}

int list::duplicate(list & source)
{
    if(!source.head)
        return 0;

    //Copy first item and set previous
    head = new node;
    head -> data = source.head -> data;
    node * previous = head;
    node * current;
    current = head -> next;

    return duplicate(source.head -> next, current, previous);
}

int list::duplicate(node * source_curr, node *& dest, node *& dest_prev)
{
    int count = 0;

    if(!source_curr -> next)
    {
        dest = new node;
        dest -> data = source_curr -> data;
        dest -> previous = dest_prev;
        dest -> next = NULL;
        tail = dest;
        return count + 1;
    }

    dest = new node;
    dest -> data = source_curr -> data;
    dest -> previous = dest_prev;
    dest_prev -> next = dest;
    
    return count + 1 + duplicate(source_curr -> next, dest -> next, dest_prev -> next);
}

