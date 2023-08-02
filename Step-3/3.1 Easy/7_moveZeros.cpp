#include <bits/stdc++.h>
using namespace std;
// bruteforce approach
// T.C. : O(N + N)
// S.C. : O(N)
void moveZeros(int arr[], int n)
{

    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            temp.push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (i <= temp.size() - 1)
        {
            arr[i] = temp[i];
        }
        else
            arr[i] = 0;
    }
}

// optimal approach
// T.C. : O(N)
// S.C. : O(1)

void moveZeros_optimal(int arr[], int n)
{
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // moveZeros(arr, n);
    moveZeros_optimal(arr, n);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}