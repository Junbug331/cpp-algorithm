#include <iostream>

using namespace std;

static const int MAX = 100;

int main()
{
    int fr[MAX] = {0};
    int a[6] ={7, 3, 1, 3 ,2, 7};
    int cnt = 0;

    for (int i = 0; i < 6; i++)
    {
        if(fr[a[i]] == 0)
            cnt++;
        fr[a[i]]++;
    }
    
    cout << "cnt = " << cnt << endl;
    for (int i=0; i<6; i++)
        cout << a[i] << " appears " << fr[a[i]] << " times. \n"; 
    cout << endl;
    
    return 0;
}