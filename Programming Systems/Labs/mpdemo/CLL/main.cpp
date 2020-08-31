#include "clist.h"


int main()
{
    list object;
    list copy;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int result = object.add_before_even();
    cout << "Number of insertions before even: " << result << endl;


    object.display(); //resulting list after your function call!
    
    return 0;
}
