#include <iostream>

#include <string> // header file for string

using namespace std; 

int main()

{

    // initializing integers

    int num1 = 21;

    int num2 = 2122;

    int num3 = 212232; 

    // Converting int to string

    string str1 = to_string(num1); 

    // Converting int to string

    string str2 = to_string(num2);

    // Converting int to string

    string str3 = to_string(num3);

    // print the converted strings

    cout << "String representation of num1: " << str1 << '\n';

    cout << "String representation of num2: " << str2 << '\n';

    cout << "String representation of num3: " << str3 << '\n';

    return 0;

}