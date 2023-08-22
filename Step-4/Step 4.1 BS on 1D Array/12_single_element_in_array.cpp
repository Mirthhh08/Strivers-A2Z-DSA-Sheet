#include <bits/stdc++.h>
using namespace std;
int findSingle(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    if (arr[0] != arr[1])
        return arr[0];

    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        if ((mid % 2 == 1 && arr[mid - 1] == arr[mid]) || (mid % 2 == 0 && arr[mid + 1] == arr[mid]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}
int main()
{
    int n = 8;
    int arr[] = {4, 4, 5, 5, 6, 7, 7};
    cout << findSingle(arr, n);
    return 0;
}