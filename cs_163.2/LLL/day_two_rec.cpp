#include "list.h"

//(1) Is the problem repetitive?
//(2) What are the non-repetitive problem(s)? <-- possiblely have two functions for separate problems
//(3) What is the base case?
//(4) What operations are to be done before or after recursive calls?
//(5) Any other stopping conditions?
//(6) How to get to the sub-problem?


int display_in_reverse(node * head)
{
    if(!head)
        return  0;
    int count = 1;
    count += display_in_reverse(head -> next);
    count += 1;
    cout << "Data: " << head -> data << endl;
    return count;
}
