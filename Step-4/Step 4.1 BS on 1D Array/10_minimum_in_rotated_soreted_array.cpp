#include <bits/stdc++.h>
using namespace std;
int findMin(int arr[], int n)
{
    int low = 0, high = n - 1;

    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // left part sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // right part sorted
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}
int main()
{
    int n = 7;
    int arr[] = {4, 5, 6, 7, 8, 2, 3};
    cout << findMin(arr, n);
    return 0;
}