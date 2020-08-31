#include "arr.h"


int main()
{
    table object; 
    table new_table; 
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int count = object.remove_last_LLL();
    cout << "Number of removed items from last LLL: " << count << endl;

    object.display();  //display again afterward!
    
    return 0;
}
