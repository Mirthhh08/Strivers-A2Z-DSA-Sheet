#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }

        while (arr[j] > pivot && j > low)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);

    return j;
}


void qS(int arr[], int low, int high)
{
    if (low < high)
    {
        int pidx = partition(arr, low, high);

        qS(arr, low, pidx - 1);
        qS(arr, pidx + 1, high);
    }
}

int main()
{
    int arr[10] = {12, 13, 1, 41, 1, 4, 7, 8, 9, 2};
    qS(arr, 0, 9);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}