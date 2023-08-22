#include <bits/stdc++.h>
using namespace std;

// T.C. :- O(log(N))
int firstOccr(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;

    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int lastOccr(vector<int> &arr, int n, int x)
{

    int low = 0, high = n - 1;

    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}
int main()
{
    int n = 6;
    vector<int> arr{3, 5, 7, 7, 15, 19};
    int x = 7;
    if (firstOccr(arr, n, x) == -1)
        cout << 0;

    else
        cout << lastOccr(arr, n, x) - firstOccr(arr, n, x) + 1;
    return 0;
}