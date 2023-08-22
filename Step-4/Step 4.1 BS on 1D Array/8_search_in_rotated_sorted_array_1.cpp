#include <bits/stdc++.h>
using namespace std;

// optimal approach
// T.C. :- O(log(N))
// S.C. :- O(1)
int search_rotated_array(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        // left part is sorted
        else if (arr[low] <= arr[mid])
        {
            if (arr[low] <= key && key <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right part is sorted
        else
        {
            if (arr[mid] <= key && key <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}
int main()
{
    int n = 7;
    int arr[] = {4, 5, 6, 0, 1, 2, 3};
    int key = 0;

    cout << search_rotated_array(arr, n, key);
    return 0;
}