#include "table.h"

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    bool flag = true;
    char response = 'Y';
    int num_input = 0, height = 0, count = 0;

    //Insert into BST
    /*
    while(flag)
    {
        cout << "Please input a non-negative integer: ";
        cin >> num_input;
        cin.ignore(100, '\n');
        insert(root, num_input);
        cout << "Want to keep inserting?(Y/N): ";
        cin >> response;
        cin.ignore(100, '\n');
        if(toupper(response) != 'Y')
            flag = false;
    }
    */
    
    //Removal from a BST
    /*
    cout << "Please enter any of the displayed numbers you wish to delete: ";
    cin >> num_input;
    cin.ignore(100, '\n');
    removal(root, num_input);
    */

    //Display sorted
    //display_sorted(root);

    //Get height
    height = get_height(root);
    cout << "Height of tree is: " << height << endl;

    /*
    //Insert into BST
    cout << "Please input a non-negative integer: ";
    cin >> num_input;
    cin.ignore(100, '\n');
    insert_a_item(root, num_input);
    */
    
    //Count even nodes
    count_even(root, count);
    cout << "Number of even nodes: " << count << endl;

    display(root);

    return 0;
}

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

    else if(add_num > root -> data)
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
    /*
    display_sorted(root -> left);
    cout << "Data: " << root -> data << endl;
    return display_sorted(root -> right);
    */

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

int insert_a_item(node * & root, int add_num)
{
    /*
    if(!root)
        return 0;
    if(root -> data > add
    */

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

