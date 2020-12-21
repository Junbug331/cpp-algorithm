#include <iostream>
#include <vector>
#include <utility>

using std::cout;

class CountSubarrayWithSumK
{
public:
    CountSubarrayWithSumK(): a_(nullptr), n_(0), k_(0) {}

    CountSubarrayWithSumK(int* a, int n, int k)
    {
        a_ = a;
        n_ = n;
        k_ = k;
    }

    void PrintArray()
    {
        for (int i = 0; i < n_; i++)
            std::cout << a_[i] << " ";
        std::cout << "\n";
        
    }

    void PrintArray(int start, int end)
    {
        for (int i = start; i <= end; i++)
            std::cout << a_[i] << " ";
        std::cout << "\n";
        
    }

    int countSubarray()
    {
        int *c_sum = new int[n_];
        c_sum[0] = a_[0];
        for (int i=1; i<n_; i++)
            c_sum[i] = c_sum[i-1] + a_[i];
        
        int cnt = 0;
        for (int start = 0; start < n_; start++)
        {
            for (int end = start; end < n_; end++)
            {
                int tmp_sum = c_sum[end];
                if (start != 0)
                    tmp_sum = c_sum[end] - c_sum[start-1];
                if (tmp_sum == k_)
                {
                    cnt++;
                    PrintArray(start, end);
                }
            }       
        }
        return cnt;
    }

private:
    int* a_;
    int n_;
    int k_;
};

int main()
{

    int a[] = {1, 0, -1 ,1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 0;
    CountSubarrayWithSumK obj(a, n, k);


    obj.countSubarray();

    return 0;

}