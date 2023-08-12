// CPP code to illustrate
// erase(size_type idx, size_type len )
#include <iostream>
#include <string>
using namespace std;

// Function to demo erase
void eraseDemo(string str)
{
	// Deletes 4 characters from index number 1
	str.erase(1, 4);

	cout << "After erase : ";
	cout << str;
}

// Driver code
int main()
{
	string str("Hello World!");

	cout << "Before erase : ";
	cout << str << endl;
	eraseDemo(str);

	return 0;
}
