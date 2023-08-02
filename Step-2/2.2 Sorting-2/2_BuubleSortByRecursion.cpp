#include <bits/stdc++.h>
using namespace std;
void bubbleSortUsingRecursion(int arr[], int n)
{

    if (n <= 0)
    {
        return;
    }

    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }

    bubbleSortUsingRecursion(arr, n - 1);
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    bubbleSortUsingRecursion(arr, 10);

    for(auto it: arr)
    {
        cout<<it<<" ";
    }
    return 0;
}