#include <bits/stdc++.h>
using namespace std;
// Brute force approach
// T.C : O(N^2)
// S.C : O(1)
int majorityElement_brute(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                cnt++;
        }

        if (cnt > n / 2)
            return arr[i];
    }

    return -1;
}

// better approach
// T.C : O(N) + O(N) (for unordered map most cases) or
//    T.C  :(O(NLog(N)) + O(N) for map)
// S.C : o(N)

int majorityElement_better(int arr[], int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }

    return -1;
}

// optimal appraoch
// Moore's Voting Algorithm
// T.C. :- O(N) + O(N)
// S.C :- O(1)
int majorityElement_optimal(int arr[], int n)
{

    int ele = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = arr[i];
        }

        else if (arr[i] == ele)
        {
            cnt++;
        }

        else
        {
            cnt--;
        }
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            temp++;
        }
    }

    return temp > n / 2 ? ele : -1;
}
int main()
{
    int n = 10;
    int arr[n] = {1, 5, 7, 6, 7, 7, 7, 6, 6, 10};
    // cout << majorityElement_brute(arr, n);
    // cout << majorityElement_better(arr, n);

    cout << majorityElement_optimal(arr, n);
    return 0;
}