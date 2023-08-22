#include <bits/stdc++.h>
using namespace std;

int isPossible(int m, int k, vector<int> &bloomDay, int day)
{

    int totalFlwrs = 0, bqtCnt = 0;
    int n = bloomDay.size();

    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= day)
        {
            totalFlwrs++;

            if (totalFlwrs == k)
            {
                bqtCnt++;
                totalFlwrs = 0;
            }
        }
        else
        {
            totalFlwrs = 0;
        }
    }

    if (bqtCnt >= m)
        return true;
    else
        return false;
}

int findMax(int n, vector<int> &bloomDay)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, bloomDay[i]);
    }

    return maxi;
}
// brute force approach
// T.C. :- O(max{bloomDay} * N)
// S.C. :- O(1)
int solve(int m, int k, vector<int> &bloomDay)
{
    int n = bloomDay.size();

    int maxi = findMax(n, bloomDay);
    for (int i = 1; i <= maxi; i++)
    {

        if (isPossible(m, k, bloomDay, i))
        {
            return i;
        }
    }

    return -1;
}

// optimal approach
// T.C. :- O(log(max{bloomDay}) * N)
// S.C. :- O(1)
int solve_optimal(int m, int k, vector<int> &bloomDay)
{
    int n = bloomDay.size();

    int low = 0, high = findMax(n, bloomDay);

    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(m, k, bloomDay, mid))
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

    int m = 2, k = 3;
    vector<int> bloomDay = {5, 5, 5, 5, 10, 5, 5};

    // cout << solve(m, k, bloomDay);
    cout << solve_optimal(m, k, bloomDay);
    return 0;
}