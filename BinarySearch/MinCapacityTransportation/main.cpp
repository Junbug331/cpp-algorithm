#include <iostream>

using namespace std;

class MinCapacityTransportation
{
    int *a_;
    int n_;
    int k_;

public:
    int maxVal()
    {
        int maxVal = a_[0];
        for (int i = 1; i < n_; i++)
            maxVal = maxVal > a_[i] ? maxVal : a_[i];
        return maxVal;
    }

    long long sumOf()
    {   
        long long sum = 0;
        for (int i = 0; i < n_; i++)
        {
            sum += a_[i];
        }
        return sum;
    }

    int num_of_ride(int c)
    {
        if(a_ == nullptr)
            return -1;

        int ans = 1;
        long long sum = 0;
        for (int i = 0; i <= n_; i++)
        {
            if (sum + a_[i] <= c)
                sum += a_[i];
            else
            {
                ans++;
                sum = a_[i];
            }
        }
        return ans;
    }

    int min_capacity()
    {
        int left = maxVal(), right = sumOf(), mid;
        int ans = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            int rides = num_of_ride(mid);
            if (rides > k_)
                left = mid + 1;
            else
            {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }

public:
    MinCapacityTransportation(): a_(nullptr), n_(0), k_(0) {}
    MinCapacityTransportation(int *a, int n, int k)
    {
        n_ = n;
        a_ = new int[n_];
        for (int i= 0; i < n; i++)
            a_[i] = a[i];
        k_ = k;
    }
}; 

int main()
{  
    int a[] = {7, 3, 2, 3, 1, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;
    MinCapacityTransportation obj(a, n, k);
    cout << obj.min_capacity() << endl;;

    return 0;
}