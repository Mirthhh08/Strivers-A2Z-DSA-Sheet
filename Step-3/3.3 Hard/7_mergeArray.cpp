#include <bits/stdc++.h>
using namespace std;
// brute force appraoch
// T.C. :- O(N + M)
// s.c :- O(N+ M);
void mergeArray_brute(int arr1[], int arr2[], int n, int m)
{
    int ans[m + n];
    int i, j = 0;
    int idx = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            ans[idx] = arr1[i];
            idx++, i++;
        }
        else
        {

            ans[idx] = arr2[j];
            idx++, j++;
        }
    }

    while (i < n)
    {
        ans[idx++] = arr1[i++];
    }

    while (j < m)
    {
        ans[idx++] = arr2[j++];
    }

    for (int i = 0; i < idx; i++)
    {
        arr1[i] = ans[i];
    }
}

// optimal sol
// T.C. :- O(min(N + M)) + O(N * log (N)) O(M * log (M))
// s.c :- O(1);

void mergeArray_better(int arr1[], int arr2[], int n, int m)
{
    int i = n - 1;
    int j = 0;

    while (arr1[i] > arr2[j])
    {
        swap(arr1[i], arr2[j]);
        i--;
        j++;
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    int idx = 0;
    for (int k = n; k < m + n; k++)
    {
        arr1[k] = arr2[idx++];
    }

    for (int i = 0; i < n+m; i++)
    {
        cout << arr1[i] << " ";
    }
}
int main()
{
    int n = 4;
    int arr1[] = {1, 3, 5, 7};

    int m = 5;
    int arr2[] = {0, 2, 6, 8, 9};

    // mergeArray_brute(arr1, arr2, n, m);
    mergeArray_better(arr1, arr2, n, m);

    return 0;
}