#include <iostream>

using namespace std;

long long i,nfac;
long long factorial(long long n)
    {
    nfac=1;
    i=1;
    for (i=1;i<=n;i++)
        {
        nfac=nfac*i;
        }
    return (nfac);
    }

int main()
{
    long long a, b, c; long long bf,af,cf,k;
    cout << "Enter the total number of lottery balls: ";
    cin  >> a;
    cout << "Enter the number of drawn balls: ";
    cin  >> b;
    if(b < 0 or a < 0)
    {
        cout << "The number of balls must be a positive number.";
    }
    else if (a<b)
    {
        cout << "The maximum number of drawn balls is the total amount of balls.";

        }
    else
    {
        c=a-b;
        //cout<<c<<endl;
        af=factorial(a); bf=factorial(b); cf=factorial(c);
        //cout << af<<endl<<bf <<endl<< cf;

        k=af/((cf)*bf);
        cout << "The probability of guessing all " <<b<<" balls correctly is 1/"<< k <<endl;
    }
    return 0;
}
