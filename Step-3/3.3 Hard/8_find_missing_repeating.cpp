#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C.. :- O(N^2)
// S.C :- O(1)
vector<int> findmissingandrepeating_brute(int n, int arr[])
{
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                ans.push_back(arr[i]);
                break;
            }
        }
        sum += arr[i];
    }
    int miss = ((n * (n + 1)) / 2) - (sum - ans.back());
    ans.push_back(miss);

    return ans;
}

// brute force approach
// T.C.. :- O(2N)
// S.C :- O(N)

vector<int> findmissingandrepeating_better(int n, int arr[])
{
    vector<int> ans;
    int hash[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            ans.push_back(i);
        else if (hash[i] == 0)
            ans.push_back(i);
    }
    return ans;
}

// optimal approach
// T.C.. :- O(N)
// S.C :- O(1)

vector<int> findmissingandrepeating_optimal(int n, int arr[])

{
    long long N = (long long)n;
    long long s = 0, s2 = 0;
    long long sn = (N * (N + 1)) / 2;
    long long s2n = (N * (N + 1) * (2 * N + 1)) / 6;

    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = s - sn;   // x - y
    long long val2 = s2 - s2n; // x2 - y2
    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;

    long long y = x - val1;

    return {(int)x, (int)y};
}


int main()
{
    int n = 3;
    int arr[n] = {1, 3, 3};

    // vector<int> ans = findmissingandrepeating_brute(n, arr);
    vector<int> ans = findmissingandrepeating_better(n, arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}