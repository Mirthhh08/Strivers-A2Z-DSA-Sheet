#include <bits/stdc++.h>
using namespace std;
// brute force approach
// T.C :-O(N^2)
// S.C .:-O(1)

int maximumuProductSubarray_brute(int arr[], int n)
{
    int product = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            ans *= arr[j];

            product = max(product, ans);
        }
    }
    return product;
}
// optimal appraoch
// T.C :-O(N)
// S.C .:-O(1)
int maximumuProductSubarray_optimal(int arr[], int n)
{
    long long prefix = 1, suffix = 1;
    long long product = LONG_LONG_MIN;
    long long idx = n - 1;
    for (long long i = 0; i < n; i++)
    {

        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;

        prefix *= arr[i];
        suffix *= arr[idx--];

        product = max(product, max(prefix, suffix));
    }

    return product;
}

int main()
{
    int n = 5;
    int arr[] = {6, -3, -10, 0, 2};
    // cout << maximumuProductSubarray_brute(arr, n);

    cout << maximumuProductSubarray_optimal(arr, n);
    return 0;
}