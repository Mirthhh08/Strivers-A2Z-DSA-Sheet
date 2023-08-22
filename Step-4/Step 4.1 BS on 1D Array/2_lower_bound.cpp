#include <bits/stdc++.h>
using namespace std;
// brute force approach
// T.C. :- O(N)
// S.C. :- O(1)
int lowerBound_brute(int arr[], int n, int k)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= k)
        {

            return i;
        }
    }
    return n;
}
// optimal approach
// T.C. :- O(logN)
// S.C. :- O(1)
int lowerBound(int arr[], int n, int k)
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
    int n = 5;
    int arr[n] = {3, 5, 8, 15, 19};
    int x = 9;

    // cout << lowerBound_brute(arr, n, x);
    cout << lowerBound(arr, n, x);
    return 0;
}