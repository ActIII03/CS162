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

}

int table::insert(CollegeHousing & to_add)
{

    if(!insert(root, to_add))
    {
        cout << "Successfully added!" << endl;
        return 0;
    }
    return -1;
}

int table::insert(node * & root, CollegeHousing & to_add)
{
    //Root has is null so insert here
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
    else if(!(strcmp(root -> col_house.name, to_add.name)))
        insert(root -> right, to_add);

    //Otherwise go left
    else
        insert(root -> left, to_add);

    return 0;
    
}

int table::search(char * name, CollegeHousing & to_find)
{
    if(!search(root, name, to_find))
    {
        cout << "Floorplan found!" << endl;
        return 0;
    }
    return -1;

}

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
    display_sorted(root -> left);

    cout << "\nName: " << root -> col_house.name << "\n";
    return display_sorted(root -> right);
}
