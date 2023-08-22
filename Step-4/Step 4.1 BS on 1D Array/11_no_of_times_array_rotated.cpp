#include <bits/stdc++.h>
using namespace std;
int findMin(int arr[], int n)
{
    int low = 0, high = n - 1;

    int ans = INT_MAX;
    int idx = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // left part sorted
        if (arr[low] <= arr[mid])
        {
            int temp = ans;
            ans = min(ans, arr[low]);
            if (temp != ans)
            {
                idx = low;
            }
            low = mid + 1;
        }
        // right part sorted
        else
        {
            int temp = ans;
            ans = min(ans, arr[mid]);
            if (temp != ans)
            {
                idx = mid;
            }
            high = mid - 1;
        }
    }

    return idx;
}
int main()
{
    int n = 7;
    int arr[] = {4, 5, 6, 7, 8, 2, 3};
    cout << findMin(arr, n);
    return 0;
}