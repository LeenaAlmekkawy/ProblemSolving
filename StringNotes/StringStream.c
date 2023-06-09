#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string input = "1 2 3 4 5";
    std::vector<int> nums; // create a vector to store the integers
    
    std::stringstream ss(input); // create a stringstream from the input string
    
    int num;
    while (ss >> num) { // extract integers from the stringstream
        nums.push_back(num); // add the integer to the vector
    }
    
    // print the elements of the vector
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}