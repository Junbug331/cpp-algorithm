#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= static_cast<int>(sqrt(n)); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    for (int i = 2; i < 20; i++)
    {
        if (isPrime(i))
            cout << i << " is a prime number.\n";
        else
        {
            cout << i << " is not a prime number.\n";
        }
    }
    
    return 0;
}