#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    char ch;
    ifstream in_file;
    in_file.open("Test.dat");

    //Doesn't read white sapce characters
    //Read and echo
    if(in_file)
    {
        in_file >> ch;
        while(in_file && !in_file.eof())
        {
            cout << ch;
            in_file >> ch;
        }
        in_file.close();
        in_file.clear;
    }

    /*Echoes all characters, including white space
     * This approach is used only for working with single characters and not with arrays
     * if(in_file)
     * {
     *      ch = in_file.get();   <---- Reads any characters
     *      while(in_file && !in_file.eof())    <--Succesful?
     *      {
     *          cout << ch;     <--- Processes what was read
     *          ch = in_file.get();    <---Attemt to read again
     *      }
     *      in_file.close();  <---Done with file
     *      in_file.clear();  <---Allows 'in_file' var to be re-used
     *  }
     */

    /*Echoes all characters using arrays of characters
     *
     * const int MAX = 255;         <----- Done globally
     * -------------------------------------------------
     *
     *  char line[MAX];
     *  char delimiter;
     *  ifstream in_file;
     *  in_file.open("Test.dat");
     *
     *  if(in_file)
     *  {
     *      in_file.get(line, MAX, '\n');       <---Read in a line
     *      while(in_file && !in_file.eof())    <---Successful?
     *      {
     *              //Prefer to read in with delimiter
     *              delimiter = in_file.get;
     *              cout << line << delimiter;
     *              in_file.ignore(100, '\n');      <---Progress past the delimiter
     *
     *              //Attempt to read in next one
     *              in_file.get(line, MAX, '\n');  <---Attempt to read again
     *
     *      }
     *      in_file.close();
     *      in_file.clear();
     *  }
     */
    return 0;
}
