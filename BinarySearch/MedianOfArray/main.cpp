/// Find the median of two sorted array
/// arr1 = [1,3,5]
/// arr2 = [2,4,6]
/// median(arr1, arr2) = 3.5

#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <stdexcept>


using namespace std;

vector<int> mergeTwoArray(vector<int>& arr1, vector<int>& arr2)
{
    vector<int> mergedArr;
    int i, j;
    for (i = 0, j = 0; i < arr1.size() && j < arr2.size();  )
    {
        if (arr1[i] < arr2[j] )
            mergedArr.push_back(arr1[i++]);
        else if (arr1[i] > arr2[j])
            mergedArr.push_back(arr2[j++]);
        else
        {
            mergedArr.push_back(arr1[i++]);
            mergedArr.push_back(arr2[j++]);
        }
    }

    for (int k = i; k < arr1.size(); k++)
        mergedArr.push_back(arr1[k]);
    for (int k = j; k < arr2.size(); k++)
        mergedArr.push_back(arr2[k]);

    return mergedArr;
}

void PrintArr(vector<int>& arr)
{
    for (auto elem : arr)
        cout << elem << " ";
    cout << "\n";
}

double findMedianOfTwoSortedArrays_bruteForce(vector<int>& arr1, vector<int>& arr2)
{
    vector<int> mergedArr = mergeTwoArray(arr1, arr2);
    int n =  mergedArr.size();

    if (n % 2 != 0)
        return mergedArr[n/2]; 

    return (mergedArr[(n/2) - 1] + mergedArr[n/2]) / 2.0;
}
 
/*
    x1 x2 | x3 x4 x5 x6
    y1 y2 y3 y4 y5 | y6 y7 y8 

    if we found a partition('|') such that
    x2 <= y6
    y5 <= x3
    
    we can visualize an array such that
    [x1~x2][y1~y5]|[x3~x6][y6~y8]
    so the numbers that can be around our parition are
        behind the partition : x2 or y5  -> whichever bigger would be the number
        after the partition : x3 or y6  -> whichever smaller would be the number

    so midian would be (max(x2, y5) and min(x3, y6)) / 2  -> when sum of two arrays is even
    


    x: 1  3  8  9  15
    p 0  1  2  3  4  5
    y: 7  11 18 19 21 25

    x: 5 y: 6  num of elements

    *** how to find p ***
    partX + partY = (x + y + 1) / 2    for the case x + y is odd, we add + 1 -> it doesn't affect even case since 12 / 2 = 13 / 2 

    Loop : start = 0, end = size of shorter array - 1 (basically looping through shorter array)
    p = (start + end) / 2       <- Binary Search
    partX : p
    partY : calculate partY each time by above equation

    Found case is
        maxLeftX <= minRightY       =>      x[partX-1] <= y[partY]
        maxRightY <= minRightX       =>      y[partY-1] <= x[partX]
        we found our P
        
    else if (= maxLeftX > minRightY)
        move torward left in x      (= move toward right in y)
    else (= maxLeftY > minRightX)
        move toward right in x      (= move toward left in y)
*/

double findMedianOfTwoSortedArrays_optimized(vector<int>& arr1, vector<int>& arr2)
{
    if (arr1.size() > arr2.size())
        return findMedianOfTwoSortedArrays_optimized(arr2, arr1);
    

    int x = arr1.size();
    int y = arr2.size();

    int left = 0;
    int right = x;

    while(left <= right)
    {
        int partitionX = (left + right) / 2;
        int partitionY = (x + y + 1)/2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : arr1[partitionX-1];
        int minRightX  = (partitionX = x) ? INT_MAX : arr1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : arr2[partitionY-1];
        int minRightY = (partitionY == y) ? INT_MAX : arr2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            if ((x + y) % 2 == 0)
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            else
                return max(maxLeftX, maxLeftY);
        }
        else if(maxLeftX > minRightY)
        {
            right = partitionX - 1;
        }
        else if(maxLeftY > minRightX)
        {
            left = partitionX + 1;
        }
    }

    throw std::invalid_argument("Array isnt sorted!\n");

    return 0.0;
}

int main()
{
    vector<int> arr1 = {1, 3, 8, 9, 15};
    vector<int> arr2 = {7, 11, 19, 25};
    cout << findMedianOfTwoSortedArrays_bruteForce(arr1, arr2)  << "\n";
    cout << findMedianOfTwoSortedArrays_optimized(arr1, arr2) << "\n";

    return 0;
}