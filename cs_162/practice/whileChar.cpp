#include <iostream>
using namespace std;

int main(void)
{
	
	char response = 'n';
	int num;
	while ('n' == response)
	{
	cout << "Enter a number: ";
	cin >> num; cin.ignore();
	cout << "You entered " << num << endl
	     << "is this correct? ";
	cin >> response; cin.ignore();
	}
	return 0;
}
