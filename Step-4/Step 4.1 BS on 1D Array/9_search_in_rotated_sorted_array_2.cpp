#include <bits/stdc++.h>
using namespace std;

// optimal approach
// T.C. :- O(log(N))
// S.C. :- O(1)
bool search_rotated_array(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return true;

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }
        // left part is sorted
        if (arr[low] <= arr[mid])
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

    return false;
}
int main()
{
    int n = 7;
    int arr[] = {4, 5, 6, 6, 6, 2, 3};
    int key = 6;

    cout << search_rotated_array(arr, n, key);
    return 0;
}