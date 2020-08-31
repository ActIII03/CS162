#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    float result = object.get_height();   
    if(!result)
        cout << "Tree is empty!" << endl;
    else
        cout << "Average: " << result << endl;


    object.display();	//displays again after!
   
    return 0;
}
