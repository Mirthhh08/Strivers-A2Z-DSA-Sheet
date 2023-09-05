#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C. :- O(N^2)
// S.C. :- O(1)
int findRow(int n, int m, vector<vector<int>> arr)
{
    int ans = -1;
    int prevCnt = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                cnt++;
        }

        if (cnt > prevCnt)
        {
            ans = i;
        }
        prevCnt = cnt;
    }

    return ans;
}

int firstOcr(int row, int m, vector<vector<int>> arr)
{
    int low = 0, high = m - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[row][mid] == 1)
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
int findRow_better(int n, int m, vector<vector<int>> arr)
{
    int ans = -1;
    int max = 0;
    for (int i = 0; i < n; i++)
    {

        int firstOcc = firstOcr(i, m, arr);

        if (firstOcc > -1 && m - firstOcc > max)
        {
            max = m - firstOcc;
            ans = i;
        }
    }

    return ans;
}

// optimal approach
// T.C. :- O(N + M)
// S.C. :- O(1)
int findRow_optimal(int n, int m, vector<vector<int>> arr)
{
    int i = 0, j = m - 1, ans = -1;

    while (i < n && j >= 0)
    {
        if (arr[i][j] == 0)
        {
            i++;
        }
        else if (arr[i][j] == 1)
        {
            ans = i;
            j--;
        }
    }

    return ans;
}

int main()
{
    int n = 2, m = 2;
    vector<vector<int>> arr = {{0, 1},
                               {1, 1}};

    // cout << findRow(n, m, arr);
    // cout << findRow_better(n, m, arr);
    cout << findRow_optimal(n, m, arr);

    return 0;
}