#include <iostream>

using namespace std;

void get_leng_ht(cube *c_pntr[]);

struct cube   
{
    int length;
    int height;
    int area;
};

int main(void)
{
    cube c;
    cube *c_pntr;
    c_pntr = &c;

    c.length = 2;
    c.height = 2;
    c.area = (c.length * c.length) * c.height;

    cout << "Length: " << c.length << "\nHeight: " << c.height << endl;
    cout << "Area: " << c.area << endl;

    c_pntr -> length = 4;
    c_pntr -> height = 4;
    c.area = (c.length * c.length) * c.height;

    cout << "*Length: " << c.length << "\n*Height: " << c.height << endl;
    cout << "*Area: " << c.area << endl;

    return 0;
}
