/* Maximum SUm SUbarray */

#include <bits/stdc++.h>
using namespace std;

// bruteforce approach
// T.C :- O(N^2)
// S.C :- O(1)
int maximumSubarraySum(int arr[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// optimal approach
// using Kadane's Algorithm
// T.C :- O(N)
// S.C :- O(1)

int kadanesAlgorithm(int arr[], int n)
{

    int sum = 0, maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        maxi = max(sum, maxi);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

int main()
{
    int n = 10;
    int arr[n] = {1, 5, -7, 6, -1, 7, 7, -9, 6, 10};
    // cout << maximumSubarraySum(arr, n);

    cout << kadanesAlgorithm(arr, n);
    return 0;
}