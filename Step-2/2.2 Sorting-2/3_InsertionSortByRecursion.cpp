#include <bits/stdc++.h>
using namespace std;

void insertionSortByRecursion(int arr[], int n, int i)
{
    if (i >= n)
    {
        return;
    }

    int j = i;

    while (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }

    insertionSortByRecursion(arr, n, i + 1);
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertionSortByRecursion(arr, 10, 0);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}