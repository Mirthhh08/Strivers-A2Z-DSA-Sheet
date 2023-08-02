#include <bits/stdc++.h>
using namespace std;

// brute force approach
// using set

// Time .Complexity.

// insertion in set takes O(logN)
// so,
// overall T.C. : O(Nlog(N) + N)

// T.C. : O(Nlog(N))
// S.C. : O(N)
int removeDuplicateFromSortedArray(int arr[], int n)
{
    set<int> uniqueSet;

    for (int i = 0; i < n; i++)
    {
        uniqueSet.insert(arr[i]);
    }

    int idx = 0;
    for (auto it : uniqueSet)
    {
        arr[idx] = it;
        idx++;
    }

    return idx;
}

// optimal
//  two - pointer approach
// T.C. : O(N)
// S.C : O(1)
int removeDuplicateFromSortedArray_Optimal(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    return i + 1;
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

    // cout << removeDuplicateFromSortedArray(arr, n) << endl;
    cout<<removeDuplicateFromSortedArray_Optimal(arr , n)<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}