#include <iostream>

using namespace std;

int main()
{
    int a=0; int b=0;
    cout << "Enter a number: ";
    cin>>a;
    b=a*a*a;
    if (b<0)
    {
        cout << "Error! The cube of " << a <<" is not "<< b <<"." <<endl;
    }
    else
    {
        cout << "The cube of " << a <<" is "<< b <<"." <<endl;
    }
    return 0;
}
