#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C. :- O(N^2)
// S.C. :- O(1)
int maxSubarrayXOR_brute(int n, int arr[], int k)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = i; j < n; j++)
        {
            x = x xor arr[j];

            if (x == k)
                cnt++;
        }
    }

    return cnt;
}

// optimal  approach
// T.C. :- O(N)
// S.C. :- O(N)
int maxSubarrayXOR_optimal(int n, int arr[], int k)
{
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x ^= arr[i];

        int diff = x ^ k;
        if (mp.find(diff) != mp.end())
        {
            cnt += mp[diff];
        }

        mp[x]++;
    }

    return cnt;
}

int main()
{
    int n = 5;
    int arr[n] = {4, 2, 2, 6, 4};
    int k = 6;
    // cout << maxSubarrayXOR_brute(n, arr, k);
    cout << maxSubarrayXOR_optimal(n, arr, k);
    return 0;
}