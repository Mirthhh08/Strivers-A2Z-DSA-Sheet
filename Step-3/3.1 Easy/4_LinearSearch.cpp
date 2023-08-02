#include <bits/stdc++.h>
using namespace std;

// T.C. : O(N)
int linearSearch(int arr[] , int n , int k)
{
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == k)
        {
            return 1;
        }
    }

    return -1;
}
int main()
{
    int arr[10] = {10, 2, 3, 5, 7, 1, 9, 4, 1, 3};
    cout<<linearSearch(arr, 10 , 4);
    return 0;
}