#include <iostream>
#include <string>

int main()
{
    std::string name = "";
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    int age = 0;
    std::cout << "Enter your age: ";
    std::cin >> age;
    int b = 0;
    b=age+1;
    std::cout << "Pleased to meet you, " << name << "!" << std::endl;
    std::cout << "In your next birthday you'll be "<< b <<" years old!"<< std::endl;

    return EXIT_SUCCESS;
}
