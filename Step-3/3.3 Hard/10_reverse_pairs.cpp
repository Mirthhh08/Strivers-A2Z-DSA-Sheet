#include <bits/stdc++.h>
using namespace std;
// brute force approach
// T.C :- O(N^2)
// S.C .:-O(1)

int countReversePairs_brute(int arr[], int n)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > (2 * arr[j]))
            {
                cnt++;
            }
        }
    }

    return cnt;
}

// optimal  approach
// T.C :-O(NlogN)
// S.C .:-O(N) for storing the array during merge operation
void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low, right = mid + 1;
    vector<int> ans;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            ans.push_back(arr[left]);
            left++;
        }
        else
        {
            ans.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        ans.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        ans.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = ans[i - low];
    }
}
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;

        cnt += (right - (mid + 1));
    }

    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
    {
        return cnt;
    }

    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return cnt;
}
int countReversePairs_optimal(vector<int> &arr, int n)
{

    return mergeSort(arr, 0, n - 1);
}
int main()
{
    int n = 6;
    vector<int> arr = {3, 2, 4, 5, 1, 20};

    // cout << countReversePairs_brute(arr, n);

    cout << countReversePairs_optimal(arr, n);
    return 0;
}