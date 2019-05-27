#include "cs162_list.h"


int main()
{
    list my_values;
    my_values.build();
          
    int to_add = 99, count;

    //PUT YOUR FUNCTION CALL HERE!
//    my_values.insert(to_add);
    count =  my_values.count_and_insert();
    my_values.display_all();
    my_values.append(to_add);
    cout << "Count from main: " << count << endl;
     
    return 0;

}
