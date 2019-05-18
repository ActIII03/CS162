#include <fstream>
#include <iostream>
using namespace std;

const char outfile[]= "out.dat"; //file location where data will writen too

int main()
{
    ofstream out; //variable used to use fstream fun()
    int data = 10;
    char delimiter = ',';
    out.open(outfile); //Opens the file to write at the begining of the file
                       //and destroys any content!
    //out.open(outfile, ios::app);
    
    if(out) //Checks for successful connections
    {
        out << data << delimiter << endl;

        out.close();  //Closes the file (No arguments)
        out.clear();  //Allows 'out' variable to be reused 
    }
    return 0;
}
