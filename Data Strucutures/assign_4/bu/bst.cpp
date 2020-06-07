//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "bst.h"

node::node()
{
    right = NULL;
    left = NULL;
}

table::table()
{
    root = NULL;
    MAX = 9;
}

table::~table()
{

    destory(root);
}

int table::insert(Venue & to_add)
{

    int result = insert(root, to_add);

    return result;
}

int table::search_meal(char * to_find, Venue & found)
{
    if(!root)
        return -99;

    int result = search_meal(root, to_find, found);

    return result;
}

int table::remove(char * to_remove)
{

    if(!root)
        return -99;
     
    return remove(root, to_remove);
}

int table::display(char * search, a_venue matches[], int choice)
{

    if(!root)
        return -99;
    
    int count = 0, MAX = 0;

    // If user wants to display matching meals only
    if(choice == 1)
        count += display_matched_meals(root, search);

    // If user wants too display meal is sorted order
    else if(choice == 2)
        count += display_sorted(root);
    else if(choice == 3)
        count += retrieve_meal(root, search, matches, MAX);

    MAX = 10;

    return count;
}

int table::get_height()
{
    if(!root)
        return 0;

    return get_height(root);
}

int table::is_efficient()
{
    if(!root)
        return -99;

    int subtree_height_diff = get_height(root -> left) - get_height(root -> right);

    if(subtree_height_diff > 1 || subtree_height_diff < -1)
        return -99;

    return 0;
}

int table::is_max(int left_height, int right_height)
{
    if(left_height > right_height)
        return left_height;
    return right_height;
}

int table::insert(node * & root, Venue & to_add)
{
    int result = 0;

    //Empty list or traversed past a leaf
    if(!root)
    {
        root = new node;
        if(!root -> venue_entry.copy_venue(to_add))
        {
            result = -1;
            delete root;
            root = NULL;
            return result;
        }
        return result;
    }

    //Prevent duplicate entries
    if(root -> venue_entry.compare(to_add.meal) == 0 && strcmp(root -> venue_entry.name, to_add.name) == 0)
    {
        result = -1;
        return result;
    }

    //Go left if current node is alphabetically greater than the incoming entry
    else if(root -> venue_entry.compare(to_add.meal) > 0)
       result = insert(root -> left, to_add);

    // Otherwise, go right
    else
        result = insert(root -> right, to_add);

    return result;
}

int table::search_meal(node * root, char * search, Venue & found)
{
    int result = 0;

    if(!root)
        return result + 1;
    
    if(root -> venue_entry.compare(search) == 0)
    {
        found.copy_venue(root -> venue_entry);
        return result;
    }
    else if(root -> venue_entry.compare(search) > 0)
        result += search_meal(root -> left, search, found);
    else
        result += search_meal(root -> right, search, found);

    return result;
}

int table::remove(node * & root, char * to_remove)
{

    int result = 0;

    //Traversed to End of Subtree
    if(!root)
        return result;

    //Check for match and if a match check for cases for removal
    if(root -> venue_entry.compare(to_remove) == 0)
    {

        //Match is a leaf
        if(!root -> right && !root -> left)
        {
            delete root;
            root = NULL;
            return result + 1;
        }
        //Match has one child
        else if(root -> right || root -> left)
        {
            node * temp = root;
            if(!root -> left)
            {
                root = root -> right;
                delete temp;
            }
            else if(!root -> right)
            {
                root = root -> left;
                delete temp;
            }
            //Match has two children
            else 
            {
                node * current = root;
                node * previous;
                while(current -> left)
                {
                    previous = current;
                    current = current -> left;
                }
                previous -> left = current -> right;
                root -> venue_entry.copy_venue(current -> venue_entry);
                delete current;
            }
            return result + 1;
        }
    }

    // Pre-order traversal
    if(root -> venue_entry.compare(to_remove) > 0)
        result = remove(root -> left, to_remove);
    else
        result = remove(root -> right, to_remove);

    return result;
}

int table::retrieve_meal(node * root, char * search, a_venue matches[], int & MAX)
{
    if(!root && MAX < 10)
        return 0;

    int count = 0;

    if(root -> venue_entry.compare(search) == 0)
    {
        ++count;
        strcpy(matches[MAX].meal, root -> venue_entry.meal);
        strcpy(matches[MAX].name, root -> venue_entry.name);
        matches[MAX].price = root -> venue_entry.price;
        matches[MAX].rating = root -> venue_entry.rating;
        strcpy(matches[MAX].review, root -> venue_entry.review);
        strcpy(matches[MAX].category, root -> venue_entry.category);
        ++MAX;
    }

    if(strcmp(root -> venue_entry.meal, search)  > 0)
        count += retrieve_meal(root -> left, search, matches, MAX);
    else
        count += retrieve_meal(root -> right, search, matches, MAX);

    return count;
}


int table::display_matched_meals(node * root, char * match)
{
    if(!root)
        return 0;

    int count = 0;

    if(root -> venue_entry.compare(match) == 0)
    {
        ++count;
        root -> venue_entry.display();
    }
    
    // Pre-order traversal
    if(root -> venue_entry.compare(match) > 0)
        count += display_matched_meals(root -> left, match);
    else
        count += display_matched_meals(root -> right, match);
    return count;

}

int table::display_sorted(node * root)
{

    int count = 0;

    if(!root)
        return count;
    
    // In-order traversal
    count += display_sorted(root -> left);
    root -> venue_entry.display();
    ++count;
    count += display_sorted(root -> right);

    return count;
}

int table::get_height(node * root)
{
    if(!root)
        return 0;
    return 1 + is_max(get_height(root -> left), get_height(root -> right));

}

void table::destory(node * & root)
{

    if(!root)
        return;

    destory(root -> left);
    destory(root -> right);
    delete root;
    root = NULL;

    return;
}
