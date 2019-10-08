#include <iostream>
#include <cstring>

using namespace std;

void get_char_arr(char * arr){

    cout << arr << endl;
    cin.getline(arr, 14, '\n');
    cin.ignore(); 

}

int main(){

    char c_arr[15]= "ORIGINAL";
    cout << "Char arr: " << c_arr << endl;
    get_char_arr(c_arr);
    cout << "Char arr: " << c_arr << endl;
    get_char_arr(c_arr);
    cout << "Char arr: " << c_arr << endl;
    return 0;
}
