#include "cs163_list.h"
using namespace std;

int main()
{
    
    //First try this out as is. Then start adding in your function calls!
    list my_list;
    my_list.build();
    my_list.display_all();

    //PLACE YOUR FUNCTION CALL HERE!
    //int sum = my_list.sum_total();
    //cout << "\nSum of LLL from main: " << sum << endl;

    //bool flag = my_list.remove_last();
    //if(!flag)
    //    cout << "Nothing was removed" << endl;
    //else
    //    cout << "Removal was successful" << endl;
    
    //int choice = 0;
    //cout << "Pick a number from the list to remove: ";
    //cin >> choice;
    //cin.ignore(100, '\n');
    //my_list.find_item(choice);

    //bool result = my_list.remove_all();
    //if(!result)
    //    cout << "Remove-all was unsuccessful" << endl;
    //else
    //    cout << "Remove-all was successful" << endl;

    //my_list.remove_all();
    //int choice = 0;
    //cout << "Please pick a number to find:" << endl;
    //cin >> choice;
    //cin.ignore(100, '\n');
    //bool result = my_list.find_item(choice);
    //if(!result)
    //    cout << "Search was unsuccessful" << endl;
    //else
    //    cout << "Search was successful" << endl;

    list dest_list;
    bool result = dest_list.copy(my_list);
    if(!result)
        cout << "Copy-all was unsuccessful" << endl;
    else
        cout << "Copy-all was successful" << endl;

    dest_list.display_all();

    return 0;    
}
