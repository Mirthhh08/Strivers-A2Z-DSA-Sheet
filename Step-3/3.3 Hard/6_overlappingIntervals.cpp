#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C. :- O(N * log(N)) + O(2N);
// S.C. :- O(log(N)) or O(N)
vector<vector<int>> overlappedIntervals_brute(vector<vector<int>> arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        if (!ans.empty() && end <= ans.back()[1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (end >= arr[j][0])
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}

// optimal approach
// T.C. :- O(N * log(N)) + O(N);
// S.C. :- O(log(N)) or O(N)
vector<vector<int>> overlappedIntervals_optimal(vector<vector<int>> arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        if (ans.empty() || arr[i][0] > ans.back()[1])
            ans.push_back(arr[i]);

        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> arr{{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    // vector<vector<int>> ans = overlappedIntervals_brute(arr);
    vector<vector<int>> ans = overlappedIntervals_optimal(arr);

    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    cout<<ans.back()[1];
    return 0;
}