#include <bits/stdc++.h>
using namespace std;

void rotateArrayBy1(int arr[], int n)
{
    int temp[n];

    for (int i = 1; i < n; i++)
    {
        temp[i - 1] = arr[i];
    }

    temp[n - 1] = arr[0];
}
// brute force approach
// T.C.: O(N)
// S.C: O(N)
int leftRotateArray(int arr[], int n, int k)
{
    int temp[n];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }
    int j = 0;
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n - k)];
    }
}

// optimal approach
// T.C.: O(N)
// S.C: O(1)
void reverse(int *arr, int start, int end)
{

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void leftRotateArray_optimal(int arr[], int n, int d)
{
    if (d == 0)
        return;
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
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
    int k;
    cin >> k;

    // leftRotateArray(arr, n, k);
    leftRotateArray_optimal(arr, n, k);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}
