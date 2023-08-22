#include <bits/stdc++.h>
using namespace std;

int findLowerBound(vector<int> arr, int n, int k)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= k)
        {
            ans = mid;
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
    vector<int> arr{3, 5, 8, 9, 15, 19};
    int x = 9;
    cout << findLowerBound(arr, n, x);
    return 0;
}