#include "cs163_bst.h"
using namespace std;

int main()
{
    table BST, copy_of_BST;	
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    int count = 0, sum = 0, height = 0;
    bool flag = BST.is_balanced();

    cout << boolalpha << flag << " BST is balanced" << endl;
    //count = BST.count();
    //cout << "Number of nodes in our BST: " << count << endl;
    //sum = BST.sum();
    //cout << "Sum of every node in BST: " << sum << endl;
    //height = BST.height();
    //cout << "Height of tree: " << height << endl;
    //count = BST.remove_all();
    //cout << "Deleted " << count << " nodes\n";
    //count = copy_of_BST.copy(BST);

    //cout << "Copy of: \n";
    //copy_of_BST.display();
    //cout << "Number of copies: " << count << endl;

    //cout << "OG: \n";
    //BST.display();

    return 0;
}
