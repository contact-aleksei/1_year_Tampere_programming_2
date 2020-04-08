#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    std::cout << setw(7) << '*' << endl;
    std::cout << setw(5) << '*' << setw(4) << '*' << endl;
    std::cout << setw(3) << '*' << setw(8) << '*' << endl;
    std::cout << setw(1) << '*' << setw(12) << '*'<< endl;
    std::cout << setw(3) << '*' << setw(8) << '*' << endl;
    std::cout << setw(5) << '*' << setw(4) << '*' << endl;
    std::cout << setw(7) << '*' << endl;
    return 0;
}
