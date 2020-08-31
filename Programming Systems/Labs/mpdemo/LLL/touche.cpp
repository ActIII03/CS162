#include "list.h"

void list::hello()
{
    cout << "Hello" << endl;
}

int list::display_unique()
{

    if(!head)
        return 0;
    return display_unique(head, head);
}

int list::display_unique(node * head, node * first_item)
{

    int count = 0;

    if(!head)
        return count;
    
    if( is_unique(first_item, first_item, head) )
    {
        cout << "Unique item: " << (head -> data) << endl;
        ++count;
    }

    return count + display_unique(head -> next, first_item);

}

bool list::is_unique(node * head, node * first_item, node * searched_item)
{

    if(!head)
        return true;

    if( head -> data == searched_item -> data && head != searched_item)
        return false;

    return is_unique(head -> next, first_item, searched_item);
}

// Come back later
int list::average_unique()
{
    if(!head)
        return 0;

    int sum = 0;
    int count = average_unique(head, head, sum);

    return sum / count;

}

int list::average_unique(node * head, node * first_item, int & sum)
{
    int count = 0;

    if(!head)
        return count;

    if( is_unique(head, first_item, head) )
    {
        sum += head -> data;
        ++count;
    }
    
    return count + average_unique(head -> next, first_item, sum);

}

int list::remove_duplicate()
{
    if(!head)
        return 0;
    return remove_duplicate(head, head);
}

int list::remove_duplicate(node * & head, node * first_item)
{
    int count = 0;

    if(!head)
        return count;

    //Last item isn't distinct
    if(!head -> next && !is_unique(head, first_item, head))
    {
        delete head;
        head = NULL;
        ++count;
    }
    //First item isn't distinct
    else if( head == first_item && !is_unique(head, first_item, head))
    {
        node * temp = head -> next;
        delete head;
        first_item = head = temp;
        ++count;
    }
    else if(!is_unique(head, first_item, head))
    {
        node * temp = head -> next;
        delete head;
        head = temp;
        ++count;
    }

    return count + remove_duplicate(head -> next, first_item);
}

