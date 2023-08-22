#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T.C. :- O(N^2)
// S.C. :- O(1)
int inversionCount(int arr[], int n)
{

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }

    return cnt;
}
// optimal approach
// using merge sort
// T.C. :- O(N log N)
// S.C. :- O(N) auxilary space
int merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}
int mergeSort(int arr[], int left, int right)
{
    int cnt = 0;
    if (left >= right)
    {
        return cnt;
    }

    int mid = (left + right) / 2;

    cnt += mergeSort(arr, left, mid);
    cnt += mergeSort(arr, mid + 1, right);
    cnt += merge(arr, left, mid, right);

    return cnt;
}
int inversionCount_optimal(int arr[], int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{

    int n = 42;
    int arr[] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};

    // cout << inversionCount(arr, n);

    cout << inversionCount_optimal(arr, n);
    return 0;
}