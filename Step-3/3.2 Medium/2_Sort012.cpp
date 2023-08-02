#include <bits/stdc++.h>
using namespace std;
// brute force approach
// use any sorting algo (best will me be : merge sort)
// T.C. : O(NlogN)
// S.C. : O(N)

/* --------------------------------------------------------*/

// Better solution
// T.C. :O(N + N)
// S.C. : O(1)
void sort012(int arr[], int n)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;
        else if (arr[i] == 1)
            one++;
        else
            two++;
    }
    int idx = 0;
    while (zero--)
    {
        arr[idx++] = 0;
    }

    while (one--)
    {
        arr[idx++] = 1;
    }

    while (two--)
    {
        arr[idx++] = 2;
    }
}

// DNF :-  Dutch National Flag Algorithm

void sort012_DNF(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if (arr[mid] == 1)
        {
            mid++;
        }

        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 10;
    int arr[n] = {2, 0, 2, 0, 1, 0, 1, 0, 0, 2};

    // sort012(arr, n);
    sort012_DNF(arr, n);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}