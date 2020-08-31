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
