#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world!";
    std::string subStr = "world";

    size_t found = str.find(subStr);
    if (found != std::string::npos) {
        std::cout << "Substring found at position: " << found << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;
}