#include <bits/stdc++.h>
using namespace std;
// T.C. :- O(log(N))
int findfloor(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int findCeil(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n = 6;
    int arr[n] = {3, 5, 7, 8, 15, 19};
    int x = 9;

    cout << findfloor(arr, n, x) << endl;
    cout << findCeil(arr, n, x);

    return 0;
}