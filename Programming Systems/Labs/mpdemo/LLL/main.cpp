#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int result = object.remove_duplicate();

    cout << "Number of non-distinct items removed: " << result << endl;

    object.display();  //displays the LLL again!
    
    return 0;
}
