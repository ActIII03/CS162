#include "table.h"

int main()
{
    node * root = NULL;
    node * dest = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */

    cout << "Number of nodes: " << count(root) << endl;
    cout << "Average of even data members: " << average_even(root) << endl;
    cout << "Largest integer: " << display_lrg(root) << endl;
    cout << "Root's ios: " << check_right(root) << endl;

    cout << "Number of nodes copied: " << copy_BST(root, dest) << endl;
    cout << "Copied BST:" << endl;
    //inorder_traversal(dest);

    return 0;
}

int inorder_traversal(node * root)
{
    if(!root)
        return 0;

    inorder_traversal(root -> left);
    cout << "\nNumber: " << root -> data << endl;
    inorder_traversal(root -> right);

    return 0;
}

int count(node * root)
{
    if(!root)
        return 0;
    int num = 1;
    num += count(root -> left);
    num += count(root -> right);
    return num;
}

int average_even(node * root)
{
    if(!root)
        return 0;
    int average = ( sum_even(root) / count(root) );
    return average;
}

int sum_even(node * root)
{
    if(!root)
        return 0;
    int sum = 0;
    if(root -> data % 2 == 0)
        sum += root -> data;
    sum += sum_even(root -> left);
    sum += sum_even(root -> right);
    return sum;
}

int display_lrg(node * root)
{
    if(!root)
        return 0;
    if(!root -> right)
        return root -> data;
    return display_lrg(root -> right);
}

int display_ios(node * root)
{

    if(!root)
        return 0;
    
    if(root -> left)
        return traverse_ltree(root -> left);

    else if(!root -> left && root -> right)
    {
        if(root -> right -> data > root -> data)
            return root -> data;
        else
            return display_ios(root -> right);
    }

}

int traverse_ltree(node * root)
{
    if(!root -> left)
        return root -> data;
    return traverse_ltree(root -> left);
}

int check_right(node * root)
{
    if(!root)
        return 0;

    if(!root -> right)
        return -99;
    return display_ios(root -> right);
}

int copy_BST(node * source, node * & dest)
{
    //Empty list or traversed past a leaf
    if(!source)
        return 0;

    int num = 1;
    dest = new node;
    dest -> data = source -> data;
    dest -> right = dest -> left = NULL;

    num += copy_BST(source -> left, dest -> left);
    num += copy_BST(source -> right, dest -> right);

    return num;
}


