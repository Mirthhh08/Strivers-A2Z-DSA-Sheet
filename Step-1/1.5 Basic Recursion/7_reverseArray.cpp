#include <bits/stdc++.h>
using namespace std;
//  using pointers
int  reverseArray(int arr[], int s = 0, int e = 4)
{

    if (s > e)
    {
        return 1;
    }

    swap(arr[s], arr[e]);
    return reverseArray(arr, s+1, e-1);

    
}

// without pointers
int  reverseArray2(int arr[] , int i)
{

    if (i >= (5 - i - 1))
    {
        return 1;
    }

    swap(arr[i], arr[5 - i - 1]);
    return reverseArray2(arr , i + 1);

    
}
int main()
{

    int arr[5] = {1, 2, 3, 4, 5};

    reverseArray2(arr , 0);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}