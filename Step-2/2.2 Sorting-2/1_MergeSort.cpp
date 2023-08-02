#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    // Your code here
    int left = l, right = m + 1;
    vector<int> ans;

    while (left <= m && right <= r)
    {
        if (arr[left] < arr[right])
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

    while (left <= m)
    {
        ans.push_back(arr[left]);
        left++;
    }

    while (right <= r)
    {
        ans.push_back(arr[right]);
        right++;
    }

    for (int i = l; i <= r; i++)
    {

        arr[i] = ans[i-l];
    }
}

void mergeSort(int arr[], int l, int r)
{
    // code here

    if (l == r)
        return;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 4, 5, 3, 2, 1};
    mergeSort(arr, 0, 9);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}