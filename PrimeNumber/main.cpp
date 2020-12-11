#include <iostream>
#include <math.h>
#include <string>


using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= n && i*i <= n*n; ++i)
    {
        if ( i < n && n % i == 0 )
            return false;
    }
    return true;
}

void PrimeFactorization(int n, int* f, int* exep, int* len)
{
    int d = 2;
    *len = 0;
    
    if ( n == 1)
    {
        (*len)++;
        f[*len] = 2;
        exep[*len] = 0;

        return;
    }

    while (n > 1 && d*d <= n*n)
    {
        int k = 0;
        while (n % d == 0)
        {
            n /= d;
            k++;
        }
        if (k > 0)
        {
            f[*len] = d;
            exep[*len] = k;
            (*len)++;
        }
        d++;
    }

    if ( n > 1 )
    {
        f[*len] = n;
        exep[*len] = 1;
        (*len)++;
    }
}

void sieveOfEratosthenes(int limit, bool *isPrime)
{
    for (int i = 2; i < limit; i++)
        isPrime[i] = true;
    
    for (int i = 2; i < limit / 2; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * 2; j < limit; j += i)
                isPrime[j] = false;
        }
    }
}

int main()
{
    cout << "Testing isPrime() " << endl;
    for (int i = 2; i < 20; i++)
    {
        if (isPrime(i))
            cout << i << " is a prime number.\n";
        else
        {
            cout << i << " is not a prime number.\n";
        }
    }
    cout<<endl;

    cout << "Testing PrimeFactorization() " << endl;
    cout << "Prime factoriztion of 100 is " << endl;
    
    int n = 1020;
    int f[100], exep[100];
    int len;
    PrimeFactorization(n, f, exep, &len);

    string result = "";
    for (int i=0; i<len; i++)
    {
        result += to_string(f[i]) + "^" + to_string(exep[i]) + " * ";
    }
    result.replace(result.size()-3, 3, "");
    cout << result << endl;
    cout << endl;

    cout << "Testing SieveOfEratosthenes()" << endl;
    cout << "Printing out all the prime numbers from 2 to 50" << endl;
    bool isPrime[100];
    int limit = 50;
    sieveOfEratosthenes(limit, isPrime);
    for (int i = 2; i < limit; i++)
    {
        if (isPrime[i])
            cout << i << " ";
    }
    cout << endl;
    cout << endl;

    return 0;
}