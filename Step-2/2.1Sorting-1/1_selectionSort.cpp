#include <bits/stdc++.h>
using namespace std;
int selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionSort(arr, 10);

    for (int it = 0; it < 10; it++)
    {
        cout << arr[it] << " ";
    }

    return 0;
}
