//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

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

//Wrapper function for search by name
int table::search(char * name, CollegeHousing & to_find)
{
    if(!search(root, name, to_find))
    {
        cout << "Floorplan found!" << endl;
        return 0;
    }
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

int table::remove(char * name)
{
    if(!root)
        return -1;
    
    //Recursively search and remove floorplan
    if(!remove(name, root))
        return 0;
    return 1;
}

int table::remove(char * name, node * & root)
{
    if(!root)
        return 1;

    //In-order traversal for removal
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
        cout << "Name: " << root -> col_house.name
             << "\nLocation: " << root -> col_house.location << endl;
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

