#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C. = O(N^2)
// S.C. : O(1)
void longestSubArrayWithKSum(int arr[], int n, int k)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        long long s = 0;
        for (int j = i; j < n; j++)
        {

            s += arr[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }

    cout << len << endl;
}

// better appraoch
// using hashmap
// T.C. : O(N . log(N)) **ordered map
// T.C. : O(N) (most cases)  or O(N^2) (rare case) **unordered map
// S.C. : O(N)
// ** optimal apprach for positives and negatives ** //
void longestSubarrayWithKSum_better(int arr[], int n, int k)
{

    int prefixSum = 0;
    int maxlen = 0;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {

        prefixSum += arr[i];

        if (prefixSum == k)
            maxlen = max(maxlen, i + 1);

        int diff = prefixSum - k;

        if (mp.find(diff) != mp.end())
        {
            maxlen = max(maxlen, i - mp[diff]);
        }

        // mp[prefixSum] = i; when array contains positvies

        if (mp.find(prefixSum) == mp.end())
        {
            mp[prefixSum] = i;
        }
    }

    cout << maxlen << endl;
}

// optimal appraoch
// using two pointer
// T.C. : O(2N) ~ T.C. : O(N)
// S.C. : O(1)
// * for positives and zeros *  //
void longestSubarrayWithKSum_Optimal(int arr[], int n, int k)
{

    int i = 0, j = 0;
    int maxlen = 0;
    int sum = 0;
    
    while (i < n)
    {

        while (sum > k)
        {
            sum -= arr[j];
            j++;
        }

        if (sum == k)
        {
            maxlen = max(maxlen, i - j);
        }

        sum += arr[i];

        i++;
    }

    cout << maxlen;
}

int main()
{
    int n = 5, k = 3;

    int arr[n] = {1, 1, 1, 2, 1};

    // longestSubArrayWithKSum(arr, n, k);

    // longestSubarrayWithKSum_better(arr, n, k);

    longestSubarrayWithKSum_Optimal(arr, n, k);
    return 0;
}