#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C. :- O(N^2)
// S.C. :- O(1)
int maxlen_brute(int arr[], int n)
{
    int maxlen = 1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            cnt++;

            if (sum == 0)
            {
                maxlen = max(maxlen, cnt);
            }
        }
        cnt = 0;
    }

    return maxlen;
}

// optimal  approach
// T.C. :- O(N)
// S.C. :- O(N)
int maxlen_optimal(int arr[], int n)
{
    int maxlen = 0;
    unordered_map<int, int> mp;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            maxlen = i + 1;

        else
        {
            if (mp.find(sum) != mp.end())
            {
                maxlen = max(maxlen, (i - mp[sum]));
                continue;
            }

            mp[sum] = i;
        }
    }

    return maxlen;
}
int main()
{

    int n = 4;
    int arr[n] = {-1 , 1 , -1 ,1};

    // cout << maxlen_brute(arr, n);
    cout << maxlen_optimal(arr, n);
    return 0;
}