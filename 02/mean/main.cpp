#include <iostream>
using namespace std;
// Write here a function counting the mean value

int main()
{
    float S = 0;    int i = 0;    int n = 0;    int x = 0;    float m = 0;
    std::cout << "From how many integer numbers you want to count the mean value? ";
    std::cin  >> n ;
    if (n>0)
        {
        while(i < n)
        {
            ++i;
            std::cout << "Input "<<i<<". number: "; std::cin  >> x;
            S=S+x;

        }
        m=S/n;
        std::cout << " Mean value of the given numbers is " << m << endl;
        }
    else
        {std::cout << "Cannot count mean value from 0 numbers"<< endl;
        }



}
