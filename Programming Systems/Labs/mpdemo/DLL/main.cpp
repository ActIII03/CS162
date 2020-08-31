#include "dlist.h"


int main()
{
    list object;
    list copy;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int result = copy.duplicate(object);
    cout << "Number of items: " << result << endl;


    cout << "Copy:\n";
    copy.display();
    
    return 0;
}
