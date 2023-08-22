#include <bits/stdc++.h>
using namespace std;
// iterative approach
// T.C. :- O(log N)
// S.C. :- O(1)
int binarySearch(int arr[], int n, int k)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
            return mid;

        else if (arr[mid] < k)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

// recursive approach
int binarySearch_recursive(int arr[], int low, int high, int k)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == k)
        return mid;

    if (arr[mid] < k)
        return binarySearch_recursive(arr, mid + 1, high, k);

    return binarySearch_recursive(arr, low, mid - 1, k);
}
int main()
{
    int n = 5;
    int arr[n] = {2, 3, 5, 7, 9, 11};
    int k = 9;

    cout << binarySearch(arr, n, k);
    cout << endl;
    cout << binarySearch_recursive(arr, 0, n - 1, k);
    return 0;
}