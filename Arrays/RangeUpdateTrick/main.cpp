#include <iostream>
#include <memory>

class RangeUpdate
{
public:
    RangeUpdate(): n(0), a(nullptr), b(nullptr), s(nullptr), updateFlag(false)
    {}
    void InitializeArray(int *inputArray, int nmax = 10);
    void Update(int x, int y, int val);
    void BuildFinalArray();
    void PrintArray();

private:
    int n;
    int* a, *b, *s;
    bool updateFlag;
};

void RangeUpdate::InitializeArray(int *inputArray, int nmax)
{
    if (a)
    {
        delete[] a;
        delete[] b;
        delete[] s;
        a = nullptr;
        b = nullptr;
        s = nullptr;
    }
    n = nmax + 1;
    a = new int[n];
    b = new int[n];
    s = new int[n];
    a[0] = b[0] = s[0] = 0;
    for (int i=1; i < n; i++)
    {
        a[i] = inputArray[i-1];
        b[i] = 0;
        s[i] = 0;
    }
        
}

void RangeUpdate::Update(int x, int y, int val)
{
    b[x] += val;
    b[y+1] -= val;

    if (!updateFlag)
        updateFlag = true;
} 

void RangeUpdate::BuildFinalArray()
{
    if (updateFlag)
    {
        for (int i=1; i<=n; i++)
        {
            s[i] = s[i-1] + b[i];
            a[i] += s[i];
        }
        
        updateFlag = false;
        std::cout <<"s: "; std::cout.width(3);
        for (int i=1; i<n; i++)
            std::cout << s[i] << " ";
        std::cout << std::endl;
    }
}

void RangeUpdate::PrintArray()
{
    if (!updateFlag)
    {
        std::cout << "a: ";
        for (int i = 1; i < n; i++)
            std::cout << std::cout.width(3) << a[i];
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Array hasn't updated yet!!" << std::endl;
        std::cout <<"b: ";
        for (int i=1; i<n; i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;
    }
    
}


int main()
{
    RangeUpdate rangeupdate;
    int a[9] = {2, -7, 10, 3, -1, 19, -20, 23, 17};
    rangeupdate.InitializeArray(a, 9);
    rangeupdate.PrintArray();

    rangeupdate.Update(3, 7, 5);
    rangeupdate.Update(4, 8, 2);
    rangeupdate.Update(2, 6, -1);

    rangeupdate.BuildFinalArray();

    //rangeupdate.PrintArray();


    return 0;
}