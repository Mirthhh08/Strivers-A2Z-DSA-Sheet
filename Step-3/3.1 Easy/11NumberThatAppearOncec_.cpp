#include <bits/stdc++.h>
using namespace std;
// brute force appraoch
// T.C.: O(N^2)
// S.C : O(1)
int search(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
        }

        if (count == 1)
        {
            return arr[i];
        }
    }
}

// better approach
// T.C.: O(N)  unorderd_map takes O(1) for insertion most case
// T.C : O(N^2) worst case very rare
// S.C : O(1)
int search_using_hashing(int arr[], int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}

// optimal Appraoch
// T.C. : O(N)
// S.C. : O(1)
int search_optimal(int arr[], int n)
{
    int x = 0;

    for (int i = 0; i < n; i++)
    {
        x = x ^ arr[i];
    }

    return x;
}


// best Appraoch
// T.C. : O(logN)
// S.C. : O(1)

int search_best(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                low = mid + 2;
            }
            else
            {
                high = mid;
            }
        }

        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return arr[low];
}
int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << search(arr, n);
    // cout << search_optimal(arr, n);

    cout << search_best(arr, n);

    return 0;
}
