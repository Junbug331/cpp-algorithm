#include <iostream>

using namespace std;

class MaxinumNumbersOfGroup
{
    int *a_;
    int n_;
    
public:
    MaxinumNumbersOfGroup(): a_(nullptr), n_(0) {}
    MaxinumNumbersOfGroup(int *a, int n)
    {
        n_ = n;
        a_ = new int[n];
        for (int i = 0; i < n; i++)
            a_[i] = a[i];
    }
    ~MaxinumNumbersOfGroup()
    {
        delete[] a_;
        a_ = nullptr;
        n_ = 0;
    }

    int sumof()
    {
        int sum = 0;
        for (int i = 0; i < n_; i++)
            sum += a_[i];
        return sum;
    }

    bool isValid(int k, int x)
    {
        long long cnt = 0;
        for (int i = 0; i < n_; i++)
            cnt += min(x, a_[i]);
        return cnt >= 1LL * x * k;
    }

    int bSearch(int k)
    {
        int left = 0, right = sumof()/k, ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (isValid(k, mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }

};

int main()
{
    int a[] = {1,2,3,4,5,6,7};
    int n = sizeof(a)/ sizeof(a[0]);

    MaxinumNumbersOfGroup obj(a, n);
    cout << obj.bSearch(5) << endl;
    return 0;
}

