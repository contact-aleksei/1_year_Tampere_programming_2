#include <iostream>

using namespace std;

int main()
{
    int temp;
    float tempF,tempC;
    cout << "Enter a temperature: ";
    cin >> temp;
    tempF=1.8*temp+32;
    tempC=(temp-32)/1.8;
    cout << temp << " degrees Celsius is "<< tempF<<" degrees Fahrenheit"<< endl;
    cout << temp << " degrees Fahrenheit is "  << tempC  << " degrees Celsius"<< endl;

    return 0;
}
