#include "clist.h"

bool list::remove_rear_dupl()
{
    if(!rear)
        return false;
    node * previous = rear;
    node * current = rear -> next;
    return remove_rear_dupl(current, previous, rear, rear->data);
}

bool list::remove_rear_dupl(node *& current, node *& previous, node * rear, int rear_data)
{
    bool flag = false;

    if(current -> next == rear)
    {
        if(current -> data == rear_data)
        {
            previous -> next = current -> next;
            delete current;
            current = previous -> next;
            flag = true;
        }
        return flag;
    }
    if(current -> data == rear_data)
    {
        previous -> next = current -> next;
        delete current;
        current = previous -> next;
        flag = true;
        flag = remove_rear_dupl(current, previous, rear, rear_data);
    }
    else
        flag = remove_rear_dupl(current -> next, previous -> next, rear, rear_data);
    return flag;
}

//int list::add_before_even()
//{
//    if(!rear)
//        return 0;
//    node * previous = rear;
//    node * current = rear -> next;
//    return add_before_even(current, previous, rear);
//}
//
//int list::add_before_even(node *& current, node *& previous, node *& rear)
//{
//    int count = 0 ;
//
//    if(current == rear)
//    {
//        if(current -> data % 2 == 0)
//        {
//            node * new_node = new node;
//            new_node -> data = 99;
//            new_node -> next = current;
//            previous -> next = new_node;
//            previous = new_node;
//            ++count;
//        }
//        return count;
//    }
//    
//    //Tail recursion
//    if(current -> data % 2 == 0)
//    {
//        node * new_node = new node;
//        new_node -> data = 99;
//        new_node -> next = current;
//        previous -> next = new_node;
//        previous = new_node;
//        ++count;
//    }
//
//    previous = previous -> next;
//    current = current -> next;
//
//    return count + add_before_even(current, previous, rear);
//}

int list::copy_even(list & source)
{
    if(!source.rear)
        return 0;
    int count = copy_even(source.rear, source.rear, rear);
    cout << "Rear: " << rear << endl; 
    return count;
}

int list::copy_even(node * source_curr, node * source_rear, node *& dest)
{
    int count = 0;

    if(source_curr -> next == source_rear)
    {
        if(source_curr -> data % 2 == 0)
        {
            dest = new node;
            dest -> data = source_curr -> data;
            dest -> next = rear;
            cout << "Date copied: " << dest -> data << endl;
            cout << "Rear: " << rear << " Dest: " << dest -> next << endl; 
            ++count;
        }
        else 
        {
            dest = rear;
            cout << "Rear: " << rear << " Dest: " << dest << endl; 
        }
        return count;
    }
    if(source_curr -> data % 2 == 0)
    {
        dest = new node;
        dest -> data = source_curr -> data;
        cout << "Date copied: " << dest -> data << endl;
        return count + 1 + copy_even(source_curr -> next, source_rear, dest -> next);
    }
    else
        return count + copy_even(source_curr -> next, source_rear, dest);
    return count;
}

int list::delete_before_even()
{
    if(!rear)
        return 0;
    return delete_before_even(rear->next,rear, rear);
}

int list::delete_before_even(node *& current, node *& previous, node * &rear)
{
    int count = 0;

    if(current == rear)
    {
        if(current -> data % 2 == 0)
        {
            node * temp = current;
            rear = previous;
            previous -> next = current -> next;
            delete temp;
            ++count;
        }
        return count;
    }

    if(current -> data % 2 == 0)
    {
        node * temp = current;
        previous -> next = current -> next;
        delete temp;
        current = previous -> next;
        return count + 1 + delete_before_even(current, previous, rear);
    }
    else
        return count + delete_before_even(current -> next, previous -> next, rear);
    return count;
}

int list::add_before_even()
{
    if(!rear)
        return 0;
    node * previous = rear;
    node * current = rear -> next;
    return add_before_even(current, previous, rear);

}


int list::add_before_even(node *& current, node *& previous, node *& rear)
{
    int count = 0;
    //Base case: reached node before rear
    if(current == rear)
    {
        if(current -> data % 2 == 0)
        {
            node * new_node = new node;
            new_node -> data = 99;
            new_node -> next = current;
            previous -> next = new_node;
            ++count;
        }
        return count;

    }
    
    if(current -> data % 2 == 0)
    {
        node * new_node = new node;
        new_node -> data = 99;
        new_node -> next = current;
        previous -> next = new_node;
        previous = current;
        current = current -> next;
        ++count;
    }
    else
    {
        previous = previous -> next;
        current = current -> next;
    }

    return count + add_before_even(current, previous, rear);
}

