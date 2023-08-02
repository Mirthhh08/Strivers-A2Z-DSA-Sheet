#include <bits/stdc++.h>
using namespace std;

// brute force approach
//  T.C : O(N^2)
// S.C. : O(1)
int twoSum(int arr[], int n, int k)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
                count++;
        }
    }

    return count;
}

// better Approach (optimal in case where you have to return indexes)
// using hashing
//  T.C : O(NlogN)
// S.C. : O(N)
int twoSum_better(int arr[], int n, int k)
{
    map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int diff = k - arr[i];
        if (mp.find(diff) != mp.end())
        {
            cnt++;
        }

        mp[arr[i]] = i;
    }

    return cnt;
}

// optimal Approach ( not optimal in case where you have to return indexes)
//  using hashing
//   T.C : O(NlogN)
//  S.C. : O(1)

int twoSum_optimal(vector<int> arr, int k)
{
    int left = 0, right = arr.size() - 1;
    int cnt = 0;
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == k)
            return 1;
        else if (sum < k)
            left++;
        else
            right--;
    }

    return 0;
}

int main()
{
    int n = 4, k = 6;
    int arr[n] = {1, 5, 7, 1};
    // cout << twoSum(arr, n, k);

    // cout << twoSum_better(arr, n, k);

    vector<int> nums = {1, 5, 7, 1};
    cout << twoSum_optimal(nums, k);
    return 0;
}