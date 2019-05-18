#include "cs162_list.h"

//Start in Step 3 by uncommenting out the code to create 
//a list object and build it!

int main()
{
    //Create an object of class list
    list my_list;
    int count = 0;
    //Call the build function to create a Linear Linked List
    //(The build member function has already been written)
    my_list.build();
    my_list.display_all();
    count = my_list.count_first();
    cout << "Main count is: " << count << endl;
    my_list.display_last();
    //Place your code here to call the functions for Lab #7


    return 0;
}
