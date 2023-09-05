#include <bits/stdc++.h>
using namespace std;
// brute force approah
// T.C. :- O(N * M)
// S.C. :- O(1)
vector<int> findPeak(int n, int m, vector<vector<int>> arr)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (i > 0)
            {
                if (arr[i][j] < arr[i - 1][j])
                    continue;
            }
            if (j < m - 1)
            {
                if (arr[i][j] < arr[i][j + 1])
                    continue;
            }
            if (i < n - 1)
            {
                if (arr[i][j] < arr[i + 1][j])
                    continue;
            }

            if (j > 0)
            {
                if (arr[i][j] < arr[i][j - 1])
                    continue;
            }

            ans.push_back(i);
            ans.push_back(j);

            break;
        }
    }

    return ans;
}

// optimal approah
// T.C. :- O(N * log(M))
// S.C. :- O(1)
vector<int> findPeak_optimal(int n, int m, vector<vector<int>> arr)
{
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int l = -1, r = -1, u = -1, d = -1;

            if (mid - 1 >= 0)
                l = arr[i][mid - 1];
            if (mid + 1 < m)
                r = arr[i][mid + 1];
            if (i - 1 >= 0)
                u = arr[i - 1][mid];
            if (i + 1 < n)
                d = arr[i + 1][mid];

            if (arr[i][mid] > l && arr[i][mid] > r && arr[i][mid] > u && arr[i][mid] > d)
            {
                return {i, mid};
            }

            l < r ? low = mid + 1 : high = mid - 1;
        }
    }
}
int main()
{
    int n = 2, m = 2;

    vector<vector<int>> arr{{8, 6},
                            {10, 1}};

    // vector<int> ans = findPeak(n, m, arr);
    vector<int> ans = findPeak_optimal(n, m, arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}