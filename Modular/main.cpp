#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;
// (a^n) % MOD
int fastExpo_recur(int a, long long n, int MOD)
{
    // base case
    if ( n == 0)
        return 1;
    // a^n = ((a^2)^(n/2))
    if (n % 2 == 0)
        return fastExpo_recur((1LL * a * a) % MOD, n / 2, MOD);
    // a^n = a * a^(n-1)
    return (1LL * a * fastExpo_recur(a, n-1, MOD)) % MOD;
}


int fastExpo_iter(int a, long long n, int MOD)
{
    /// -> (a^n) % MOD
    int result = 1;

    /// a = 2, n = 13, ans = 1
    /// 1. n is odd     : 2 * 2^12, a = 2, n = 12, ans = 2
    /// 2. n is even    : (4^6), a = 4, n = 6, ans = 2
    /// 3. n is even    : (16^3), a = 16, n = 3, ans = 2
    /// 4. n is odd     : 16 * 16^2, a = 16, n = 2, ans = 32
    /// 5. n is even    : (256^1), a = 256, n = 1, ans = 32
    /// 6. n is odd     : 256 * 256^0, a = 256, n = 0, ans = 256 * 32
    if ( n  == 0)
        return 1;

    while( n >= 1 )
    {
        if (n % 2 == 0)
        {
            a = (1LL * a * a) % MOD;
            n /= 2;
        }
        result = (1LL * result * a) % MOD;
        n--;
    }
    return result;
}

int main()
{
    system_clock::time_point start, end;
    microseconds microSec;

    start = system_clock::now();
    cout << fastExpo_recur(5, 10, 1000000007) << endl;
    end = system_clock::now();
    microSec = duration_cast<microseconds>(end - start);
    cout << "recur takes "<< microSec.count() << " us\n";
    cout << endl;

    start = system_clock::now();
    cout << fastExpo_iter(5, 10, 1000000007) << endl;
    end = system_clock::now();
    microSec = duration_cast<microseconds>(end - start);
    cout << "iter takes " << microSec.count() << " us\n";
    cout << endl;
   
    return 0;
}