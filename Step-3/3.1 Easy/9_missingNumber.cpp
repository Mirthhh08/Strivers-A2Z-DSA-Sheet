#include <bits/stdc++.h>
using namespace std;
int missingNumber(int A[], int N)
{
    // Your code goes here
    int sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum += A[i];
    }

    N = (N * (N + 1)) / 2;

    return N - sum;
}
int main()
{
    int arr[4] = {1, 4, 5, 2};
    cout << missingNumber(arr, 5);
    return 0;
}