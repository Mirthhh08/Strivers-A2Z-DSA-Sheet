#include <bits/stdc++.h>
using namespace std;
// brute force approach
// T.C. :- O(N)
// S.C. :-  O(1)
int findPeak(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && arr[i] > arr[i + 1])
            return arr[i];

        else if (i == n - 1 && arr[i] > arr[i - 1])
            return arr[i];

        else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            return arr[i];
    }
}

// optimal approach
// T.C. :- O(logN)
// S.C. :-  O(1)

int findPeak_optimal(int arr[], int n)
{

    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;

    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            return mid;

        else if (arr[mid] > arr[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

int main()
{
    int n = 3;
    int arr[n] = {1, 2, 3};
    // cout << findPeak(arr, n);
    
    cout << findPeak_optimal(arr, n);
    return 0;
}