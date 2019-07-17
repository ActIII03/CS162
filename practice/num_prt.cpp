#include <iostream>

using namespace std;

int main(){

    //char word[] = "Hello";
    char *ch_ptr;
    //ch_ptr = word;
    int num[] = { 1, 2, 3, 4};

    char letter[] = "center";
    ch_ptr = letter;  //Need address operator

    int *ptr;
    ptr = num;

    cout << "Without for-loop: " << *ptr << endl;

    for(int i = 0; i < 4; ++i)
        cout << "ptr: " << *ptr++ << endl;

    cout << "Word(w/o *): " << ch_ptr 
         << "\nWord(w/ *): " << &ch_ptr << endl;
    return 0;
}
