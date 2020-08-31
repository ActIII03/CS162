#include "table.h"

int table::remove_largest()
{
    if(!root)
        return 0;
    else if(!root -> right)
        return root -> data;
    node * previous;
    node * current = root;
    return remove_largest(current, previous);
}

int table::remove_largest(node *& current, node *& previous)
{
    int largest_num = 0;
    if(!current -> right)
    {
        if(current -> left)
        {
            largest_num = current -> data;
            previous -> right = current -> left;
            delete current;
            current = NULL;
        }
        else
        {
            largest_num = current -> data;
            delete current;
            current = NULL;
            previous -> right = NULL;
        }
        return largest_num;
    }
    previous = current;
    return remove_largest(current -> right, previous);
}

int table::remove_smallest()
{
    int smallest_num = 0;
    if(!root)
        return smallest_num;
    else if(!root -> right)
    {
        node * temp = root -> left;
        smallest_num = root -> data;
        delete root;
        root = temp;
        return smallest_num;
    }
    node * previous = root;
    node * current = root -> left;
    return remove_smallest(current, previous);
}

int table::remove_smallest(node *& current, node *& previous)
{
    int smallest_num = 0;
    if(!current -> left)
    {
        if(current -> right)
        {
            smallest_num = current -> data;
            previous -> left = current -> right;
            delete current;
            current = NULL;
        }
        else if(!current -> right)
        {
            smallest_num = current -> data;
            delete current;
            current = NULL;
            previous -> left = NULL;
        }
        return smallest_num; 
    }
    previous = current;
    current = current -> left;
    return remove_smallest(current, previous);
}

int table::find_root_ios()
{
    if(!root)
        return 0;
    else if(!root -> right)
        return find_root_ios(root -> left);
    return find_root_ios(root -> right);
}

int table::find_root_ios(node * current)
{
    if(current -> left)
    {
        return traverse_left(current -> left);
    }
    return current -> data;
}

int table::traverse_left(node * current)
{
    if(!current -> left)
        return current -> data;
    return traverse_left(current -> left);
}

int table::copy_bst(table & src)
{
    if(!src.root)
        return 0;
    return copy_bst(src.root, this -> root);
}

int table::copy_bst(node * src, node *& dest)
{
    int sum = 0;
    if(!src)
    {
        dest = NULL;
        return sum;
    }
    //Pre-order traversal
    sum += src -> data;
    dest = new node;
    dest -> data = src -> data;
    sum += copy_bst(src -> left, dest -> left);
    sum += copy_bst(src -> right, dest -> right);
    return sum;
}

int table::is_max(int l_tree, int r_tree)
{
    return (l_tree > r_tree) ? l_tree : r_tree;
}

float table::get_height()
{
    if(!root) return 0;

    node * current = root;
    float sum1 = 0, sum2 = 0;
    int count1 = 0, count2 = 0;
    int l_tree_height = 1 + get_height(current -> left, sum1, count1);
    int r_tree_height = 1 + get_height(current -> right, sum2, count2);

    if(l_tree_height == r_tree_height)
    {
        cout << "Height of both root's sub-trees equal one another\n";
        return (sum1 + sum2) / (count1 + count2);
    }
    else if(l_tree_height > r_tree_height)
    {
        cout << "Root's left sub-tree is greater\n";
        return sum1 / count1;
    }
    cout << "Root's right sub-tree is greater\n";
    return sum2 / count2;
    
}

int table::get_height(node * current, float & sum, int & count)
{
    if(!current) return 0;
    ++count;
    sum += current -> data;
    
    return 1 + is_max(get_height(current -> left, sum, count), get_height(current -> right, sum, count));

}

