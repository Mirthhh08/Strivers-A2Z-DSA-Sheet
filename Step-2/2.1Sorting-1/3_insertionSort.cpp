#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
            cout<<"runs\n";
        }
    }
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    insertionSort(arr, 5);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}