/*
int insert(node * & root, int add_num)
{
    if(!root)
    {
        root = new node;
        root -> data = add_num;
        root -> left = NULL;
        root -> right = NULL;
        return 0;
    }

    else if(add_num >= root -> data)
        insert(root -> right, add_num);
    else
        insert(root -> left, add_num);
    return 0;
}

int removal(node * & root, int del_num)
{
    int ios = 0;
    if(!root)
       return -1;
    if(root -> data == del_num)
    {
       ios = removal_ios_rec(root -> right);   //Implement iterative function here
       root -> data = ios;
        return 0;
    }

    if(root -> data <= del_num)
       return removal(root -> right, del_num);
    return removal(root -> left, del_num); 
}


int removal_iter(node * & root)
{
    //It's a Leaf
    if(!root -> left && !root -> right)
    {
        delete root;
        root = NULL;
    }

    //Left child only
    else if(!root -> right)
    {
        node * current = root;
        root = current -> left;
        delete current;
    }

    //Right child only
    else if(!root -> left)
    {
        node * current = root;
        root = current -> right;
        delete current;
    }

    //Right & Left child
    //In-order succesor is the left node most of the right subtree
    else
    {
        node * current = root -> right;

        //Right is ios
        if(!current -> left)
        {
            root -> data = current -> data;
            root -> right = current -> right;
            delete current;
        }

        //Current has a left subtree
        //Traverse all the way left
        else
        {
            while(current -> left -> left)
                current = current -> left;

            root -> data = current -> left -> data;
            node * temp = current -> left;
            current -> left = current -> left -> right;
            delete temp;
        }
    }
    return 0;
}

int removal_ios_rec(node * & root)
{
    int ios = 0;

    if(!root -> left)
    {
        node * temp = root;
        root = root -> right;
        ios = temp -> data;
        delete temp;
        return ios;
    }

    return removal_ios_rec(root -> left);
}

// Least to greatest
int display_sorted(node * root)
{

    if(!root)
       return 0;
    
    //Least to greatest
    display_sorted(root -> left);
    cout << "Data: " << root -> data << endl;
    return display_sorted(root -> right);

    //Greatest to least
    display_sorted(root -> right);
    cout << "Data: " << root -> data << endl;
    return display_sorted(root -> left);
}

int get_height(node * root)
{
    if(!root)
        return -1;
    return get_height_rec(root);
}

int get_height_rec(node * root)
{
    if(!root)
        return 0;
    int left = 0, right = 0;

    left = get_height_rec(root -> left);
    right += get_height_rec(root -> right);
    return 1 + is_max(left, right);
}

int is_max(int left, int right)
{
    if(left == right)
        return left;
    else if(left < right)
        return right;
    else
        return left;
}

void count_even(node * root, int & count)
{

    if(!root)
        return;
    if(root -> data % 2 == 0)
        ++count;
    count_even(root -> right, count);
    count_even(root -> left, count);
}

int count_node_wr(node * root)
{
    int counter = 0;
    count_node(root, counter);
    return counter;
}

void count_node(node * root, int & counter)
{
    if(!root)
        return;
    ++counter;
    count_node(root -> right, counter);
    count_node(root -> left, counter);
    return;

}

int find_lrg(node * root)
{
    if(!root -> right)
        return root -> data;
    find_lrg(root -> right);
}
int inc_but_largest(node * & root)
{
    if(!root)
        return -1;
    int largest = find_lrg(root);
    cout << "Largest data: " << largest << endl;
    int count = 0;
    inc_but_largest_rec(root, count, largest);
    return count;
}

int inc_but_largest_rec(node * & root, int & count, int largest)
{
    if(!root)
        return 0;
    inc_but_largest_rec(root -> left, count, largest);
    inc_but_largest_rec(root -> right, count, largest);
    if(root -> data != largest)
    {
        ++root -> data;
        ++count;
    }
}

int display_second_lrg(node * root)
{
    if(!root -> right)
    {
        node * current = root;
        while(current -> left)
            current = current -> left;
        cout << "Second largest: " << current -> data;
        return 0;
    }

    display_ios(root -> right);
}

//Get help on
int display_ios(node * root)
{
    int ios = 0;

    if(!root)
        return -1;

    if(!root -> right)
        ios = root -> left -> data;
    else
        find_leftmost(root -> right, ios);
    cout << "IOS: " << ios << endl;

    return 0;
}

void find_leftmost(node * root, int & ios)
{
    if(!root)
        return;

    //Travel to IOS
    if(!root -> left)
    {
        ios = root -> data;
        return;
    }

    find_leftmost(root -> left, ios);
}

void find_next(node * root, int & ios)
{

    if(!root)
        return;

    if( (root -> left) && (root -> data < root -> right -> data) )
        find_leftmost(root -> left, ios);

    find_next(root -> right, ios);

}

int delete_bst(node * & root)
{
    if(!root)
        return 0;

    delete_bst(root -> left);
    delete_bst(root -> right);
    delete root;
    root = NULL;
    return 0;
}

//Get help
int copy_even(node * source, node * & dest)
{
    if(!source)
        return 0;
    
    if(source -> data % 2 == 0)
    {
       dest = new node;
       dest -> data = source -> data;
       dest -> right = NULL;
       dest -> left = NULL;
    }

    copy_even(source -> right, dest);
    copy_even(source -> left, dest);
    
    return 0;
}

int swap_five(node * & root)
{
    if(!root)
        return 0;

    if(root -> data % 2 == 0)
        root -> data = 99;

    swap_five(root -> left);
    swap_five(root -> right);
}

int copy_to_arr(node * root)
{

    int count = 0, index = 0;
    count_node(root, count);

    int b_arr[count];

    copy_to_arr(root, b_arr, index);
    count = 0;

    for(;count < index; ++count)
        cout << "\n(" << (count + 1) << ") " << b_arr[count] << endl;

    return 0;
}

int copy_to_arr(node * root, int b_arr[], int & index)
{
    if(!root)
        return 0;

    b_arr[index] = root -> data;
    ++index;

    copy_to_arr(root -> left, b_arr, index);
    copy_to_arr(root -> right, b_arr, index);
}
*/

