#include <bits/stdc++.h>
using namespace std;
bool canWeplace(int n, vector<int> &stalls, int k, int dist)
{
    int cowCnt = 1, last = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cowCnt++;
            last = stalls[i];
        }
        if (cowCnt >= k)
        {
            return true;
        }
    }

    return false;
}
// brute force approach
// T.c. :- O(NlogN + O(N * max(stalls[n-1] - stalls[0]) ))
int solve(int n, vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int high = stalls[n - 1] - stalls[0];

    for (int i = high; i >= 0; i--)
    {
        if (canWeplace(n, stalls, k, i))
        {
            return i;
        }
    }
}

int solve_optimal(int n, vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int low = stalls[0], high = stalls[n - 1] - stalls[0];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canWeplace(n, stalls, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
int main()
{
    int n = 5;
    int k = 3;
    vector<int> stalls{1, 2, 4, 8, 9};

    // cout << solve(n, stalls, k);
    cout << solve_optimal(n, stalls, k);

    return 0;
}