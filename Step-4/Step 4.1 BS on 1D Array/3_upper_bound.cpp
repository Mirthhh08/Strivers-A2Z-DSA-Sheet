#include <bits/stdc++.h>
using namespace std;
// brute force approach
// T.C. :- O(N)
// S.C. :- O(1)
int upper_bound_brute(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            return i;
        }
    }
}
// optimal approach
// T.C. :- O(logN)
// S.C. :- O(1)
int uppper_bound_optimal(int arr[] , int n , int x)
{
    int low = 0 , high = n - 1;
    int ans = -1;
    while(low <=  high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }

    }

    return ans;
}
int main()
{
    int n = 6;
    int arr[n] = {3, 5, 8, 9, 15, 19};
    int x = 9;

    // cout << upper_bound_brute(arr, n, x);
    
    cout << uppper_bound_optimal(arr, n, x);
    return 0;
}