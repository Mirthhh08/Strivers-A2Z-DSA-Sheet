#include <bits/stdc++.h>
using namespace std;

int calculateTime(int n, int arr[], int hourly)
{
    int totalH = 0;

    for (int i = 0; i < n; i++)
    {

        totalH += ceil((double)arr[i] / (double)hourly);
    }

    return totalH;
}
int findMax(int n, int arr[])
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

// brute force approach
// T.C. :- O( max(arr) * N)
// S.C. :- O(1)
int solve(int n, int arr[], int h)
{
    int maxi = findMax(n, arr);

    for (int i = 1; i < maxi; i++)
    {
        int reqT = calculateTime(n, arr, i);

        if (reqT < h)
            return i;
    }
}



// optimal approach
// T.C. :- O( log(max(arr[n])) * N)
// S.C. :- O(1)
int solve_optimal(int n, int arr[], int h)
{
    int low = 0, high = findMax(n, arr);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int reqT = calculateTime(n, arr, mid);

        if (reqT <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}
int main()
{
    int n = 4;
    int arr[n] = {3, 5, 6, 11};
    int h = 6;

    // cout << solve(n, arr, h);

        cout << solve_optimal(n, arr, h);
    return 0;
}