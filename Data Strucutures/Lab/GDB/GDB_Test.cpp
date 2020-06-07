#include <iostream>
#include <cstring>
using namespace std;

class Journal_Entry
{
    public:
        void Set_Title(char * toAdd);
        void Show_Title();
    
    private:
        char * Title;
};

void Journal_Entry::Set_Title(char * toAdd)
{
    Title = new char[strlen(toAdd)+1];
    strcpy(Title, toAdd);
}

void Journal_Entry::Show_Title()
{
    cout << Title << endl;
}

int main()
{
    Journal_Entry * Entry = NULL; //new Journal_Entry;
    
    char toAdd[300];

    cout << "\nPlease enter a title for your journal entry:\n";
    cin.get(toAdd, 300, '\n');

    Entry -> Set_Title(toAdd);

    cout << endl << "The title is:\n";
    Entry -> Show_Title();

    return 0;
}
