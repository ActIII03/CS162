#include <iostream>
using namespace std;

int main(void) { 
    int a, b, c;
    double fl;
    char d, e, f;
    
    cout << "First this program will take in three numbers." << endl;
    cout << "Enter a number: ";
    a = cin.peek();
    
    if(cin.fail()) {
        cout << "Fail state detected!" << endl;
        cin >> d;
        if(d == 'q')
        {
            cout << d << endl;
            return 0;
        }
        
        cin.clear();
        cin.ignore(100, '\n');
    }
    cin >> a; 

    cout << a << endl;
        
    cout << "Enter a number: ";
    cin >> b;
    cout << b << endl;
    
    cout << "Enter a number: ";
    cin >> c;
    cout << c << endl; 
    
    cout << endl << "Now we use get() to get a char." << endl;
    //cin.ignore();
    cout << "enter a characer: ";
    d = cin.get();
    cout << d << endl;
    
    cout << endl << "Finally we take in two more characters." << endl;
    cout << "Enter two charcters: ";
    cin >> e >> f;
    cout << e << " " << f << endl; 

    return 0;   
}
