//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: ADT operations

#include "bst.h"
#include "college_house.h"

table::table()
{
    root = NULL;
}

table::~table()
{
   remove_all(root);
}

node::node()
{
    right = NULL;
    left = NULL;
}

void table::remove_all(node * & root)
{
    if(!root)
        return;
    remove_all(root -> left);
    remove_all(root -> right);
    delete root;
    root = NULL;
    return;
} 

//Wrapper function for insertion
int table::insert(CollegeHousing & to_add)
{

    if(!insert(root, to_add))
        return 0;
    return -1;
}

//Recursive insertion function
int table::insert(node * & root, CollegeHousing & to_add)
{
    //Root is null so insert here
    if(!root)
    {
        root = new node;
        root -> col_house.name = new char[strlen(to_add.name) + 1];
        strcpy(root -> col_house.name, to_add.name);
        root -> col_house.location = new char[strlen(to_add.location) + 1];
        strcpy(root -> col_house.location, to_add.location);
        root -> col_house.sq_footage = to_add.sq_footage;
        root -> col_house.num_of_bedrm = to_add.num_of_bedrm;
        root -> col_house.dist_from_psu = to_add.dist_from_psu;
        root -> left = NULL;
        root -> right = NULL;
        return 0;
    }

    //If greater than root, go right
    else if(strcmp(root -> col_house.name, to_add.name) > 0)
        insert(root -> right, to_add);

    //Otherwise go left
    else
        insert(root -> left, to_add);

    return 0;
    
}

int table::remove_location(char * location)
{
    if(!root)
        return -1;
    return remove_location(location, root);
}


int table::remove_location(char * location, node * & root)
{
    if(!root)
        return 0;
    
    //Preorder traversal
    if(!(strcmp(root -> col_house.location, location)))
        remove_node(root);

    //Traverse left
    remove_location(location, root -> left);
    //Traverse Right
    remove_location(location, root -> right);
    return 0;

}

//Wrapper function for search by name
int table::search(char * name, CollegeHousing & to_find)
{
    if(search(root, name, to_find))
    {
        cout << "Floorplan found!" << endl;
        return 0;
    }
    
    cout << "Not found!" << endl;
    return -1;

}

//recursive search by name
int table::search(node * root, char * name, CollegeHousing & found)
{
    if(!root)
        return 0;

    //Search alphabetically start from A-Z
    search(root -> left, name, found);
    
    //Check for name match
    if(!strcmp(root -> col_house.name, name))
    {
        strcpy(found.name, root -> col_house.name);
        strcpy(found.location, root -> col_house.location);
        found.sq_footage = root -> col_house.sq_footage;
        found.num_of_bedrm = root -> col_house.num_of_bedrm;
        found.dist_from_psu = root -> col_house.dist_from_psu;
        return 0;
    }
    search(root -> right, name, found);
    return 0;
}

bool table::search(char * name, node * & root)
{
    if(!root)
        return false;
    // Compare current node with name from user
    if(!(strcmp(root -> col_house.name, name)))
        return true;
    //Go left or right
    else if(strcmp(root -> col_house.name, name) > 0)
        search(name, root -> right);
    else
        search(name, root -> left);
    return false;
}


int table::remove(char * name)
{
    //Recursively search first and if found, delete
    if(search(name, root))
    {
        remove_node(root);
        return 0;
    }

    return 1;
}

int table::remove_node(node * & root)
{

    //Leaf
    if(!root -> right && !root -> left )
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

    //In-order succesor is the left node most of the right subtree
    else
    {
        node * current = root -> right;

        //Right is ios
        if(!current -> left)
        {
            strcpy(root -> col_house.name, current -> col_house.name);
            strcpy(root -> col_house.location, current -> col_house.location);
            root -> col_house.sq_footage = current -> col_house.sq_footage;
            root -> col_house.num_of_bedrm = current -> col_house.num_of_bedrm;
            root -> right = current -> right;
            delete current;
            current = NULL;
        }

        //Current has a left subtree
        //Traverse all the way left
        else
        {
            while(current -> left -> left)
                current = current -> left;

            strcpy(root -> col_house.name, current -> col_house.name);
            strcpy(root -> col_house.location, current -> col_house.location);
            root -> col_house.sq_footage = current -> col_house.sq_footage;
            root -> col_house.num_of_bedrm = current -> col_house.num_of_bedrm;
            node * temp = current -> left;
            current -> left = current -> left -> right;
            delete temp;
        }
    }
    return 0;

}

int table::display_sorted()
{
    if(!root)
        return -1;
    //Display sorted recursively
    display_sorted(root);

    return 0;
}

int table::display_sorted(node * root)
{
    if(!root)
        return 0;

    //Go down left-subtree  --> A - Z
    display_sorted(root -> right);

    cout << "\nName: " << root -> col_house.name << endl;
    return display_sorted(root -> left);
}

int table::display_location(char * location)
{
    if(!root)
        return -1;

    display_location(location, root);

    return 0;

}

int table::display_location(char * location, node * root)
{
    //Empty list or Traversal reached NULL
    if(!root)
        return 0;


    //Compare user's location with current root's location member
    if(!(strcmp(location, root -> col_house.location)))
    {
        cout << "\nName: " << root -> col_house.name
             << "\nLocation: " << root -> col_house.location 
             << "\nSquare Footage " << root -> col_house.sq_footage
             << "\nNumber of bedrooms: " << root -> col_house.num_of_bedrm
             << "\nDistance(miles) from PSU: " << root -> col_house.dist_from_psu << endl;
    }

    //A-Z search
    display_location(location, root -> left);
    return display_location(location, root -> right);
}

//Wrapper function get height 
int table::get_height()
{
    if(!root)
        return -1;

    return get_height(root);
}

int table::get_height(node * root)
{

     if(!root)
         return 0;

     int left = 0, right = 0;
     left += get_height(root -> left);
     right += get_height(root->right);

     return 1 + is_max(left, right);

}

int table::is_max(int num_one, int num_two)
{
    if( num_one > num_two )
        return num_one;
    else if( num_one < num_two )
        return num_two;
    else
        return num_one;
}

bool table::is_efficient()
{
    if(!root)
        return false;

    if(is_efficient(root) > 0)
        return true;
    else
        return false;

}

int table::is_efficient(node * root)
{
    if(!root)
     return 0;

    int left = 0, right = 0;
    left += is_efficient(root -> left);
    right += is_efficient(root->right);

    //If height differ by more than one 
    if(abs(left - right) > 1)
        return -1;
    //Otherwise
    else
        return 1 + is_max(left, right);
}

