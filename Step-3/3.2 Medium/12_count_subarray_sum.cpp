#include <bits/stdc++.h>
using namespace std;
// brute froce appraoch
// T.C. :- O(N^3)
// S.C. :- O(1)
int count_subarray(vector<int> arr, int k)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            if (sum == k)
                cnt++;
        }
    }

    return cnt;
}

// betterfroce appraoch
// T.C. :- O(N^2)
// S.C. :- O(1)
int count_subarray_better(vector<int> arr, int k)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            sum += arr[j];

            if (sum == k)
                cnt++;
        }
    }

    return cnt;
}

// optimal appraoch
// T.C. :- O(N)
// S.C. :- O(1)
int count_subarray_optimal(vector<int> arr, int k)
{
    int presum = 0;
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        presum += arr[i];
        int remove = presum - k;

        cnt += mp[remove];

        mp[presum]++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 6, 1, 4, 2, -3};
    int k = 3;
    // cout << count_subarray(arr, k);
    // cout << count_subarray_better(arr, k);
    cout << count_subarray_optimal(arr, k);
    return 0;
}