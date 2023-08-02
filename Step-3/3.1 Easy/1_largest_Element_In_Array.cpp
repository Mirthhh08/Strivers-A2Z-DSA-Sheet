#include <bits/stdc++.h>
using namespace std;

//  T.C. : O(N)
//  S.C. : O(1)
int largestElement(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {

        arr[i] = max(arr[i - 1], arr[i]);
    }

    return arr[n - 1];
}


int main()
{
    int arr[5] = {10, 90, 121, 321, 1};
    cout << largestElement(arr, 5);
    return 0;
}